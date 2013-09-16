#ifndef BACKUPPLANEDITSOURCESFILTERS_H
#define BACKUPPLANEDITSOURCESFILTERS_H

#include <QDialog>
#include "widgetscrollarea.h"

class PushButton;


namespace Ui {
class BackupPlanEditSourcesFilters;
}

class BackupPlanEditSourcesFilters : public QDialog
{
    Q_OBJECT

public:
    explicit BackupPlanEditSourcesFilters(QWidget *parent = 0);
    ~BackupPlanEditSourcesFilters();

private:
    Ui::BackupPlanEditSourcesFilters *ui;
    WidgetScrollArea *m_sourcesWidget;
    WidgetScrollArea *m_filtersWidget;
    PushButton *m_addSourceFolder;
    PushButton *m_addSourceFile;
    PushButton *m_continue;
    PushButton *m_cancel;
};

#endif // BACKUPPLANEDITSOURCESFILTERS_H
