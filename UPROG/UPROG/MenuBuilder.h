/*###############################################################*/
/*######################====MENUBUILDER====######################*/
/*###############################################################*/
/*Description:
    Menu Builder class that realize that implements Builder Pattern to
    create and interact with menu that may descripts in JSON file
*/
#ifndef CONFIGBUILDER_H
#define CONFIGBUILDER_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QJsonObject>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include "../../UControlBase.h"
#include "dosmenu/DSLineEdit.h"

#define MAX_LINE_EDIT 15

class MenuBuilder : public UControlBase
{
    Q_OBJECT
    QVBoxLayout* m_pMenuLayout;
    QVector<QRadioButton*> m_radioButtonList;
    QVector<DSLineEdit*> m_lineEditList;
    QVector<QLayout*> m_layoutList;
    QVector<QLabel*> m_labelList;
    QVector<QLabel*> m_labelBlinkList;
    QVector<QTimer*> m_timerList;
    bool m_bBlink;
    bool m_bConfigChanged;
public:
    MenuBuilder(QVBoxLayout*);//Init main layout
    ~MenuBuilder();//cleanup all widgets and layout
    void addRadioButton(QString szName);//Add configured and styled radio button in layout
    void addNamedEdit(QString szNamedEdit);//Add configured and styled label + line edit = named edit in layout
    void addLabelBlink(QString szName);//Add blinking label in layout
    void enableWidgets(bool bEnabled);//Enable/Disable all widgets in builder (layout)
    bool radioButtonValue(int nIndex) const;//get radioButton value by index in list
    QString lineEditValue(int nIndex) const;//get lineEdit value by index in list
    QVector<DSLineEdit*> getLineEditList() const;//get list of created lineEdit
    QVector<QLabel*> getLabelList() const;//get list of created labels
    QVBoxLayout* getMenuLayout();//get menu main layout
    void buildFromJson(QJsonObject *pJsonMainObj);//Build Menu from configuration in JSON file
    void deleteWidgets();//Delete all widgets (widget lists)
    bool isEmpty();//Is menu layout empty
    bool isEditDone();//Is editing of all namedEdits done
public slots:
    void labelBlink();//Blinking timer timeout slot
    void on_lineEdit_returnPressed();//Slot when return pressed in lineEdit box
    void on_lineEdit_textChanged(const QString &arg1);//Set border style to lineEdit when its content changed
    void on_radioButton_cheked(bool);//Change images of radioButtons defined to state
};

#endif // CONFIGBUILDER_H
