#include "backupplan.h"


BackupPlan::BackupPlan(QObject *parent) :
    QObject(parent)
{
}


BackupPlan *BackupPlan::fromWizard()
{
    BackupPlan *newPlan = new BackupPlan();
    return newPlan;
}
