#ifndef BACKUPPLAN_H
#define BACKUPPLAN_H

#include <QObject>

class BackupPlan : public QObject
{
    Q_OBJECT
public:
    explicit BackupPlan(QObject *parent = 0);
    static BackupPlan *fromWizard();
signals:

public slots:

private:
    Q_DISABLE_COPY(BackupPlan)

};

#endif // BACKUPPLAN_H
