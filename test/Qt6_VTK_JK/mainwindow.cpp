#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ------2D chart---------
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

    // 渲染窗口
    // view->GetRenderWindow()->SetSize(800, 600);
    // view->GetRenderWindow()->Render();
}

MainWindow::~MainWindow()
{
    delete ui;
}

