#include "backupsourcewidget.h"
#include "backupsource.h"
#include "widgetsettings.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include "delegates/mousehoverable.h"


BackupSourceWidget::BackupSourceWidget(QSharedPointer<BackupSource> source,
                                       QWidget *parent) :
    QWidget(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    m_source(source),
    m_sourceLabel(WidgetSettings::newTextLabel(this)),
    m_deleteButton(new PushButton(this, this)),
    m_editButton(new PushButton(this, this)),
    m_includeHiddenButton(new CheckButton(this, this))
{
    m_sourceLabel->setText(m_source->directory().absolutePath());
    QFont font = m_sourceLabel->font();
    font.setBold(true);
    m_sourceLabel->setFont(font);
    this->setLayout(new QHBoxLayout(this));
    m_deleteButton->setSVG(":/delete");
    m_editButton->setSVG(":/edit");
    m_deleteButton->setContentsMargins(0, 0, 0, 0);
    m_editButton->setContentsMargins(0, 0, 0, 0);
    m_deleteButton->setMouseHoverColor(WidgetSettings::iconButtonMouseOverColor());
    m_editButton->setMouseHoverColor(WidgetSettings::iconButtonMouseOverColor());
    connect(m_deleteButton,
            SIGNAL(pressed()),
            this,
            SIGNAL(deleteButtonClicked()));
    m_includeHiddenButton->setText(tr("hidden files"));
    font = WidgetSettings::buttonFont();
    font.setPointSize(font.pointSize() - 1);
    m_includeHiddenButton->setFont(font);
    m_deleteButton->setFont(font);
    m_editButton->setFont(font);
    m_includeHiddenButton->setContentsMargins(0, 0, 0, 0);
    m_includeHiddenButton->setMouseHoverColor(WidgetSettings::iconButtonMouseOverColor());
    layout()->setContentsMargins(8, 1, 8, 1);
    layout()->addWidget(m_sourceLabel.data());
    layout()->addWidget(m_includeHiddenButton);
    layout()->addWidget(m_editButton);
    layout()->addWidget(m_deleteButton);
    ((QHBoxLayout*)layout())->addSpacerItem(new QSpacerItem(0, 10, QSizePolicy::Expanding, QSizePolicy::Ignored));
    int h = m_includeHiddenButton->minimumHeight();
    connect(m_editButton,
            SIGNAL(clicked()),
            this,
            SLOT(OnEditButtonPressed()));
    setFixedHeight(h);
}


void BackupSourceWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(QColor(150, 150, 150, 64));
    painter.drawLine(rect().x(), rect().y(),
                     rect().right(), rect().y());
    painter.drawLine(rect().x(), rect().bottom(),
                     rect().right(), rect().bottom());
    DrawMouseHoverRect(painter);
    QWidget::paintEvent(e);
}


QSharedPointer<BackupSource> BackupSourceWidget::source() const
{
     return m_source;
}


void BackupSourceWidget::OnEditButtonPressed()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Select a folder to add to the backup"),
                                                    m_source->directory().absolutePath());
    if (!dir.isEmpty())
    {
        m_source->setDirectory(dir);
        m_sourceLabel->setText(dir);
    }
}
