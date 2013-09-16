#include "backupsource.h"


BackupSource::BackupSource(QDir dir) :
    m_dir(dir)
{
}


QDir BackupSource::directory() const
{
    return m_dir;
}
