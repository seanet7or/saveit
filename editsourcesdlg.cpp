#include "editsourcesdlg.h"
#include "ui_backupplaneditsourcesfilters.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include "widgetsettings.h"
#include "pushbutton.h"
#include "backupsourcewidget.h"
#include "filtereditdlg.h"


EditSourcesDlg::EditSourcesDlg(QWidget *parent) :
    BaseDlg(parent, tr("Select the source folders to include into the backup")),
    m_sourcesWidget(new WidgetScrollArea(tr("Sources"),
                                         tr("Choose the files and folders you want to include into the backup. Here you may add another folder or move the mouse cursor over a previously included folder to edit or delete it from the schedule."),
                                         this)),
    m_addSourceFolder(new PushButton(this)),
    m_continue(new PushButton(this)),
    m_cancel(new PushButton(this))
{
    this->setWindowIcon(QIcon(":/backup-add"));
    this->setContentsMargins(0, 0, 0, 0);
    m_addSourceFolder->setText(tr("Add a folder"));
    m_addSourceFolder->setSVG(":/folder-add");
    connect(m_addSourceFolder,
            SIGNAL(clicked()),
            this,
            SLOT(onAddSourceButtonPressed()));
    connect(m_continue,
            SIGNAL(clicked()),
            this,
            SLOT(accept()));
    connect(m_cancel,
            SIGNAL(clicked()),
            this,
            SLOT(reject()));
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    m_sourcesWidget->addButton(m_addSourceFolder);
    addSource(QDir::homePath());
    m_continue->setSVG(":/continue");
    m_continue->setText(tr("Use this source"));
    m_cancel->setSVG(":/cancel");
    m_cancel->setText(tr("Cancel"));
    layout->addWidget(m_sourcesWidget);
    QHBoxLayout *nextLayout = new QHBoxLayout();
    nextLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Ignored));
    nextLayout->addWidget(m_cancel);
    nextLayout->addWidget(m_continue);
    nextLayout->setContentsMargins(0, 0, 8, 8);
    layout->addLayout(nextLayout);
    setWindowModality(Qt::WindowModal);
    this->setLayout(layout);
}


EditSourcesDlg::~EditSourcesDlg()
{
}


void EditSourcesDlg::addSource(QDir dir)
{
    QSharedPointer<BackupSource> source(new BackupSource(dir));
    BackupSourceWidget *widget = new BackupSourceWidget(source);
    m_sourcesWidget->append(widget);
    connect(widget,
            SIGNAL(deleteButtonClicked()),
            this,
            SLOT(onDeleteButtonPressed()));
}


void EditSourcesDlg::onAddSourceButtonPressed()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Select a folder to add to the backup"),
                                                    QDir::homePath());
    if (!dir.isEmpty())
    {
        addSource(dir);
    }
}


void EditSourcesDlg::onDeleteButtonPressed()
{
    BackupSourceWidget *w = qobject_cast<BackupSourceWidget*>(sender());
    if (w)
    {
        QSharedPointer<BackupSource> source = w->source();
        delete w;
        m_sourceList.removeAt(m_sourceList.indexOf(source));
    }
}
