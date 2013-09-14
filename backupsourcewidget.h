#ifndef BACKUPSOURCEWIDGET_H
#define BACKUPSOURCEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSvgRenderer>
#include "backupsource.h"


class BackupSourceWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit BackupSourceWidget(BackupSource *source, QWidget *parent = 0);
    void setSVG(const QString &name);
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QSvgRenderer m_svg;

};

#endif // BACKUPSOURCEWIDGET_H
