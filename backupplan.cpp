#include "backupplan.h"
#include "editsourcesdlg.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include "basedlg.h"
#include "widgetsettings.h"
#include "pushbutton.h"


BackupPlan::BackupPlan(QObject *parent) :
    QObject(parent)
{
}


BackupPlan *BackupPlan::fromWizard()
{
    BackupPlan *newPlan = new BackupPlan();
    QString name;

    while (name.length() == 0)
    {
        BaseDlg nameDlg(NULL, tr("Name Your Backup Schedule"));
        nameDlg.setLayout(new QVBoxLayout());
        ((QVBoxLayout*)nameDlg.layout())->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::Expanding));
        nameDlg.layout()->addWidget(WidgetSettings::newHelpLabel(tr("Enter a name for your new backup schedule:")));
        QLineEdit *nameEdit = new QLineEdit();
        nameEdit->setText(tr("My Backup"));
        nameDlg.layout()->addWidget(nameEdit);
        PushButton *nextButton = new PushButton(NULL, NULL);
        nextButton->setText(tr("Continue"));
        nextButton->setSVG(":/continue");
        connect(nextButton, SIGNAL(clicked()), &nameDlg, SLOT(accept()));
        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
        buttonLayout->addWidget(nextButton);
        ((QVBoxLayout*)nameDlg.layout())->addLayout(buttonLayout);
        ((QVBoxLayout*)nameDlg.layout())->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::Expanding));
        nameDlg.show();
        if (nameDlg.exec() == QDialog::Rejected)
        {
            delete newPlan;
            return NULL;
        }
        else
        {
            name = nameEdit->text();
        }
    }

    EditSourcesDlg dlg;
    dlg.show();
    if (dlg.exec() == QDialog::Rejected)
    {
        delete newPlan;
        return NULL;
    }

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
