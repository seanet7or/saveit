#include "backupplaneditsourcesfilters.h"
#include "ui_backupplaneditsourcesfilters.h"
#include <QVBoxLayout>


BackupPlanEditSourcesFilters::BackupPlanEditSourcesFilters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackupPlanEditSourcesFilters),
    m_sourcesWidget(new WidgetScrollArea(tr("Sources"), this)),
    m_filtersWidget(new WidgetScrollArea(tr("Filters"), this))
{
    ui->setupUi(this);
    setWindowTitle(tr("Creating A New Backup - Select Sources"));
    this->setWindowIcon(QIcon(":/backup-add"));
    this->setContentsMargins(0, 0, 0, 0);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    QLabel *helpLabel = new QLabel(this);
    QFont f = helpLabel->font();
    f.setPointSize(10);
    f.setWeight(QFont::DemiBold);
    f.setStyle(QFont::StyleOblique);
    helpLabel->setFont(f);
    helpLabel->setText(tr("Choose the files and folders you want to include into the backup. Additionally, you may set up a filter to exclude some of the files and subdirectories from the backup."));
    helpLabel->setWordWrap(true);
    helpLabel->setContentsMargins(12, 12, 12, 12);
    layout->addWidget(helpLabel);
    layout->addWidget(m_sourcesWidget);
    layout->addWidget(m_filtersWidget);
    setModal(true);
    this->setLayout(layout);
}


BackupPlanEditSourcesFilters::~BackupPlanEditSourcesFilters()
{
    delete ui;
}
