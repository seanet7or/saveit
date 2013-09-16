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
    m_deleteButton(QSharedPointer<IconButton>(new IconButton(this))),
    m_editButton(QSharedPointer<IconButton>(new IconButton(this)))
{
    m_sourceLabel->setText(m_source->directory().absolutePath());
    this->setLayout(new QHBoxLayout(this));
    m_deleteButton->setSVG(":/delete");
    m_editButton->setSVG(":/edit");
    layout()->setContentsMargins(8, 1, 8, 1);
    layout()->addWidget(m_sourceLabel.data());
    layout()->addWidget(m_editButton.data());
    layout()->addWidget(m_deleteButton.data());
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
