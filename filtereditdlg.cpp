#include "filtereditdlg.h"
#include "ui_filtereditdlg.h"
#include "pushbutton.h"

FilterEditDlg::FilterEditDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterEditDlg)

{
    ui->setupUi(this);

}

FilterEditDlg::~FilterEditDlg()
{
    delete ui;
}
