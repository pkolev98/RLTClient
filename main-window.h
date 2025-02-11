#pragma once

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDesktopWidget>

#include "all-windows-commons.h"
#include "automatic-mode-window.h"
#include "manual-mode-window.h"

class MainWindow : public QWidget, public AllWindowsCommons {
public:
    MainWindow();

    ~MainWindow() {
        if (AutomaticMode) {
            delete AutomaticMode;
        }
    }

public slots:
    void AddIp();

    void AutomaticModeChosen();

    void ManualModeChosen();

private:
    // Main menu layout
    void CreateIpLayout();

    void CreateModesLayout();

    void CreateMainWindowLayout();

    void ConnectMainWindowSignals();

    // Main Window Menu Layout
    QVBoxLayout* MainWindowLayout;

    QVBoxLayout *IpSetLayout;
    QLabel* IpLabel;
    QHBoxLayout *AddIpLineEditLayout;
    QLineEdit* AddIpLineEdit; 
    QHBoxLayout *IpSetButtonLayout;
    QPushButton* AddIpButton;

    QLabel* ModesLabel;
    QHBoxLayout* ModesButtonsLayout;
    QPushButton* AutomaticModeButton;
    QPushButton* ManualModeButton;

    QString ConfiguredIp;

    AutomaticModeWindow* AutomaticMode;
    ManualModeWindow* ManualMode;
};