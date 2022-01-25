/*################################################################*/
/*######################====HFCOMBOBOX====########################*/
/*################################################################*/
/*Description:
HFComboBox is reimplemented QComboBox standard element with additional
feature such as submenu means another action instead popup window
if user's mouse presses on ComboBox element (HREF imitation)
*/
#ifndef HFCOMBOBOX_H
#define HFCOMBOBOX_H

#include <QComboBox>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>

class HFComboBox : public QComboBox
{
    Q_OBJECT
    QWidget *m_pParentWidget;
    bool m_bSubMenu; //submenu active indicator
public:
    explicit HFComboBox(QWidget *parent = 0); //Initial state with submenu disabled
    void enableSubMenu(bool bEnabled); //Enable/Disable Submenu Underlined References Text
    bool subMenuEnabled(); //Indicator if submenu is already enabled
signals:
    void itemPressed(); //If submenu enabled & left mouse button pressed then emit signal
public slots:
    void mousePressEvent(QMouseEvent *pMouseEvent); //Mouse button press event in ComboBox
};

#endif // HFCOMBOBOX_H
