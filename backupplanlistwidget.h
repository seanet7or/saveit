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
    explicit BackupPlanListWidget(QWidget *parent, const BackupPlanList &list);

signals:

public slots:

private:
    const BackupPlanList &m_list;
    PushButton *m_emptyListButton;

};

#endif // BACKUPPLANLISTWIDGET_H
