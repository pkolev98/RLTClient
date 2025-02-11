#include "automatic-mode-window.h"

void AutomaticModeWindow::EstablishConnectionPressed() {
    if ( ConnectionEstablished ) {
        Logs->clear();
        Logs->append("Connection already established!");
        return;
    }

    RLTClient.EstablishConnection(ConfiguredIp.toStdString());
    ConnectionEstablished = true;
    RLTClient.SetMode(false);
    Logs->clear();
    Logs->append("Establishing connection...");
    Logs->append("Connection established!");
}

void AutomaticModeWindow::StartButtonPressed() {
    if (ConnectionEstablished) {
        Logs->append("RLT start requested");
        RLTClient.Start();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void AutomaticModeWindow::StopButtonPressed() {
    if ( ConnectionEstablished ) {
        Logs->append("RLT stop requested");
        RLTClient.Stop();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void AutomaticModeWindow::ConnectAutomaticModeSignals() {
    connect(StartButton, &QPushButton::clicked, this, &AutomaticModeWindow::StartButtonPressed);
    connect(StopButton, &QPushButton::clicked, this, &AutomaticModeWindow::StopButtonPressed);
    connect(EstablishConnectionButton, &QPushButton::clicked, this, &AutomaticModeWindow::EstablishConnectionPressed);
}

AutomaticModeWindow::AutomaticModeWindow(QString ConfiguredIP) {
    CreateAutomaticModeWindow();
    //CenterWindow();
    ConfiguredIp = ConfiguredIP;
    ConnectAutomaticModeSignals();
    setLayout(AutomaticModeWindowLayout);
}

void AutomaticModeWindow::CreateAutomaticModeWindow() {
    setWindowTitle("RLT Automatic mode ");

    setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    AutomaticModeWindowLayout = new QVBoxLayout(this);
    AutomaticModeWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    AddRLTLogo(AutomaticModeWindowLayout, this);

    AutomaticModeWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    CreateEstablishConnectionLayout();

    AutomaticModeWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    ControlsLabel = new QLabel("Controls for RLT platform:", this);
    ControlsLabel->setAlignment(Qt::AlignHCenter);
    AutomaticModeWindowLayout->addWidget(ControlsLabel);

    AutomaticModeWindowLayout->addItem(new QSpacerItem(10, 30, QSizePolicy::Minimum, QSizePolicy::Fixed));

    ControlButtonsLayout = new QHBoxLayout();
    StartButton = new QPushButton("Start RLT", this);
    StartButton->setFixedSize(100, 50);
    StopButton = new QPushButton("Stop RLT", this);
    StopButton->setFixedSize(100, 50);
    ControlButtonsLayout->addWidget(StartButton);
    ControlButtonsLayout->addWidget(StopButton);

    AutomaticModeWindowLayout->addLayout(ControlButtonsLayout);
}

void AutomaticModeWindow::CreateEstablishConnectionLayout() {
    LogsLayout = new QHBoxLayout(this);
    LogsLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    Logs = new QTextEdit(this);
    Logs->setFixedSize(300, 200);
    Logs->setReadOnly(true);
    Logs->setPlaceholderText("Waiting for establishing connection...");
    LogsLayout->addWidget(Logs);

    LogsLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    AutomaticModeWindowLayout->addLayout(LogsLayout);

    ButtonLayout = new QHBoxLayout(this);
    ButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    EstablishConnectionButton = new QPushButton("Establish connection", this);
    EstablishConnectionButton->setFixedSize(200, 50);
    ButtonLayout->addWidget(EstablishConnectionButton);

    ButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    AutomaticModeWindowLayout->addLayout(ButtonLayout);
}