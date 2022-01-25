/*####################################################################*/
/*######################====FWITEMDELEGATE====########################*/
/*####################################################################*/
/*Description:
FWItemDelegate is Firmware Item Delegate class that implements particular
item in HEX Firmware table View-Model-Delegate pattern
It sets background of items such as color or image while firmware downloads
*/
#include "FWItemDelegate.h"
#include <QApplication>
//Initialize empty item background color & image
FWItemDelegate::FWItemDelegate(QWidget* pParentWidget) : QStyledItemDelegate(pParentWidget)
{
    m_itemColor1 = QColor();
    m_itemImage1 = QImage();
    m_nItemFrom1 = 0;
    m_nItemTo1 = 0;
    m_bColorImage1 = true;
    m_itemColor2 = QColor();
    m_itemImage2 = QImage();
    m_nItemFrom2 = 0;
    m_nItemTo2 = 0;
    m_bColorImage2 = true; //choose what we need : background color or image
    m_itemColor3 = QColor();
    m_itemImage3 = QImage();
    m_nItemFrom3 = 0;
    m_nItemTo3 = 0;
    m_bColorImage3 = true; //choose what we need : background color or image
}
//cleanup
FWItemDelegate::~FWItemDelegate()
{

}
//Paint event of each item (word of firmware) in a HEX table
void FWItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //QPalette palette = option.palette;
    //palette.setColor(QPalette::All,QPalette::Background,QColor(m_nItemColor));
    if(option.state & QStyle::State_Enabled)
    {
            if((index.row()*FW_NUM_COLS + index.column()) >= m_nItemFrom1 && (index.row()*FW_NUM_COLS + index.column()) <= m_nItemTo1)
            {
                if(m_bColorImage1)
                    painter->fillRect(option.rect,m_itemColor1); //set item 1 background in HEX table (loaded word)
                else
                    painter->drawImage(option.rect,m_itemImage1);
            }
            if((index.row()*FW_NUM_COLS + index.column()) >= m_nItemFrom2 && (index.row()*FW_NUM_COLS + index.column()) <= m_nItemTo2)
            {
                if(m_bColorImage2)
                    painter->fillRect(option.rect,m_itemColor2); //set item 2 background in HEX table (loading word)
                else
                    painter->drawImage(option.rect,m_itemImage2);
            }
            if((index.row()*FW_NUM_COLS + index.column()) >= m_nItemFrom3 && (index.row()*FW_NUM_COLS + index.column()) <= m_nItemTo3)
            {
                if(m_bColorImage3)
                    painter->fillRect(option.rect,m_itemColor3); //set item 3 background in HEX table (loading word)
                else
                    painter->drawImage(option.rect,m_itemImage3);
            }
    }
    QStyledItemDelegate::paint(painter,option,index);//call parent method
}
//Set background color of loaded word in HEX table
void FWItemDelegate::setItemColor1(int nItemFrom,int nItemTo,QColor &itemColor)
{
    m_itemColor1 = itemColor;
    m_nItemFrom1 = nItemFrom;
    m_nItemTo1 = nItemTo;
    m_bColorImage1 = true; //background image or color indicator
}
//Set background color of loading word in HEX table
void FWItemDelegate::setItemColor2(int nItemFrom,int nItemTo,QColor &itemColor)
{
    m_itemColor2 = itemColor;
    m_nItemFrom2 = nItemFrom;
    m_nItemTo2 = nItemTo;
    m_bColorImage2 = true;
}
//Set background color of remain words in HEX table
void FWItemDelegate::setItemColor3(int nItemFrom,int nItemTo,QColor &itemColor)
{
    m_itemColor3 = itemColor;
    m_nItemFrom3 = nItemFrom;
    m_nItemTo3 = nItemTo;
    m_bColorImage3 = true;
}
//Set background image of loaded word in HEX table
void FWItemDelegate::setItemImage1(int nItemFrom,int nItemTo,QImage &itemImage)
{
    m_itemImage1 = itemImage;
    m_nItemFrom1 = nItemFrom;
    m_nItemTo1 = nItemTo;
    m_bColorImage1 = false;
}
//Set background image of loading word in HEX table
void FWItemDelegate::setItemImage2(int nItemFrom,int nItemTo,QImage &itemImage)
{
    m_itemImage2 = itemImage;
    m_nItemFrom2 = nItemFrom;
    m_nItemTo2 = nItemTo;
    m_bColorImage2 = false;
}
//Set background image of remain words in HEX table
void FWItemDelegate::setItemImage3(int nItemFrom,int nItemTo,QImage &itemImage)
{
    m_itemImage3 = itemImage;
    m_nItemFrom3 = nItemFrom;
    m_nItemTo3 = nItemTo;
    m_bColorImage3 = false;
}
