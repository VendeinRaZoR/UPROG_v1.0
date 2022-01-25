/*################################################################*/
/*########################====HFLABEL====#########################*/
/*################################################################*/
/*Description:
HFLabel is reimplemented QLabel standard element with additional
feature such as submenu means additional action if user's mouse
presses on Label element (HREF imitation)
*/
#ifndef HFLABEL_H
#define HFLABEL_H

#include <QLabel>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>

class HFLabel : public QLabel
{
    Q_OBJECT
    QWidget *m_pParentWidget;
    bool m_bSubMenu; //submenu active indicator
public:
    explicit HFLabel(QWidget *parent = 0);//init
    void enableSubMenu(bool bEnabled); //Enable/Disable Submenu Underlined References Text
    bool subMenuEnabled(); //Indicator if submenu is already enabled
signals:
    void itemPressed(); //If submenu enabled & left mouse button pressed then emit signal
public slots:
    void mousePressEvent(QMouseEvent *pMouseEvent); //Mouse button press event in Label
};

#endif // HFLABEL_H
