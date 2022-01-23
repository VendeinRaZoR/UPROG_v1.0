/*################################################################*/
/*######################====DSLINEEDIT====########################*/
/*################################################################*/
/*Description:
DSLineEdit is reimplemented QLineEdit class that draw lineEdit in DOS style
*/

#include "DSLineEdit.h"
#include "DOSProxyStyle.h"

DSLineEdit::DSLineEdit(QWidget *parent) : QLineEdit(parent)
{
    DOSEditStyle *lineEditStyle = new DOSEditStyle(style());
    setStyle(lineEditStyle);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Highlight,QColor("white"));
    pal.setColor(QPalette::HighlightedText,QColor("black"));
    this->setPalette(pal);
}

DSLineEdit::DSLineEdit(const QString & str, QWidget *parent) : QLineEdit(str,parent)
{
    DOSEditStyle *lineEditStyle = new DOSEditStyle(style());
    setStyle(lineEditStyle);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Highlight,QColor("white"));
    pal.setColor(QPalette::HighlightedText,QColor("black"));
    this->setPalette(pal);
}
