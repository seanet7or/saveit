#ifndef BACKUPSOURCE_H
#define BACKUPSOURCE_H
#include <QDir>


class BackupSource
{
public:
    BackupSource(QDir dir);
    QDir directory() const;
    void setDirectory(const QString &dir);
private:
    QDir m_dir;
};

#endif // BACKUPSOURCE_H
