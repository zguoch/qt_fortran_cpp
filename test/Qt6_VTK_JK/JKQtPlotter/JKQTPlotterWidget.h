#ifndef H_JKQTPLOTTERWIDGET
#define H_JKQTPLOTTERWIDGET

#include <QMainWindow>
#include <QMouseEvent>
#include <QHoverEvent>
#include <QtWidgets>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <thread>
#include <qmenu.h>

#ifdef USE_JKQtPlotter
#include "jkqtplotter/jkqtplotter.h"
#include "jkqtplotter/graphs/jkqtpparsedfunction.h"

// 不完整申明MainWindow
class MainWindow;

class JKQTPlotterWidget : public JKQTPlotter
{
    Q_OBJECT
public:

public:
    JKQTPlotterWidget(QWidget* parent = nullptr);
    void setMainWindowPointer(MainWindow* pMainWindow);
private:
    MainWindow* m_pMainWindow; //将主窗口的指针传过来用于操作相应的数据
};
#else
class JKQTPlotterWidget : public QWidget
{
    Q_OBJECT
public:

public:
    JKQTPlotterWidget(QWidget* parent = nullptr){};
};
#endif 

#endif