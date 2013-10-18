#ifndef BASEDLG_H
#define BASEDLG_H

#include <QDialog>

class BaseDlg : public QDialog
{
    Q_OBJECT
public:
    explicit BaseDlg(QWidget *parent, const QString &title);

signals:

public slots:

};

#endif // BASEDLG_H
