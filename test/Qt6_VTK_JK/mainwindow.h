#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkContextView.h>
#include <vtkRenderer.h>
#include <vtkChartXY.h>
#include <vtkFloatArray.h>
#include <vtkTable.h>
#include <vtkPlot.h>

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
    vtkSmartPointer<vtkContextView> m_vtkChartView;
};
#endif // MAINWINDOW_H
