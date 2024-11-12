

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 可以采用这种方式：使用mpl提供的cpp接口绘图，然后将绘图结果pdf在qt中借助popplooer显示

    // MatplotlibWidget *matplotlibWidget = new MatplotlibWidget();
    // this->setCentralWidget(matplotlibWidget);
    // this->resize(800, 600);
    // // this->show();
    // // 调用绘图函数
    // matplotlibWidget->plot();

    // 初始化 Python 解释器
    // py::scoped_interpreter guard{};
    // MatplotlibWidget *matplotlibWidget = new MatplotlibWidget();
    // this->setCentralWidget(matplotlibWidget);
    // this->resize(800, 600);

    // func_py();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::func_py()
{
    py::scoped_interpreter guard{}; // 初始化 Python 解释器
        try {
            // 其他依赖库需要用静态编译的python进行安装:`./bin/python3 -m pip install matplotlib`，会安装在`./lib/python3.13/site-packages`目录下，最终只需要将`lib/python3.13`拷贝到可执行文件相同目录即可
            // // 设置 Python 标准库路径，假设最终可执行文件和 lib 文件夹在同一目录。实际上试了一下，只要lib/python3.13的文件夹（包含最小要求的文件）放在相同目录即可，如果不是在相同目录可以考虑如下方式修改
            // py::exec("import sys");
            // py::exec("sys.path.append('/Users/zguo/MyData/AmateurCareer/Projects/CUG_DuJinsong/GeomagticModeler/test/Qt_Cpp_Python/build/install/lib/python3.13')");  // 指向标准库路径
            // setenv("PYTHONPATH", "libs/python3.13", 1); //好像不起作用，直接放在可执行文件相同的lib目录下算了
            // 导入 Python 模块
            py::object math = py::module_::import("math");
            py::object mpl = py::module_::import("matplotlib");

            // 调用 sqrt 函数
            double result = math.attr("sqrt")(16.0).cast<double>();

            // 打印结果
            std::cout << "The square root of 16 is: " << result << std::endl;

            // ------------------ 执行一段python代码
            int x = 5;
            int y = 10;

            // 使用 locals 传递变量到 Python 中
            py::dict locals;
            locals["x"] = x;
            locals["y"] = y;
            py::exec(R"(
                result = x + y
                for i in range(0,4):
                    print(i)
                print(f"The result of x + y is: {result}")
            )", py::globals(), locals);
            int result2 = locals["result"].cast<int>();
            std::cout << "Result from Python: " << result2 << std::endl;

        } catch (const py::error_already_set& e) {
            std::cerr << "Python error: " << e.what() << std::endl;
        }
}

