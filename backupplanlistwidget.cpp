#include "backupplanlistwidget.h"


BackupPlanListWidget::BackupPlanListWidget(QWidget *parent, const BackupPlanList &list) :
    WidgetScrollArea(parent), m_list(list)
{
    m_emptyListButton = new PushButton();
    m_emptyListButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QFont f = m_emptyListButton->font();
    f.setPointSize(12);
    m_emptyListButton->setFont(f);
    m_emptyListButton->setText(tr("\nYou have no backup plans yet.\nClick here to create a new backup.\n"));
    append(m_emptyListButton->Widget());
}
