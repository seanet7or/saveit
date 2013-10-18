#include "basedlg.h"
#include <QIcon>


BaseDlg::BaseDlg(QWidget *parent, const QString &title) :
    QDialog(parent)
{
    setWindowIcon(QIcon(":/application-icon"));
    setWindowTitle(title);
}
