#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <pybind11/embed.h>
namespace py = pybind11;

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void func_py();
private:
    Ui::MainWindow *ui;
};

// class MatplotlibWidget : public QWidget {
// public:
//     MatplotlibWidget(QWidget *parent = nullptr) : QWidget(parent), imageLabel(new QLabel(this)) {
//         QVBoxLayout *layout = new QVBoxLayout(this);
//         layout->addWidget(imageLabel);
//         setLayout(layout);
//     }

//     void plot() {
//         // 调用 Python 绘图代码
//         py::scoped_interpreter guard{}; // 初始化 Python 解释器
//         py::exec(R"(
//             import matplotlib.pyplot as plt
//             import numpy as np

//             x = np.linspace(0, 10, 100)
//             y = np.sin(x)

//             plt.figure()
//             plt.plot(x, y)
//             plt.savefig("plot.png")
//         )");

//         // 加载并显示生成的图像
//         QPixmap pixmap("plot.png");
//         imageLabel->setPixmap(pixmap);
//     }

// private:
//     QLabel *imageLabel;
// };

class MatplotlibWidget : public QWidget {
public:
    MatplotlibWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        py::object matplotlib_module = py::module_::import("matplotlib_embed");
        py::object create_canvas = matplotlib_module.attr("create_canvas");

        // 调用 Python 函数创建 MatplotlibCanvas
        py::object canvas = create_canvas();

        // 从 Python 转换为 Qt 对象
        QWidget *canvas_widget = canvas.cast<QWidget *>();

        layout->addWidget(canvas_widget);
        setLayout(layout);
    }
};
#endif // MAINWINDOW_H
