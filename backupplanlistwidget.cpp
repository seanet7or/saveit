#include "backupplanlistwidget.h"
#include <QFont>
#include <QtSvg/QSvgRenderer>
#include "backupplan.h"
#include "widgetsettings.h"


BackupPlanListWidget::BackupPlanListWidget(QWidget *parent, const BackupPlanList &list) :
    WidgetScrollArea(tr("Planned Backups"),
                     tr("You have no planned backups yet.\nClick the button below to create a new backup."),
                     parent),
    m_list(list),
    m_helpLabel(WidgetSettings::newHelpLabel())
{
    m_addListItemButton = new PushButton();
    m_addListItemButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    m_addListItemButton->setSVG(":/backup-add");

    m_addListItemButton->setText(tr("Add new backup"));
    connect(m_addListItemButton,
            SIGNAL(clicked()),
            this,
            SLOT(newBackupWizard()));
    append(m_addListItemButton->Widget());
}


void BackupPlanListWidget::newBackupWizard()
{
    BackupPlan::fromWizard();
}
