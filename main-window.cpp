#include "main-window.h"

//slots
void MainWindow::AddIp() {
    ConfiguredIp = AddIpLineEdit->text();
    AddIpLineEdit->clear();
    AddIpLineEdit->setPlaceholderText("IP Added");
    AddIpLineEdit->setReadOnly(true);
    qDebug() << "Entered Text: " << ConfiguredIp;
}

void MainWindow::AutomaticModeChosen()
{
    if (ConfiguredIp.size() > 0) {
        AutomaticMode = new AutomaticModeWindow(ConfiguredIp);
        AutomaticMode->show();
    }
    else
    {
        AddIpLineEdit->clear();
        AddIpLineEdit->setPlaceholderText("Add IP before choosing mode!");
    }
}

void MainWindow::ManualModeChosen()
{
    if (ConfiguredIp.size() > 0) {
        ManualMode = new ManualModeWindow(ConfiguredIp);
        ManualMode->show();
    }
    else
    {
        AddIpLineEdit->clear();
        AddIpLineEdit->setPlaceholderText("Add IP before choosing mode!");
    }
}

void MainWindow::ConnectMainWindowSignals() {
    connect(AddIpButton, &QPushButton::clicked, this, &MainWindow::AddIp);
    connect(AutomaticModeButton, &QPushButton::clicked, this, &MainWindow::AutomaticModeChosen);
    connect(ManualModeButton, &QPushButton::clicked, this, &MainWindow::ManualModeChosen);
}

MainWindow::MainWindow() {
    CreateMainWindowLayout();
}

void MainWindow::CreateIpLayout() {
    IpSetLayout = new QVBoxLayout();
    IpSetLayout->setSpacing(3);

    IpLabel = new QLabel("Enter IP of Raspberry:", this);
    IpLabel->setAlignment(Qt::AlignHCenter);
    IpSetLayout->setAlignment(Qt::AlignHCenter);
    IpSetLayout->addWidget(IpLabel);

    // Add layout for the text box
    AddIpLineEditLayout = new QHBoxLayout();
    AddIpLineEditLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    AddIpLineEdit = new QLineEdit(this);
    AddIpLineEdit->setFixedSize(300, 20);

    AddIpLineEditLayout->addWidget(AddIpLineEdit);
    AddIpLineEditLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    IpSetLayout->addLayout(AddIpLineEditLayout);

    // Create button for setting ip layout
    IpSetButtonLayout = new QHBoxLayout();
    IpSetButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    AddIpButton = new QPushButton("Configure IP", this);
    AddIpButton->setFixedSize(100, 50);

    IpSetButtonLayout->addWidget(AddIpButton);
    IpSetButtonLayout->addItem(new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum));

    IpSetLayout->addLayout(IpSetButtonLayout);
    MainWindowLayout->addLayout(IpSetLayout);
}

void MainWindow::CreateModesLayout() {

    ModesLabel = new QLabel("Choose Rpi Load Transport mode:", this);
    ModesLabel->setAlignment(Qt::AlignHCenter);
    MainWindowLayout->addWidget(ModesLabel);

    MainWindowLayout->addItem(new QSpacerItem(5, 10, QSizePolicy::Minimum, QSizePolicy::Fixed));

    ModesButtonsLayout = new QHBoxLayout();
    ManualModeButton = new QPushButton("Manual Mode", this);
    AutomaticModeButton = new QPushButton("Automatic mode", this);
    ModesButtonsLayout->addWidget(ManualModeButton);
    ModesButtonsLayout->addWidget(AutomaticModeButton);

    MainWindowLayout->addLayout(ModesButtonsLayout);
}

void MainWindow::CreateMainWindowLayout() {
    setWindowTitle("RLT Control");

    setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    MainWindowLayout = new QVBoxLayout(this);
    MainWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    AddRLTLogo(MainWindowLayout, this);

    MainWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    CreateIpLayout();

    MainWindowLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    CreateModesLayout();

    CenterWindow(this);

    ConnectMainWindowSignals();

    setLayout(MainWindowLayout);
}