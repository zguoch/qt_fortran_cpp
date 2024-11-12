#include "mainwindow.h"

#include <QApplication>

#include <poppler-qt6.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 打开PDF文件
    QString pdfFilePath = "path/to/your/file.pdf";
    auto document = Poppler::Document::load(pdfFilePath);
    if (!document || document->isLocked()) {
        qWarning("无法加载或解锁PDF文件");
        return -1;
    }

    // 渲染第一页（从0开始计数）
    int pageNumber = 0;
    auto page = document->page(pageNumber);
    if (!page) {
        qWarning("无法加载页面");
        // delete document;
        return -1;
    }

    // 设置渲染的分辨率（数值越大，图像越清晰）
    double resolution = 72.0;  // 每英寸的像素数
    QImage image = page->renderToImage(resolution, resolution);
    
    // 在QLabel中显示渲染的图像
    QLabel label;
    label.setPixmap(QPixmap::fromImage(image));
    label.show();

    // 释放资源
    // delete page;
    // delete document;

    // MainWindow w;
    // w.show();
    return a.exec();
}
