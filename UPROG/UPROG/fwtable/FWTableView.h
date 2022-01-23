/*#################################################################*/
/*######################====FWTABLEVIEW====########################*/
/*#################################################################*/
/*Description:
FWTableView implements View pattern of Firmware HEX words table
in Model-View-delegate pattern
*/
#ifndef FWTABLEVIEW_H
#define FWTABLEVIEW_H

#include <QTableView>

#define HEX_TABLE_COLUMN_WIDTH 40
#define HEX_TABLE_ROW_HEIGHT 40

class FWTableView : public QTableView
{
    Q_OBJECT
public:
    explicit FWTableView(QWidget *parent = 0);
    void forceUpdateView(); //Force update viewport of View while firmware downloading process
    int columnWidth(int column) const; //Set colunm width in View
    int rowHeight(int row) const; //Set row height in View
signals:
    
public slots:
    
};

#endif // FWTABLEVIEW_H
