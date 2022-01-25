/*################################################################*/
/*######################====HFCOMBOBOX====########################*/
/*################################################################*/
/*Description:
HFComboBox is reimplemented QComboBox standard element with additional
feature such as submenu means another action instead popup window
if user's mouse presses on ComboBox element (HREF imitation)
*/
#include "HFComboBox.h"
//Initial state with submenu disabled
HFComboBox::HFComboBox(QWidget *parent) : QComboBox(parent)
{
    m_pParentWidget = parent;
    m_bSubMenu = false;
}
//Enable/Disable Submenu Underlined References Text
void HFComboBox::enableSubMenu(bool bEnabled)
{
    m_bSubMenu = bEnabled;
    QFont font;
    font.setUnderline(bEnabled);
    this->setFont(font);
}
//Indicator if submenu is already enabled
bool HFComboBox::subMenuEnabled()
{
    return m_bSubMenu;
}
//Mouse button press event in ComboBox
void HFComboBox::mousePressEvent(QMouseEvent *pMouseEvent)
{
    if(pMouseEvent->button() == Qt::LeftButton && m_bSubMenu)
        emit itemPressed();//If submenu enabled & left mouse button pressed then emit signal
    else
        showPopup();//else show popup list menu
}
