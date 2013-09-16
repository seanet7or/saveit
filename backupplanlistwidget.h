#ifndef BACKUPPLANLISTWIDGET_H
#define BACKUPPLANLISTWIDGET_H
#include <QObject>
#include "widgetscrollarea.h"
#include "backupplanlist.h"
#include "pushbutton.h"

class BackupPlanListWidget : public WidgetScrollArea
{
    Q_OBJECT
public:
    explicit BackupPlanListWidget(QWidget *parent, BackupPlanList &list);

signals:

public slots:

private slots:
    void newBackupWizard();

private:
    BackupPlanList &m_list;
    PushButton *m_addListItemButton;

};

#endif // BACKUPPLANLISTWIDGET_H
