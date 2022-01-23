/*#################################################################*/
/*######################====FWTABLEVIEW====########################*/
/*#################################################################*/
/*Description:
FWTableView implements View pattern of Firmware HEX words table
in Model-View-delegate pattern
*/
#include "FWTableView.h"
//Set style of HEX table
FWTableView::FWTableView(QWidget *parent) :
    QTableView(parent)
{
    setStyleSheet("font-family: 'Terminal';");
}
//Force update viewport of View while firmware downloading process
//that displays in HEX table in kind of items changing background color or images
void FWTableView::forceUpdateView()
{
    viewport()->update();
}
//Set colunm width in View
int FWTableView::columnWidth(int column) const
{
    return HEX_TABLE_COLUMN_WIDTH;
}
//Set row height in View
int FWTableView::rowHeight(int row) const
{
    return HEX_TABLE_ROW_HEIGHT;
}
