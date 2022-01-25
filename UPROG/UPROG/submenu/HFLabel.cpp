/*################################################################*/
/*########################====HFLABEL====#########################*/
/*################################################################*/
/*Description:
HFLabel is reimplemented QLabel standard element with additional
feature such as submenu means additional action if user's mouse
presses on Label element (HREF imitation)
*/
#include "HFLabel.h"
//init
HFLabel::HFLabel(QWidget *parent)
{
    m_pParentWidget = parent;
    m_bSubMenu = false;
}
//Enable/Disable Submenu Underlined References Text
void HFLabel::enableSubMenu(bool bEnabled)
{
    m_bSubMenu = bEnabled;
    QFont font;
    font.setUnderline(bEnabled);
    this->setFont(font);
}
//Indicator if submenu is already enabled
bool HFLabel::subMenuEnabled()
{
    return m_bSubMenu;
}
//Mouse button press event in Label
void HFLabel::mousePressEvent(QMouseEvent *pMouseEvent)
{
    if(pMouseEvent->button() == Qt::LeftButton && m_bSubMenu)
        emit itemPressed();//If submenu enabled & left mouse button pressed then emit signal
}
