/*###############################################################*/
/*######################====MENUBUILDER====######################*/
/*###############################################################*/
/*Description:
    Menu Builder class that realize that implements Builder Pattern to
    create and interact with menu that may descripts in JSON file
*/
#include "MenuBuilder.h"
#include "../../UCommon.h"
#include <QDebug>

#define WRONG_FORMAT_TITLE tr("Неверный формат данных")
#define WRONG_FORMAT_TEXT tr("Неверный формат введенных данных\nДопускается только число без знаков")

#define BLINK_TIME 500 //time for blinking effect for empty device & interface menu
//set menu layout and edit done indicator
//Init main layout
MenuBuilder::MenuBuilder(QVBoxLayout* pMenuLayout)
{
    m_pMenuLayout = pMenuLayout;
    m_bConfigChanged = false;
}
//cleanup all widgets and layout
MenuBuilder::~MenuBuilder()
{
    delete m_pMenuLayout;
    deleteWidgets();
}
//Add configured and styled radio button in layout
void MenuBuilder::addRadioButton(QString szName)
{
    QRadioButton *pRadioButton = new QRadioButton(szName,m_pMenuLayout->parentWidget());
    pRadioButton->setStyleSheet("QRadioButton::indicator{ image: url('../images/radiooff.png'); color:white; font-family: 'Terminal';}");
    pRadioButton->setCheckable(true);
    pRadioButton->setAutoExclusive(false);
    pRadioButton->setMouseTracking(true);
    connect(pRadioButton,SIGNAL(toggled(bool)),this,SLOT(on_radioButton_cheked(bool)));
    m_pMenuLayout->addWidget(pRadioButton);//add in layout
    m_radioButtonList.append(pRadioButton); //append in list
}
//Add configured and styled label + line edit = named edit in layout
void MenuBuilder::addNamedEdit(QString szNamedEdit)
{
    QStringList szNamedEditList = szNamedEdit.split("|");
    QString szName = szNamedEditList.at(0);
    QString szEdit = szNamedEditList.at(1);
    QHBoxLayout *pLineLayout = new QHBoxLayout();//Horizontal layout for control
    QLabel *pLabel = new QLabel(szName,m_pMenuLayout->parentWidget());//label
    DSLineEdit *pLineEdit = new DSLineEdit(szEdit,m_pMenuLayout->parentWidget());//lineEdit
    pLineEdit->setStyleSheet("QLineEdit{border: 2px solid white;background-color:blue;}");//style
    connect(pLineEdit,&QLineEdit::textChanged,this,&MenuBuilder::on_lineEdit_textChanged);
    connect(pLineEdit,&QLineEdit::returnPressed,this,&MenuBuilder::on_lineEdit_returnPressed);
    pLineLayout->addWidget(pLabel);
    pLineLayout->addWidget(pLineEdit);
    m_layoutList.append(pLineLayout); //append in list (vector)
    m_labelList.append(pLabel); //append in list
    m_lineEditList.append(pLineEdit); //append in list
    m_pMenuLayout->addLayout(pLineLayout); //add in layout
}
//Add blinking label in layout
void MenuBuilder::addLabelBlink(QString szName)
{
    QLabel *pBlinkLabel = new QLabel(szName,m_pMenuLayout->parentWidget());
    pBlinkLabel->setAlignment(Qt::AlignCenter);
    QTimer *pLabelTimer = new QTimer(this);
    pLabelTimer->start(BLINK_TIME); //start blink timer
    connect(pLabelTimer,&QTimer::timeout,this,&MenuBuilder::labelBlink); //timeout slot connection
    m_timerList.append(pLabelTimer); //append timer & label in list
    m_labelBlinkList.append(pBlinkLabel);
    m_pMenuLayout->addWidget(pBlinkLabel);
}
//Is menu layout empty
bool MenuBuilder::isEmpty()
{
    return m_radioButtonList.isEmpty() && m_lineEditList.isEmpty() &&
            m_layoutList.isEmpty() && m_timerList.isEmpty();
}
//get menu main layout
QVBoxLayout* MenuBuilder::getMenuLayout()
{
    return m_pMenuLayout;
}
//get list of created lineEdit
QVector<DSLineEdit*> MenuBuilder::getLineEditList() const
{
    return m_lineEditList;
}
//get list of created labels
QVector<QLabel*> MenuBuilder::getLabelList() const
{
    return m_labelList;
}
//get radioButton value by index in list
bool MenuBuilder::radioButtonValue(int nIndex) const
{
    return m_radioButtonList[nIndex]->isChecked();
}
//get lineEdit value by index in list
QString MenuBuilder::lineEditValue(int nIndex) const
{
    return m_lineEditList[nIndex]->text();
}
//Build Menu from configuration in JSON file
void MenuBuilder::buildFromJson(QJsonObject *pJsonMainObj)
{
    QJsonObject::Iterator iMenu;
    for(iMenu = pJsonMainObj->begin();iMenu != pJsonMainObj->end();iMenu++)
    {
        if(iMenu.value().toString() == "RadioButton") //Add every control into menu layout
            addRadioButton(iMenu.key());
        if(iMenu.value().toString() == "LineEdit")
            this->addNamedEdit(iMenu.key());
    }
}
//Enable/Disable all widgets in builder (layout)
void MenuBuilder::enableWidgets(bool bEnabled)
{
    QVector<QRadioButton*>::Iterator rbi;//Iterators for every control lists
    for(rbi = m_radioButtonList.begin();rbi != m_radioButtonList.end();rbi++)
    {
        if(*rbi != 0)
            (*rbi)->setEnabled(bEnabled);
    }

    QVector<QLayout*>::Iterator li;
    for(li = m_layoutList.begin();li != m_layoutList.end();li++)
    {
        if(*li != 0)
            (*li)->setEnabled(bEnabled);
    }

    QVector<QLabel*>::Iterator lbli;
    for(lbli = m_labelList.begin();lbli != m_labelList.end();lbli++)
    {
        if(*lbli != 0)
            (*lbli)->setEnabled(bEnabled);
    }

    QVector<DSLineEdit*>::Iterator lei;
    for(lei = m_lineEditList.begin();lei != m_lineEditList.end();lei++)
    {
        if(*lei != 0)
            (*lei)->setEnabled(bEnabled);
    }

}
//Delete all widgets (widget lists)
void MenuBuilder::deleteWidgets()
{
    QVector<QRadioButton*>::Iterator rbi; //Iterators for every control lists
    m_bConfigChanged = false;
    for(rbi = m_radioButtonList.begin();rbi != m_radioButtonList.end();rbi++)
    {
        if(*rbi != 0)
        {
            disconnect(*rbi,SIGNAL(toggled(bool)),this,SLOT(on_radioButton_cheked(bool)));
            m_pMenuLayout->removeWidget(*rbi);
            delete *rbi;
        }
    }
    m_radioButtonList.clear();//clear list

    QVector<QLayout*>::Iterator li;
    for(li = m_layoutList.begin();li != m_layoutList.end();li++)
    {
        if(*li != 0)
        {
            m_pMenuLayout->removeItem(*li);
            delete *li;
        }
    }
    m_layoutList.clear();

    QVector<QLabel*>::Iterator lbli;
    for(lbli = m_labelList.begin();lbli != m_labelList.end();lbli++)
    {
        if(*lbli != 0)
        {
            m_pMenuLayout->removeWidget(*lbli);
            delete *lbli;
        }
    }
    m_labelList.clear();

    QVector<QLabel*>::Iterator lblbi;
    for(lblbi = m_labelBlinkList.begin();lblbi != m_labelBlinkList.end();lblbi++)
    {
        if(*lblbi != 0)
        {
            m_pMenuLayout->removeWidget(*lblbi);
            delete *lblbi;
        }
    }
    m_labelBlinkList.clear();

    QVector<QTimer*>::Iterator tmri;
    for(tmri = m_timerList.begin();tmri != m_timerList.end();tmri++)
    {
        if(*tmri != 0)
        {
            disconnect(*tmri,&QTimer::timeout,this,&MenuBuilder::labelBlink);
            (*tmri)->stop();
            delete *tmri;
        }
    }
    m_timerList.clear();


    QVector<DSLineEdit*>::Iterator lei;
    for(lei = m_lineEditList.begin();lei != m_lineEditList.end();lei++)
    {
        if(*lei != 0)
        {
            disconnect(*lei,&QLineEdit::textChanged,this,&MenuBuilder::on_lineEdit_textChanged);
            disconnect(*lei,&QLineEdit::returnPressed,this,&MenuBuilder::on_lineEdit_returnPressed);
            m_pMenuLayout->removeWidget(*lei);
            delete *lei;
        }
    }
    m_lineEditList.clear();
}
//Is editing of all namedEdits done
bool MenuBuilder::isEditDone()
{
    return m_bConfigChanged;
}
//Blinking timer timeout slot
void MenuBuilder::labelBlink()
{
    QVector<QLabel*>::Iterator lblbi;
    m_bBlink = !m_bBlink;
    for(lblbi = m_labelBlinkList.begin();lblbi != m_labelBlinkList.end();lblbi++)
        (*lblbi)->setVisible(m_bBlink);
}
//Slot when return pressed in lineEdit box
void MenuBuilder::on_lineEdit_returnPressed()
{
    QLineEdit *pLineEdit = static_cast<QLineEdit*>(sender());//Object that sends signal associated with slot
    QRegExp regExp("\\d*");
    if(pLineEdit->text() == "")//Empty lineEdit field
    {
        MessageBoxWarningOk(WRONG_FORMAT_TITLE,WRONG_FORMAT_TEXT);
        m_bConfigChanged = true;
    }
    else //else set normal border style
    {
        pLineEdit->setStyleSheet("QLineEdit{border: 2px solid white}");
        m_bConfigChanged = false;
    }
}
//Set border style to lineEdit when its content changed
void MenuBuilder::on_lineEdit_textChanged(const QString &arg1)
{
    QLineEdit *pLineEdit = static_cast<QLineEdit*>(sender());
    if(pLineEdit->text().length() < MAX_LINE_EDIT)
    {
        m_bConfigChanged = true;
        pLineEdit->setStyleSheet("QLineEdit{border: 2px solid red}");
    }
    if(pLineEdit->text().length() > MAX_LINE_EDIT)
        pLineEdit->setText(pLineEdit->text().mid(0,MAX_LINE_EDIT));
}
//Change images of radioButtons defined to state
void MenuBuilder::on_radioButton_cheked(bool bChecked)
{
    QRadioButton *pRadioButton = static_cast<QRadioButton*>(sender());
    if(bChecked)
        pRadioButton->setStyleSheet("QRadioButton::indicator{ image: url('../images/radioon.png'); color:white; font-family: 'Terminal';}");
    else
        pRadioButton->setStyleSheet("QRadioButton::indicator{ image: url('../images/radiooff.png'); color:white; font-family: 'Terminal';}");
}
