#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VTKWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    #ifdef USE_VTK 
    vtkSmartPointer<vtkContextView> m_vtkChartView;
    #endif
public:
    void test_JKplotter();
    void test_VTKchart();
};
#endif // MAINWINDOW_H
