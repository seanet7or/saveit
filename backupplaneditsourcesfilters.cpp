#include "backupplaneditsourcesfilters.h"
#include "ui_backupplaneditsourcesfilters.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "widgetsettings.h"
#include "pushbutton.h"
#include "backupsourcewidget.h"


BackupPlanEditSourcesFilters::BackupPlanEditSourcesFilters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackupPlanEditSourcesFilters),
    m_sourcesWidget(new WidgetScrollArea(tr("Sources"),
                                         tr("Choose the files and folders you want to include into the backup."),
                                         this)),
    m_filtersWidget(new WidgetScrollArea(tr("Filters"),
                                         tr("Additionally, you may set up a filter to exclude some of the files and subdirectories from the backup."),
                                         this)),
    m_addSourceFolder(new PushButton(this)),
    m_addSourceFile(new PushButton(this)),
    m_continue(new PushButton(this)),
    m_cancel(new PushButton(this))
{
    ui->setupUi(this);
    setWindowTitle(tr("Creating A New Backup - Select Sources"));
    this->setWindowIcon(QIcon(":/backup-add"));
    this->setContentsMargins(0, 0, 0, 0);
    m_addSourceFolder->setText(tr("Add a folder"));
    m_addSourceFolder->setSVG(":/folder-add");
    connect(m_addSourceFolder,
            SIGNAL(clicked()),
            this,
            SLOT(onAddSourceButtonPressed()));
    m_addSourceFile->setText(tr("Add a file"));
    m_addSourceFile->setSVG(":/file-add");
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    m_sourcesWidget->addButton(m_addSourceFolder);
    m_sourcesWidget->addButton(m_addSourceFile);
    addSource(QDir::homePath());
    m_continue->setSVG(":/continue");
    m_continue->setText(tr("Continue"));
    m_cancel->setSVG(":/cancel");
    m_cancel->setText(tr("Cancel"));
    layout->addWidget(m_sourcesWidget);
    layout->addWidget(m_filtersWidget);
    QHBoxLayout *nextLayout = new QHBoxLayout();
    nextLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
    nextLayout->addWidget(m_cancel);
    nextLayout->addWidget(m_continue);
    nextLayout->setContentsMargins(0, 0, 8, 8);
    layout->addLayout(nextLayout);
    setWindowModality(Qt::WindowModal);
    this->setLayout(layout);
}


BackupPlanEditSourcesFilters::~BackupPlanEditSourcesFilters()
{
    delete ui;
}


void BackupPlanEditSourcesFilters::addSource(QDir dir)
{
    QSharedPointer<BackupSource> source(new BackupSource(dir));
    BackupSourceWidget *widget = new BackupSourceWidget(source);
    m_sourcesWidget->append(widget);
    connect(widget,
            SIGNAL(deleteButtonClicked()),
            this,
            SLOT(onDeleteButtonPressed()));
}


void BackupPlanEditSourcesFilters::onAddSourceButtonPressed()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Select a folder to add to the backup"),
                                                    QDir::homePath());
    if (!dir.isEmpty())
    {
        addSource(dir);
    }
}


void BackupPlanEditSourcesFilters::onDeleteButtonPressed()
{
    BackupSourceWidget *w = qobject_cast<BackupSourceWidget*>(sender());
    if (w)
    {
        QSharedPointer<BackupSource> source = w->source();
        delete w;
        m_sourceList.removeAt(m_sourceList.indexOf(source));
    }
}
