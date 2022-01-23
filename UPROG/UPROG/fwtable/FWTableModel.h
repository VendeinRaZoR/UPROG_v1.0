/*##################################################################*/
/*######################====FWTABLEMODEL====########################*/
/*##################################################################*/
/*Description:
FWTableModel implements Model pattern of Firmware HEX words table
in Model-View-delegate pattern
*/
#ifndef FWTABLEMODEL_H
#define FWTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>
#include <QSize>

#include "FWTableCommon.h"

class FWTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QVector<unsigned long>* m_pFWData;
    int m_nDeviceSize;
public:
    explicit FWTableModel(QObject *parent = 0); //Initialize data of HEX table's model
    int rowCount(const QModelIndex &parent) const; //How many rows in HEX table model
    int columnCount(const QModelIndex &parent) const; //How many cols in HEX table model
    bool removeRows(int row, int count, const QModelIndex &parent); //reverved for removing rows operations
    QVariant data(const QModelIndex &index, int role) const;//A way to display data in HEX table model
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;//A way to display data in a header of HEX table model
    void setFirmwareData(QVector<unsigned long>* pFWData); //Set firmware data into HEX table
    void setDeviceSize(int nDeviceSize); //Set device memory size for setup number of rows of HEX table model
    bool setData(const QModelIndex &index, const QVariant &value, int role); //setData function for editable model (firmware data may be changed)
    void resetModel(); //Reload (update) HEX table model
signals:
    
public slots:
    
};

#endif // FWTABLEMODEL_H
