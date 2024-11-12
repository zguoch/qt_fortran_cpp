#ifndef H_CUSTOMVTKWIDGET
#define H_CUSTOMVTKWIDGET

#include <QMainWindow>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QtWidgets>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
// #include <QWebChannel>
// #include "webobjectinstance.h"
#include <thread>
// #include <omp.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkActor.h>
#include <qmenu.h>

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

#endif