#include "backupsourcewidget.h"
#include "backupsource.h"
#include "widgetsettings.h"
#include <QVBoxLayout>
#include "delegates/mousehoverable.h"


BackupSourceWidget::BackupSourceWidget(QSharedPointer<BackupSource> source,
                                       QWidget *parent) :
    QWidget(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    m_source(source),
    m_sourceLabel(WidgetSettings::newTextLabel(this)),
    m_deleteButton(new IconButton(this)),
    m_editButton(new IconButton(this)),
    m_includeHiddenButton(new CheckButton(this))
{
    m_sourceLabel->setText(m_source->directory().absolutePath());
    this->setLayout(new QHBoxLayout(this));
    m_deleteButton->setSVG(":/delete");
    connect(m_deleteButton,
            SIGNAL(pressed()),
            this,
            SIGNAL(deleteButtonClicked()));
    m_editButton->setSVG(":/edit");
    m_includeHiddenButton->setText(tr("hidden files"));
    QFont font = WidgetSettings::buttonFont();
    font.setPointSize(font.pointSize() - 1);
    m_includeHiddenButton->setFont(font);
    m_includeHiddenButton->setContentsMargins(0, 0, 0, 0);
    m_includeHiddenButton->setMouseHoverColor(WidgetSettings::iconButtonMouseOverColor());
    layout()->setContentsMargins(8, 1, 8, 1);
    layout()->addWidget(m_sourceLabel.data());
    layout()->addWidget(m_includeHiddenButton);
    layout()->addWidget(m_editButton);
    layout()->addWidget(m_deleteButton);
    ((QHBoxLayout*)layout())->addSpacerItem(new QSpacerItem(0, 10, QSizePolicy::Expanding, QSizePolicy::Ignored));
    int h = m_sourceLabel->height();
    m_deleteButton->setFixedHeight(h);
    m_editButton->setFixedHeight(h);
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
