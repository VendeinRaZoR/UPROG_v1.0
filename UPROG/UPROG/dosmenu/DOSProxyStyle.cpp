/*################################################################*/
/*######################====DOSEDITSTYLE====######################*/
/*################################################################*/
/*Description:
DOSEditStyle reimplements QProxyStyle class methods for restyle
lineEdit
*/
#include "DOSProxyStyle.h"

#define CURSOR_WIDTH 8 //Width of blinking lineEdit cursor
//DSLineEdit in DOS styled
DOSEditStyle::DOSEditStyle(QStyle *parent) :
    QProxyStyle(parent)
{
}
//Wide cursor like DOS style
int DOSEditStyle::pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    if(metric == PM_TextCursorWidth)
        return CURSOR_WIDTH; //reimplemented function now returns new PixelMetric that means another cursor width
    return QProxyStyle::pixelMetric(metric,option,widget);
}
