#ifndef BACKUPPLANLIST_H
#define BACKUPPLANLIST_H

#include <QObject>
#include "backupplan.h"

class BackupPlanList : public QObject
{
    Q_OBJECT
public:
    explicit BackupPlanList(QObject *parent = 0);
    int size() { return m_list.size(); }
signals:

public slots:
private:
    QList<BackupPlan> m_list;

};

#endif // BACKUPPLANLIST_H
