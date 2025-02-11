#pragma once

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDesktopWidget>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define LOGO_PATH "../resources/rlt-logo.png"

class AllWindowsCommons {
public:
    AllWindowsCommons() = default;

    ~AllWindowsCommons() = default;

protected:
    void CenterWindow(QWidget *Window);

    void AddRLTLogo(QVBoxLayout *MainWindowLayout, QWidget *Window);
};