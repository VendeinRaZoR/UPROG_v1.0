/*##################################################################*/
/*######################====UCONTROLBASE====########################*/
/*##################################################################*/
/*Description:
UCONTROLBASE class is used for sending parameters from GUI or another
controls with index, given in MenuBuilder, to programmer (sends simple types
like strings, int, float and others, without using any third-party library)
It works like a visitor pattern
*/
#ifndef UCONTROLBASE_H
#define UCONTROLBASE_H

#include <QString>
#include <QObject>

class UControlBase : public QObject
{
    Q_OBJECT
public:
    virtual bool radioButtonValue(int nIndex) const =0; //state of radio button
    virtual QString lineEditValue(int nIndex) const =0; //string value in a line edit text box
};

#endif // UCONTROLBASE_H
