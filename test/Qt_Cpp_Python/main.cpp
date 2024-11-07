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
void func_py_module()
{
    try {
        // 初始化 Python 解释器
        py::scoped_interpreter guard{};

        // 将当前工作目录设置为 Python 脚本所在目录
        // 如果脚本不在当前目录，需要通过 sys.path 添加脚本所在的目录
        py::module sys = py::module::import("sys");
        sys.attr("path").attr("append")("/Users/zguo/MyData/AmateurCareer/Projects/CUG_DuJinsong/GeomagticModeler/test/Qt_Cpp_Python/build/install/python");  // 假设 test.py 在当前目录下
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
