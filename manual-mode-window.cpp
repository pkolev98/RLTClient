#include "manual-mode-window.h"

void ManualModeWindow::EstablishConnectionPressed() {
    if ( ConnectionEstablished ) {
        Logs->clear();
        Logs->append("Connection already established!");
        return;
    }

    RLTClient.EstablishConnection(ConfiguredIp.toStdString());
    ConnectionEstablished = true;
    RLTClient.SetMode(true);
    Logs->clear();
    Logs->append("Establishing connection...");
    Logs->append("Connection established!");
}

void ManualModeWindow::StartButtonPressed() {
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

void ManualModeWindow::StopButtonPressed() {
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

void ManualModeWindow::ForwardButtonPressed() {
    if (ConnectionEstablished) {
        Logs->append("RLT move forward requested");
        RLTClient.MoveForward();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void ManualModeWindow::RightButtonPressed() {
    if ( ConnectionEstablished ) {
        Logs->append("RLT turn right requested");
        RLTClient.MoveRight();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void ManualModeWindow::LeftButtonPressed() {
    if ( ConnectionEstablished ) {
        Logs->append("RLT turn left requested");
        RLTClient.MoveLeft();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void ManualModeWindow::ButtonReleased() {
    if ( ConnectionEstablished ) {
        Logs->append("RLT stop moving, button released");
        RLTClient.MoveStop();
    }
    else
    {
        Logs->clear();
        Logs->append("Establish connection first!");
    }
}

void ManualModeWindow::ConnectManualModeSignals() {
    connect(ForwardButton, &QPushButton::pressed, this, &ManualModeWindow::ForwardButtonPressed);
    connect(ForwardButton, &QPushButton::released, this, &ManualModeWindow::ButtonReleased);
    connect(LeftButton, &QPushButton::pressed, this, &ManualModeWindow::LeftButtonPressed);
    connect(LeftButton, &QPushButton::released, this, &ManualModeWindow::ButtonReleased);
    connect(RightButton, &QPushButton::pressed, this, &ManualModeWindow::RightButtonPressed);
    connect(RightButton, &QPushButton::released, this, &ManualModeWindow::ButtonReleased);
    connect(EstablishConnectionButton, &QPushButton::clicked, this, &ManualModeWindow::EstablishConnectionPressed);
    connect(StartButton, &QPushButton::clicked, this, &ManualModeWindow::StartButtonPressed);
    connect(StopButton, &QPushButton::clicked, this, &ManualModeWindow::StopButtonPressed);
}

ManualModeWindow::ManualModeWindow(QString ConfiguredIP) {
    CreateManualModeWindow();
    //CenterWindow();
    ConfiguredIp = ConfiguredIP;
    ConnectManualModeSignals();
    setLayout(ManualModeWindowLayout);
}

void ManualModeWindow::CreateManualModeWindow() {
    setWindowTitle("RLT Manual mode ");

    setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    ManualModeWindowLayout = new QVBoxLayout(this);
    ManualModeWindowLayout->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    AddRLTLogo(ManualModeWindowLayout, this);

    ManualModeWindowLayout->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    CreateEstablishConnectionLayout();

    ManualModeWindowLayout->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    ControlsLabel = new QLabel("Controls for RLT platform:", this);
    ControlsLabel->setAlignment(Qt::AlignHCenter);
    ManualModeWindowLayout->addWidget(ControlsLabel);

    ManualModeWindowLayout->addItem(new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Fixed));

    ControlButtonsLayout = new QHBoxLayout();
    StartButton = new QPushButton("Start RLT", this);
    StartButton->setFixedSize(100, 50);
    StopButton = new QPushButton("Stop RLT", this);
    StopButton->setFixedSize(100, 50);
    ControlButtonsLayout->addWidget(StartButton);
    ControlButtonsLayout->addWidget(StopButton);

    ManualModeWindowLayout->addLayout(ControlButtonsLayout);

    ManualModeWindowLayout->addItem(new QSpacerItem(10, 15, QSizePolicy::Minimum, QSizePolicy::Expanding));

    MoveButtonsLayout = new QHBoxLayout();

    QIcon LeftIcon("../resources/manual-mode/left.png");
    LeftButton = new QPushButton(this);
    LeftButton->setIcon(LeftIcon);
    LeftButton->setIconSize(QSize(80, 80));
    LeftButton->setFixedSize(100, 100);

    QIcon ForwardIcon("../resources/manual-mode/forward.png");
    ForwardButton = new QPushButton(this);
    ForwardButton->setIcon(ForwardIcon);
    ForwardButton->setIconSize(QSize(80, 80));
    ForwardButton->setFixedSize(100, 100);

    QIcon RightIcon("../resources/manual-mode/right.png");
    RightButton = new QPushButton(this);
    RightButton->setIcon(RightIcon);
    RightButton->setIconSize(QSize(80, 80));
    RightButton->setFixedSize(100, 100);

    MoveButtonsLayout->addWidget(LeftButton);
    MoveButtonsLayout->addWidget(ForwardButton);
    MoveButtonsLayout->addWidget(RightButton);

    ManualModeWindowLayout->addLayout(MoveButtonsLayout);
}

void ManualModeWindow::CreateEstablishConnectionLayout() {
    LogsLayout = new QHBoxLayout(this);
    LogsLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    Logs = new QTextEdit(this);
    Logs->setFixedSize(300, 200);
    Logs->setReadOnly(true);
    Logs->setPlaceholderText("Waiting for establishing connection...");
    LogsLayout->addWidget(Logs);

    LogsLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    ManualModeWindowLayout->addLayout(LogsLayout);

    ButtonLayout = new QHBoxLayout(this);
    ButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    EstablishConnectionButton = new QPushButton("Establish connection", this);
    EstablishConnectionButton->setFixedSize(200, 50);
    ButtonLayout->addWidget(EstablishConnectionButton);

    ButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    ManualModeWindowLayout->addLayout(ButtonLayout);
}