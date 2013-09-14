#include "backupplaneditsourcesfilters.h"
#include "ui_backupplaneditsourcesfilters.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "widgetsettings.h"
#include "pushbutton.h"


BackupPlanEditSourcesFilters::BackupPlanEditSourcesFilters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackupPlanEditSourcesFilters),
    m_sourcesWidget(new WidgetScrollArea(tr("Sources"),
                                         tr("Choose the files and folders you want to include into the backup."),
                                         this)),
    m_filtersWidget(new WidgetScrollArea(tr("Filters"),
                                         tr("Additionally, you may set up a filter to exclude some of the files and subdirectories from the backup."),
                                         this)),
    m_addSourceFolder(new PushButton(this, this)),
    m_addSourceFile(new PushButton(this, this))
{
    ui->setupUi(this);
    setWindowTitle(tr("Creating A New Backup - Select Sources"));
    this->setWindowIcon(QIcon(":/backup-add"));
    this->setContentsMargins(0, 0, 0, 0);
    m_addSourceFolder->setText(tr("Add a folder"));
    m_addSourceFolder->setSVG(":/folder-add");
    m_addSourceFile->setText(tr("Add a file"));
    m_addSourceFile->setSVG(":/file-add");
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    m_sourcesWidget->addButton(m_addSourceFolder);
    m_sourcesWidget->addButton(m_addSourceFile);
    layout->addWidget(m_sourcesWidget);
    layout->addWidget(m_filtersWidget);
    setWindowModality(Qt::WindowModal);
    this->setLayout(layout);
}


BackupPlanEditSourcesFilters::~BackupPlanEditSourcesFilters()
{
    delete ui;
}
