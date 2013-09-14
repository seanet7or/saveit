#include "backupsource.h"


BackupSource::BackupSource() :
    m_dir(QDir::homePath())
{
}


QDir BackupSource::directory() const
{
    return m_dir;
}
