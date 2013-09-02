#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QList>
#include "backupplan.h"
#include "backupplanlistwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *e);

private slots:
    void OnExitClicked();
    void OnSysTrayClicked(QSystemTrayIcon::ActivationReason reason);
    
private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *m_sysTrayIcon;
    QMenu *m_sysTrayContextMenu;
    BackupPlanList m_backupPlanList;
    BackupPlanListWidget *m_backupPlanListWidget;
};

#endif // MAINWINDOW_H
