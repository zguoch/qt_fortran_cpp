#include "JKQTPlotterWidget.h"
#include "mainwindow.h"

#ifdef USE_JKQtPlotter

JKQTPlotterWidget::JKQTPlotterWidget(QWidget* parent)
: JKQTPlotter(parent)
{

}
void JKQTPlotterWidget::setMainWindowPointer(MainWindow* pMainWindow)
{
    m_pMainWindow = pMainWindow;
}

#endif