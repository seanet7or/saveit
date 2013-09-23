#include "backupplan.h"
#include "backupplaneditsourcesfilters.h"
#include <QMessageBox>
#include <QFileDialog>


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

    QString target;
    bool cancel = false;
    while (target.isEmpty())
    {
        target = QFileDialog::getExistingDirectory(NULL,
                                                   tr("Select a destination directory"),
                                                   QDir::homePath());
        if (target.isEmpty())
        {

        }

    }
    return newPlan;
}
