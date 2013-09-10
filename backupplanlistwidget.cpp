#include "backupplanlistwidget.h"
#include <QFont>
#include <QtSvg/QSvgRenderer>
#include "backupplan.h"


BackupPlanListWidget::BackupPlanListWidget(QWidget *parent, const BackupPlanList &list) :
    WidgetScrollArea(parent), m_list(list)
{
    m_emptyListButton = new PushButton();
    m_emptyListButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont f = m_emptyListButton->font();
    f.setPointSize(14);
    f.setWeight(QFont::DemiBold);
    f.setStyle(QFont::StyleOblique);
    m_emptyListButton->setSVG(":/backup-add");
    m_emptyListButton->setFont(f);
    m_emptyListButton->setText(tr("You have no planned backups yet.\nClick here to create a new backup."));
    append(m_emptyListButton->Widget());
}


void BackupPlanListWidget::newBackupWizard()
{
    BackupPlan::fromWizard();
}
