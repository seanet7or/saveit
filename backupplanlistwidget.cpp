#include "backupplanlistwidget.h"
#include <QFont>
#include <QtSvg/QSvgRenderer>
#include "backupplan.h"
#include "widgetsettings.h"


BackupPlanListWidget::BackupPlanListWidget(QWidget *parent, const BackupPlanList &list) :
    WidgetScrollArea(tr("Planned Backups"),
                     tr("Here you can manage your planned backups.\nClick the button to create a new one."),
                     parent),
    m_list(list)
{
    m_addListItemButton = new PushButton(this, this);
    m_addListItemButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    m_addListItemButton->setSVG(":/backup-add");

    m_addListItemButton->setText(tr("Add new backup"));
    connect(m_addListItemButton,
            SIGNAL(clicked()),
            this,
            SLOT(newBackupWizard()));
    addButton(m_addListItemButton);
}


void BackupPlanListWidget::newBackupWizard()
{
    BackupPlan::fromWizard();
}
