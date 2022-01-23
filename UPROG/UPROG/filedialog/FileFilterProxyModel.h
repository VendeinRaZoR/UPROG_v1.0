/*##########################################################################*/
/*######################====FILEFILTERPROXYMODEL====########################*/
/*##########################################################################*/
/*Description:
FileFilterProxyModel is reimplemented QSortFilterProxyModel class that
filter Model means throw away all unuseful items in model
*/
#ifndef FILEFILTERPROXYMODEL_H
#define FILEFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

class FileFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    QString m_szFileFilter;
public:
    explicit FileFilterProxyModel(QObject *parent = 0); //QSortFilterProxyModel constructor
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const; //Accept filter to throw away unnecessary files
    void setFileFilter(const QString& szFileFilter); //Set file filter to Model
    void resetModel(); //Reload current model to update data
signals:
    
public slots:
    
};

#endif // FILEFILTERPROXYMODEL_H
