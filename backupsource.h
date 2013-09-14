#ifndef BACKUPSOURCE_H
#define BACKUPSOURCE_H
#include <QDir>


class BackupSource
{
public:
    BackupSource();
    QDir directory() const;
private:
    QDir m_dir;
};

#endif // BACKUPSOURCE_H
