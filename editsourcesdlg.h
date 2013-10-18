#ifndef BACKUPPLANEDITSOURCESFILTERS_H
#define BACKUPPLANEDITSOURCESFILTERS_H

#include <QDialog>
#include <QDir>
#include "widgetscrollarea.h"
#include "basedlg.h"

class PushButton;
class BackupSource;


class EditSourcesDlg : public BaseDlg
{
    Q_OBJECT

public:
    explicit EditSourcesDlg(QWidget *parent = 0);
    ~EditSourcesDlg();

private:
    void addSource(QDir dir);

private slots:
    void onAddSourceButtonPressed();
    void onDeleteButtonPressed();

private:
    QList<QSharedPointer<BackupSource> > m_sourceList;
    WidgetScrollArea *m_sourcesWidget;
    PushButton *m_addSourceFolder;
    PushButton *m_continue;
    PushButton *m_cancel;
};

#endif // BACKUPPLANEDITSOURCESFILTERS_H
