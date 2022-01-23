/*##################################################################*/
/*######################====FWTABLEMODEL====########################*/
/*##################################################################*/
/*Description:
FWTableModel implements Model pattern of Firmware HEX words table
in Model-View-delegate pattern
*/
#include "FWTableModel.h"
#include <QDebug>
//Initialize data of HEX table's model
FWTableModel::FWTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_pFWData = 0;
}
//How many rows in HEX table model
int FWTableModel::rowCount(const QModelIndex &parent) const
{
    return m_nDeviceSize/FW_NUM_COLS;
}
//How many cols in HEX table model
int FWTableModel::columnCount(const QModelIndex &parent) const
{
    return FW_NUM_COLS;
}
//A way to display data in HEX table model
QVariant FWTableModel::data(const QModelIndex &index, int role) const
{
    //if(role != Qt::DisplayRole)
     //  return QVariant();
    //if(role == Qt::TextAlignmentRole)
      //  return Qt::AlignRight;
    if(role == Qt::DisplayRole)
    {
        if(m_pFWData != 0 && (index.row()*FW_NUM_COLS + index.column() < m_pFWData->size()))
            return QString("0x") + QString("%1").arg(m_pFWData->at(index.row()*FW_NUM_COLS + index.column()),2,16,QChar('0')).toUpper();
        else
            return QString("0x") + QString("%1").arg(0xFF,0,16).toUpper();
    }
    return QVariant();
}
//A way to display data in a header of HEX table model
QVariant FWTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Horizontal)
    {
        return QVariant("0x0" + QString("%1").arg(section,0,16));
    }

    if(orientation == Qt::Vertical)
    {
        return "0x" + QString("%1").arg(section*FW_NUM_COLS,sizeof(unsigned int),16,QChar('0'));
    }

    return QVariant();
}
//setData function for editable model (firmware data may be changed)
bool FWTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        emit dataChanged(this->index(0,0),this->index(m_nDeviceSize/FW_NUM_COLS - 1,FW_NUM_COLS,QModelIndex()));
        return true; //dataChanged must be emitted if data in items (item) was changed in model (in range from item (0,0) to (NUM_ROWS,NUM_COLS))
    }
    return false;
}
//reserved
bool FWTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    /*beginRemoveRows(parent,row, row + count + 1);
    while(count--)
    {
        for(int i=0;i<FW_NUM_COLS;i++)
        {
            if(m_pFWData != 0)
                m_pFWData->removeAt(row*i);
        }
    }
    endRemoveRows();*/
    return true;
}
//Set device memory size for setup number of rows of HEX table model
void FWTableModel::setDeviceSize(int nDeviceSize)
{
    beginResetModel();
    m_nDeviceSize = nDeviceSize;
    endResetModel();
}
//Set firmware data into HEX table
void FWTableModel::setFirmwareData(QVector<unsigned long>* pFWData)
{
    beginResetModel();
    m_pFWData = pFWData;
    endResetModel();
}
//Reload (update) HEX table model
void FWTableModel::resetModel()
{
    beginResetModel();
    endResetModel();
}
