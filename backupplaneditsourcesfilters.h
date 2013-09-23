#ifndef BACKUPPLANEDITSOURCESFILTERS_H
#define BACKUPPLANEDITSOURCESFILTERS_H

#include <QDialog>
#include <QDir>
#include "widgetscrollarea.h"

class PushButton;
class BackupSource;


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
    void addSource(QDir dir);

private slots:
    void onAddSourceButtonPressed();
    void onAddFilterButtonPressed();
    void onDeleteButtonPressed();

private:
    QList<QSharedPointer<BackupSource> > m_sourceList;
    Ui::BackupPlanEditSourcesFilters *ui;
    WidgetScrollArea *m_sourcesWidget;
    WidgetScrollArea *m_filtersWidget;
    PushButton *m_addSourceFolder;
    PushButton *m_addSourceFile;
    PushButton *m_continue;
    PushButton *m_cancel;
    PushButton *m_addIsoFiles;
    PushButton *m_addArchiveFiles;
    PushButton *m_addTemporaryFiles;
    PushButton *m_addCustomFilter;

};

#endif // BACKUPPLANEDITSOURCESFILTERS_H
