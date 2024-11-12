#include "VTKWidget.h"
#include "mainwindow.h"

#ifdef USE_VTK

VTKWidget::VTKWidget(QWidget* parent)
: QVTKOpenGLNativeWidget(parent)
{

}
void VTKWidget::setMainWindowPointer(MainWindow* pMainWindow)
{
    m_pMainWindow = pMainWindow;
}

void VTKWidget::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu contextMenu(this);
    QAction* setColorAction = contextMenu.addAction("颜色");
    // QAction* setOpacityAction = contextMenu.addAction("透明度");
    connect(setColorAction, &QAction::triggered, this, &VTKWidget::setColor);
    // connect(setOpacityAction, &QAction::triggered, this, &VTKWidget::setOpacity);
    // if(m_pMainWindow->m_pickedActor)
    // {
    //     contextMenu.exec(event->globalPos());
    //     m_pMainWindow->m_renderWindow->GetInteractor()->RightButtonReleaseEvent();
    // }
}

void VTKWidget::setColor()
{
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        // 将Qt颜色转换为VTK颜色
        double vtkColor[3] = {color.redF(), color.greenF(), color.blueF()};
        // // 设置渲染器的背景颜色
        // m_pMainWindow->m_style_pick->LastPickedProperty->SetColor(vtkColor);
        // // m_pMainWindow->m_style_pick->HighLightProp->SetColor(vtkColor);
        // m_pMainWindow->m_style_pick->LastPickedActor->GetProperty()->SetColor(vtkColor);
        // // 重新渲染
        // m_pMainWindow->m_renderWindow->Render();
    }
}
 
void VTKWidget::setOpacity()
{
    // 在这里添加设置Actor透明度的代码
    qDebug() << "Setting opacity...";
}

#endif