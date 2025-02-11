#pragma once

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDesktopWidget>

#include "all-windows-commons.h"
#include "grpc/grpc-client-wrapper.h"

class AutomaticModeWindow : public QWidget, public AllWindowsCommons {
public:
    AutomaticModeWindow(QString ConfiguredIP);

    ~AutomaticModeWindow() {}

public slots:
    void StartButtonPressed();

    void StopButtonPressed();

    void EstablishConnectionPressed();

private:
    void CreateAutomaticModeWindow();

    void CreateEstablishConnectionLayout();

    void ConnectAutomaticModeSignals();

    QVBoxLayout* AutomaticModeWindowLayout;

    QHBoxLayout* LogsLayout;
    QTextEdit *Logs;
    QHBoxLayout* ButtonLayout;
    QPushButton* EstablishConnectionButton;

    QLabel* ControlsLabel;
    QHBoxLayout *ControlButtonsLayout;
    QPushButton* StartButton;
    QPushButton* StopButton;

    QString ConfiguredIp;

    GrpcClientWrapper RLTClient;
    bool ConnectionEstablished{false};
};