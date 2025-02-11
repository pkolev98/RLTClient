#include "all-windows-commons.h"

void AllWindowsCommons::AddRLTLogo(QVBoxLayout *MainWindowLayout, QWidget *Window) {
    QLabel* PngLabel = new QLabel(Window);
    QPixmap pixmap(LOGO_PATH);
    PngLabel->setPixmap(pixmap);
    PngLabel->setAlignment(Qt::AlignCenter);
    MainWindowLayout->addWidget(PngLabel);
}

void AllWindowsCommons::CenterWindow(QWidget *Window) {
    QDesktopWidget* desktop = QApplication::desktop();
    QRect screenGeometry = desktop->availableGeometry(desktop->primaryScreen());

    int x = (screenGeometry.width() - Window->width()) / 2;
    int y = (screenGeometry.height() - Window->height()) / 2;

    Window->move(x, y);
}