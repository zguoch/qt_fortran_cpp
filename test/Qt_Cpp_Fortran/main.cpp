#include <QCoreApplication>
#include <QLibrary>
#include <iostream>

// extern "C" {
//     void say_hello_();
// }

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    // say_hello_();
    std::cout<<"hello qt fortran"<<std::endl;
    return a.exec();
}
