#ifndef H_CUSTOMVTKWIDGET
#define H_CUSTOMVTKWIDGET

#include <QMainWindow>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QtWidgets>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <thread>
#include <qmenu.h>

#ifdef USE_VTK
#include "QVTKRenderWidget.h"
#include <QVTKOpenGLNativeWidget.h>
#include <vtkActor.h>
#include <vtkContextView.h>
#include <vtkRenderer.h>
#include <vtkChartXY.h>
#include <vtkFloatArray.h>
#include <vtkTable.h>
#include <vtkPlot.h>

// 不完整申明MainWindow
class MainWindow;

class VTKWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:

public:
    VTKWidget(QWidget* parent = nullptr);
    void setMainWindowPointer(MainWindow* pMainWindow);
protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

private slots:
    void setColor();

    void setOpacity();

private:
    MainWindow* m_pMainWindow; //将主窗口的指针传过来用于操作相应的数据
};
#else
class VTKWidget : public QWidget
{
    Q_OBJECT
public:

public:
    VTKWidget(QWidget* parent = nullptr){};
};
#endif 

#endif