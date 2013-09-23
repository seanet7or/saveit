#ifndef FILTEREDITDLG_H
#define FILTEREDITDLG_H

#include <QDialog>

class PushButton;

namespace Ui {
class FilterEditDlg;
}

class FilterEditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FilterEditDlg(QWidget *parent = 0);
    ~FilterEditDlg();

private:
    Ui::FilterEditDlg *ui;
};

#endif // FILTEREDITDLG_H
