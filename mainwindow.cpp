#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMenu>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog);
    setWindowTitle(tr("SaveIt!"));
    setWindowIcon(QIcon(":/application-icon"));
    //setAttribute(Qt::WA_DeleteOnClose);

    m_sysTrayIcon = new QSystemTrayIcon(QIcon(":/application-icon"), this);
    m_sysTrayContextMenu = new QMenu(this);
    m_sysTrayContextMenu->addAction(tr("Exit"), this, SLOT(OnExitClicked()));
    m_sysTrayIcon->setContextMenu(m_sysTrayContextMenu);
    m_sysTrayIcon->show();
    connect(m_sysTrayIcon,
            SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,
            SLOT(OnSysTrayClicked(QSystemTrayIcon::ActivationReason)));
    m_backupPlanListWidget = new BackupPlanListWidget(this, m_backupPlanList);
    //ui->centralWidget->setLayout(new QHBoxLayout);
    ui->centralWidget->layout()->addWidget(m_backupPlanListWidget);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


MainWindow::~MainWindow()
{
    delete ui;
    m_sysTrayIcon->disconnect();
    m_sysTrayIcon->blockSignals(true);
    delete m_sysTrayIcon;
}


void MainWindow::OnExitClicked()
{
    //qDebug() << "MainWindow::OnExitClicked()";
    //this->close();
    exit(0);
}


void MainWindow::closeEvent(QCloseEvent *e)
{
    //m_sysTrayIcon->hide();
    hide();
    e->ignore();
    //QMainWindow::closeEvent(e);
}


void MainWindow::OnSysTrayClicked(QSystemTrayIcon::ActivationReason reason)
{
    if ((reason == QSystemTrayIcon::DoubleClick)
            || (reason == QSystemTrayIcon::Trigger)
            || (reason == QSystemTrayIcon::Unknown))
    {
        if (isVisible())
            hide();
        else
            show();
    }
}
