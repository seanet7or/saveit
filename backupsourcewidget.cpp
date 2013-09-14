#include "backupsourcewidget.h"
#include "backupsource.h"
#include "widgetsettings.h"


BackupSourceWidget::BackupSourceWidget(BackupSource *source,
                                       QWidget *parent) :
    QPushButton(parent)
{

}


void BackupSourceWidget::paintEvent(QPaintEvent *e)
{
    int h = rect().height() - 2 * WidgetSettings::iconButtonTopLeftMargins();
    int w = rect().width() - 2 * WidgetSettings::iconButtonLeftRightMargins();
    int l = std::min(w, h);
    int xOff = rect().width() - l;
    xOff /= 2;
    int yOff = rect().height() - l;
    yOff /= 2;
    QRect target(rect().x() + xOff,
                 rect().y() + yOff,
                 l, l);
}


void BackupSourceWidget::setSVG(const QString &name)
{
    m_svg.load(name);
}
