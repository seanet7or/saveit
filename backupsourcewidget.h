#ifndef BACKUPSOURCEWIDGET_H
#define BACKUPSOURCEWIDGET_H
#include <QSharedPointer>
#include <QWidget>
#include <QPushButton>
#include <QSvgRenderer>
#include <QLabel>
#include "backupsource.h"
#include "iconbutton.h"
#include "delegates/mousehovercomposite.h"
#include "checkbutton.h"


class BackupSourceWidget : public QWidget, protected MouseHoverComposite
{
    Q_OBJECT
public:
    explicit BackupSourceWidget(QSharedPointer<BackupSource> source, QWidget *parent = 0);
    QSharedPointer<BackupSource> source() const;
signals:
    void deleteButtonClicked();

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    QSharedPointer<BackupSource> m_source;
    QSharedPointer<QLabel> m_sourceLabel;
    IconButton* m_deleteButton;
    IconButton* m_editButton;
    CheckButton *m_includeHiddenButton;
};

#endif // BACKUPSOURCEWIDGET_H
