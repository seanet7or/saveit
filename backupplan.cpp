#include "backupplan.h"
#include "backupplaneditsourcesfilters.h"


BackupPlan::BackupPlan(QObject *parent) :
    QObject(parent)
{
}


BackupPlan *BackupPlan::fromWizard()
{
    BackupPlan *newPlan = new BackupPlan();
    BackupPlanEditSourcesFilters dlg;
    dlg.show();
    dlg.exec();
    return newPlan;
}
