#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ------ JKQtPlotter ------
    test_JKplotter();
    // ------2D chart---------
    test_VTKchart();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::test_JKplotter()
{
    #ifdef USE_JKQtPlotter
    // JKQTPXParsedFunctionLineGraph* graph=new JKQTPXParsedFunctionLineGraph(ui->qJKplotter);
    // graph->setFunction("sin(x*4*pi)*exp(-x/5)");
    // graph->setTitle("test");
    // ui->qJKplotter->addGraph(graph);
    // ui->qJKplotter->setXY(-10,10,-10,10);

    // JKQTPlotter plot;
    JKQTPDatastore* ds=ui->qJKplotter->getDatastore();
 
    // 2. now we create data for a simple plot (a sine curve)
    std::vector<double> a,b;
    const int Ndata=100;
    for (int i=0; i<Ndata; i++) {
        const double x=double(i)/double(Ndata)*8.0*M_PI;
        a.push_back(x);
        b.push_back(sin(x));
    }
    
    size_t columnX=ds->addCopiedColumn(a, "x");
    size_t columnY=ds->addCopiedColumn(b, "y");
 
    // 4. create a graph in the plot, which plots the dataset X/Y:
    JKQTPXYLineGraph* graph1=new JKQTPXYLineGraph(ui->qJKplotter);
    graph1->setXColumn(columnX);
    graph1->setYColumn(columnY);
    graph1->setTitle(QObject::tr("sine graph"));
 
    // // 5. add the graph to the plot, so it is actually displayed
    ui->qJKplotter->addGraph(graph1);
 
    // 6. autoscale the plot so the graph is contained
    ui->qJKplotter->zoomToFit();
    // delete graph1;
    #endif
}

void MainWindow::test_VTKchart()
{
    #ifdef USE_VTK
    // Set up the view
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat()); //IMPORTANT: otherwise get error "vtkGenericOpenGLRenderWindow (0x137f9efd0): Unable to find a valid OpenGL 3.2 or later implementation. ...."
    m_vtkChartView=vtkSmartPointer<vtkContextView>::New();
    // 2. key for 2D charts
    m_vtkChartView->SetRenderWindow(this->ui->qvtkWidget->renderWindow()); //must be here
    m_vtkChartView->GetRenderer()->SetBackground(1.0, 0, 1.0);
    vtkSmartPointer<vtkChartXY> chart = vtkSmartPointer<vtkChartXY>::New();
    m_vtkChartView->GetScene()->AddItem(chart);

    // 创建并初始化数据表
    vtkSmartPointer<vtkTable> table = vtkSmartPointer<vtkTable>::New();
    // 创建 x 和 y 数据列
    vtkSmartPointer<vtkFloatArray> xArray = vtkSmartPointer<vtkFloatArray>::New();
    xArray->SetName("X Axis");
    table->AddColumn(xArray);
    vtkSmartPointer<vtkFloatArray> yArray = vtkSmartPointer<vtkFloatArray>::New();
    yArray->SetName("Y Axis");
    table->AddColumn(yArray);
    // 填充数据
    int numPoints = 100;
    table->SetNumberOfRows(numPoints);
    for (int i = 0; i < numPoints; ++i)
    {
        float x = i / 10.0;
        float y = sin(x);  // 示例：Y值是X值的正弦
        table->SetValue(i, 0, x);
        table->SetValue(i, 1, y);
    }

    // // 添加线条数据到图表
    vtkPlot* line = chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table, 0, 1);  // 设置数据源（X列和Y列）
    line->SetColor(0, 0, 1);       // 设置线条颜色为蓝色
    line->SetWidth(2.0);               // 设置线条宽度

    #endif
}
