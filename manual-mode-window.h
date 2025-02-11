#pragma once

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDesktopWidget>
#include <QIcon>

#include "all-windows-commons.h"
#include "grpc/grpc-client-wrapper.h"

class ManualModeWindow : public QWidget, public AllWindowsCommons {
public:
    ManualModeWindow(QString ConfiguredIP);

    ~ManualModeWindow() {}

public slots:
    void LeftButtonPressed();

    void ForwardButtonPressed();

    void RightButtonPressed();

    void ButtonReleased();

    void EstablishConnectionPressed();

    void StartButtonPressed();

    void StopButtonPressed();

private:
    void CreateManualModeWindow();

    void CreateEstablishConnectionLayout();

    void ConnectManualModeSignals();

    QVBoxLayout* ManualModeWindowLayout;

    QHBoxLayout* LogsLayout;
    QTextEdit *Logs;
    QHBoxLayout* ButtonLayout;
    QPushButton* EstablishConnectionButton;

    QLabel* ControlsLabel;

    QHBoxLayout *ControlButtonsLayout;
    QPushButton* StartButton;
    QPushButton* StopButton;

    QHBoxLayout *MoveButtonsLayout;
    QPushButton* ForwardButton;
    QPushButton* LeftButton;
    QPushButton* RightButton;

    QString ConfiguredIp;

    GrpcClientWrapper RLTClient;
    bool ConnectionEstablished{false};
};