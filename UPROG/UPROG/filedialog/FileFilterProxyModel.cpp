/*##########################################################################*/
/*######################====FILEFILTERPROXYMODEL====########################*/
/*##########################################################################*/
/*Description:
FileFilterProxyModel is reimplemented QSortFilterProxyModel class that
filter Model means throw away all unuseful items in model
*/
#include "FileFilterProxyModel.h"
#include <QFileSystemModel>
//QSortFilterProxyModel constructor
FileFilterProxyModel::FileFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}
//Set file filter to Model
void FileFilterProxyModel::setFileFilter(const QString &szFileFilter)
{
    m_szFileFilter = szFileFilter;
}
//Reload current model to update data
void FileFilterProxyModel::resetModel()
{
    beginResetModel();
    endResetModel();
}
//Accept filter to throw away unused files in our file system
//In current case this filter is a file extention
bool FileFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index0 = sourceModel()->index(source_row,0,source_parent);
    QFileSystemModel* fileSystemModel = qobject_cast<QFileSystemModel*>(sourceModel());//Model of current file system
    return fileSystemModel->fileName(index0).indexOf(m_szFileFilter) > 0 || fileSystemModel->isDir(index0); //return needed files to appear
}
