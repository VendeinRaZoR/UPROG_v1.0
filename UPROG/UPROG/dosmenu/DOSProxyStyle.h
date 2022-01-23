/*################################################################*/
/*######################====DOSEDITSTYLE====######################*/
/*################################################################*/
/*Description:
DOSEditStyle reimplements QProxyStyle class methods for restyle
lineEdit
*/
#ifndef DOSPROXYSTYLE_H
#define DOSPROXYSTYLE_H //guard

#include <QProxyStyle>

class DOSEditStyle : public QProxyStyle
{
    Q_OBJECT
public:
    explicit DOSEditStyle(QStyle *parent = 0); //DSLineEdit in DOS styled
    int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const; //Wide cursor like DOS style
    
signals:
    
public slots:
    
};

#endif // DOSPROXYSTYLE_H
