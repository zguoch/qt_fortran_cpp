// python
// 必须在qt之前包含此头文件，否则会出现`object.h:206:23: error: expected member name or ';' after declaration specifiers PyType_Slot *slots; /* terminated by slot==0. */`错误，
// 解决方案见：https://github.com/pybind/pybind11/issues/2305
#include <pybind11/embed.h>
namespace py = pybind11;

#include <QCoreApplication>
#include <QLibrary>
#include <iostream>

// extern "C" {
//     void say_hello_();
// }

void func_py()
{
    py::scoped_interpreter guard{}; // 初始化 Python 解释器
        try {
            // 导入 Python 模块
            py::object math = py::module_::import("math");
            py::object mpl = py::module_::import("matplotlib");

            // 调用 sqrt 函数
            double result = math.attr("sqrt")(16.0).cast<double>();

            // 打印结果
            std::cout << "The square root of 16 is: " << result << std::endl;
        } catch (const py::error_already_set& e) {
            std::cerr << "Python error: " << e.what() << std::endl;
        }
}
void func_py_module()
{
    try {
        // 初始化 Python 解释器
        py::scoped_interpreter guard{};

        // 将当前工作目录设置为 Python 脚本所在目录
        // 如果脚本不在当前目录，需要通过 sys.path 添加脚本所在的目录
        py::module sys = py::module::import("sys");
        sys.attr("path").attr("append")("./");  // 假设 test.py 在当前目录下

        // 导入 Python 脚本文件 test.py
        py::object test = py::module_::import("test");

        // 调用 test.py 中的 add 函数
        int result = test.attr("add")(2, 3).cast<int>();
        std::cout << "Result of add(2, 3): " << result << std::endl;

        // 调用 test.py 中的 greet 函数
        std::string greeting = test.attr("greet")("Alice").cast<std::string>();
        std::cout << "Greeting: " << greeting << std::endl;

    } catch (const py::error_already_set& e) {
        std::cerr << "Python error: "<< std::endl;
        Py_Exit(1);
    }
}
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    // say_hello_();
    std::cout<<"hello qt "<<std::endl;

    // -------------- python ------------------
    func_py();
    // func_py_module();
    // ------------------------------------
    return a.exec();
    // return 0;
}
