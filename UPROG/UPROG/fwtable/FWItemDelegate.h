/*####################################################################*/
/*######################====FWITEMDELEGATE====########################*/
/*####################################################################*/
/*Description:
FWItemDelegate is Firmware Item Delegate class that implements particular
item in HEX Firmware table View-Model-Delegate pattern
It sets background of items such as color or image while firmware downloads
*/
#ifndef FWITEMDELEGATE_H
#define FWITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QPalette>
#include <QImage>
#include <QVariant>

#include "FWTableCommon.h"

class FWItemDelegate : public QStyledItemDelegate
{
    QColor m_itemColor1; //background colors and images
    QImage m_itemImage1;
    int m_nItemFrom1;
    int m_nItemTo1;
    bool m_bColorImage1;
    QColor m_itemColor2;
    QImage m_itemImage2;
    int m_nItemFrom2;
    int m_nItemTo2;
    bool m_bColorImage2;
public:
    FWItemDelegate(QWidget* pParentWidget = 0); //Initialize empty item background color & image
    virtual ~FWItemDelegate(); //cleanup
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const; //Paint event of each item (word of firmware) in a HEX table
    void setItemColor1(int nItemFrom,int nItemTo,QColor &itemColor); //Set background color of loaded word in HEX table
    void setItemColor2(int nItemFrom,int nItemTo,QColor &itemColor); //Set background color of loading word in HEX table
    void setItemImage1(int nItemFrom,int nItemTo,QImage &itemImage); //Set background image of loaded word in HEX table
    void setItemImage2(int nItemFrom,int nItemTo,QImage &itemImage); //Set background image of loading word in HEX table
};

#endif // FWITEMDELEGATE_H
