/*###############################################################*/
/*######################====MAIN WINDOW====######################*/
/*###############################################################*/
/*Description:
    UPROG Universal Programmer's Main Window class
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#define HEXFILE_CSUM_ERROR -3 //HEX File Checksum Error
#define HEXFILE_RECTYPE_ERROR -2 //HEX File Wrong record type
#define HEXFILE_ADDREX_NOTSUPPORT -4 //HEX File Extended Address Not Support
#define HEXFILE_BEGINRECORD_ERROR -1 //HEX File record begin not found

#define NO_FIRMWARE_OPEN_TITLE tr("Стереть микросхему?")
#define NO_FIRMWARE_OPEN_TEXT tr("Файл прошивки не задан\nСтереть текущую микросхему?")
#define NO_FIRMWARE_SAVE_TITLE tr("Чтение без сохранения")
#define NO_FIRMWARE_SAVE_TEXT tr("Файл прошивки не указан\nПрочитать содержимое текущей микросхемы?")
#define SET_PARPORT_ADDRESS_TITLE tr("Адрес LPT порта")
#define SET_PARPORT_ADDRESS_TEXT tr("Вы точно уверены в правильности\nадреса LPT порта?\nПоследствия могут быть непредсказуемыми")
#define DEVICE_INIT_TITLE tr("Микросхема инициализирована")
#define DEVICE_INIT_WRITE_TEXT tr("Сигналы установлены\nПитание подано\nПрошить микросхему полностью?")
#define DEVICE_INIT_READ_TEXT tr("Сигналы установлены\nПитание подано\nЧитать микросхему полностью?")
#define DEVICE_NOT_FOUND_TITLE tr("Устройство не найдено")
#define DEVICE_NOT_FOUND_TEXT tr("Устройство не отвечает\nПроверьте соединения и контакты")
#define DEVICE_NOT_FOUND_TEXT_B tr("Устройство с кодом производителя\n")
#define DEVICE_NOT_FOUND_TEXT_E tr("\nне найдено\nВсё равно начать чтение/запись ?")
#define LENGTH_GREATER_TITLE tr("Файл прошивки велик")
#define LENGTH_GREATER_TEXT tr("Размер файла прошивки больше,\nчем максимально доступный обьем памяти\nмикросхемы")
#define WRITE_ERROR_TITLE tr("Ошибка при прожиге")
#define WRITE_ERROR_TEXT tr("Невозможно прожечь микросхему\nПроверьте контакты и саму микросхему")
#define WRITE_DONE_TITLE tr("ПрожЫг завершён!")
#define WRITE_DONE_TEXT tr("Процесс прожЫга завершен успешно!\nПитание отключено\nМожете вынимать микосхему из программатора")
#define READ_ERROR_TITLE tr("Ошибка при чтении")
#define READ_ERROR_TEXT tr("Невозможно прочитать микросхему\nПроверьте контакты и саму микросхему")
#define READ_DONE_TITLE tr("Чтение завершено")
#define READ_DONE_TEXT tr("Процесс чтения завершен успешно!\nПитание отключено\nМожете вынимать микосхему из программатора")
#define HEX_FILE_CSUMERR_TITLE tr("Ошибка в контрольной сумме HEX")
#define HEX_FILE_RECTYPEERR_TITLE tr("Ошибка типа записи HEX")
#define HEX_FILE_ADDREX_NOTSUPPORT_TITLE tr("Расширенный адрес HEX")
#define HEX_FILE_BEGINRECORD_ERROR_TITLE tr("Ошибка начала записи HEX")
#define HEX_FILE_EMPTY_TITLE tr("Пустой HEX файл")
#define HEX_FILE_EMPTY_TEXT tr("HEX файл не содержит данных для прошивки")
#define CONFIG_CHANGED_TITLE tr("Изменение настроек")
#define CONFIG_CHANGED_TEXT tr("Сохраните настройки параметров\n(все текстовые поля зеленые, а не красные)\nперед чтением или записью")
#define INTERFACE_SETUP_ERROR_TITLE tr("Ошибка настройки программатора")
#define LPT_ADDRESS_WARNING_TITLE tr("Проверьте адрес LPT порта!")
#define LPT_ADDRESS_WARNING_TEXT tr("<b>Внимание!</b><br>Внимательно проверьте адрес LPT порта!<br>Он задается вручную, \
так как не все контроллеры LPT<br>(например, PCI-LPT или PCIe-LPT) распознаются в системе автоматически<br><br>\
Поэтому программирование по неверному адресу может пройти без ошибок, что будет неверно, либо программа зависнет,<br>\
либо изменятся настройки какого-либо оборудования, что может повлиять на его работу!<br>\
Узнать адрес своего LPT порта можно в свойствах оборудования в диспетчере устройств (Windows)<br>\
либо с помощью команды lspci (Linux)<br><br>\
<b>ВСЁ ДЕЛАТЬ НА СВОЙ СТРАХ И РИСК<br>Точно начать программировать?</b>")
////////////////////////////////////
#define PART_BURN_NOT_SUPPORT_TITLE tr("Выборочная прошивка не поддерживается")
#define PART_BURN_NOT_SUPPORT_TEXT tr("Выборочная прошивка микросхемы не поддерживается\nв данной версии программы")
#define MANINFO_NOT_FOUND_TITLE tr("Информация о производителе не найдена")
#define MANINFO_NOT_FOUND_TEXT tr("Информация о производителе (сслыка) не указана в JSON-файле\nили указана неверно")
#define MANINFO_NOT_FOUND_PATH_TEXT tr("Файл с информацией о производителе не указан в JSON-файле\nили указан неверно")
#define DATASHEET_NOT_FOUND_TITLE tr("Документация не найдена")
#define DATASHEET_NOT_FOUND_TEXT tr("Ссылка на документацию не указан в JSON-файле\nили указан неверно")
#define DATASHEET_NOT_FOUND_PATH_TEXT tr("Файл с документацией не указан в JSON-файле\nили указан неверно")
#define HEX_FILE_CRC_ERROR tr("Ошибка контрольной суммы HEX файла\nСтрока : ")
#define HEX_FILE_UNKNOWN_RECORD_TYPE tr("Неизвестный тип записи HEX файла\nСтрока : ")
#define HEX_FILE_BEGIN_SYMBOL_EMPTY tr("Отсутствует ':' в начале записи строки HEX файла\nСтрока : ")

using namespace boost::python; //Using Boost::Python

//Initialization of menu, python scripts, JSON, python interpreter, window
MainWindow::MainWindow(QPython *pPythonInterpreter,QVector<QJsonObject> *pJsonObjList,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//
    m_pUDevice = 0;//Universal Device pointer
    m_pManLabel = new QLabel(ui->frame_2);//Menu Labels
    m_pManLabel->setText(tr("Производитель"));//
    m_pManLabel->setAlignment(Qt::AlignCenter);//
    m_pHFComboBox = new HFComboBox(ui->frame_2);//
    m_pDevLabel = new QLabel(ui->frame_2);//
    m_pDevLabel->setText(tr("Микросхема"));//
    m_pDevLabel->setAlignment(Qt::AlignCenter);//
    m_pHFComboBox_2 = new HFComboBox(ui->frame_2);//
    m_pIntfLabel = new QLabel(ui->frame);//
    m_pIntfLabel->setText(tr("Программатор"));//
    m_pIntfLabel->setAlignment(Qt::AlignCenter);//
    m_pHFComboBox_3 = new HFComboBox(ui->frame);//
    m_pHFComboBox->show();//Show Labels
    m_pHFComboBox_2->show();//
    m_pHFComboBox_3->show();//
    this->statusBar()->setVisible(true);//Status Bar Configuration
    this->statusBar()->setSizeGripEnabled(false);//
    this->statusBar()->showMessage(tr("ESC - завершить программирование CTRL - дополнительное меню"));//
    this->setWindowFlags(this->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);//Fixed window size
    ui->verticalLayout_6->addWidget(m_pManLabel);//Add Labels to layout
    ui->verticalLayout_6->addWidget(m_pHFComboBox);//
    ui->verticalLayout_6->addWidget(m_pDevLabel);//
    ui->verticalLayout_6->addWidget(m_pHFComboBox_2);//
    ui->verticalLayout_5->addWidget(m_pIntfLabel);//
    ui->verticalLayout_5->addWidget(m_pHFComboBox_3);//
    m_pPythonInterpreter = pPythonInterpreter;//Init Python Interpreter
    m_pJsonObjList = pJsonObjList;//Init JSON Object List
    m_pMenuDevice = new MenuBuilder(new QVBoxLayout(ui->groupBox));//
    m_pMenuInterface = new MenuBuilder(new QVBoxLayout(ui->groupBox_2));//
    m_pFileSaveProxyModel = new FileFilterProxyModel();//
    m_pFileOpenProxyModel = new FileFilterProxyModel();//
    m_fwloadModule = import("fwload");//import python module (script)
    m_fwloadNamespace = m_fwloadModule.attr("__dict__");//Namespace of python module
    m_fwsaveModule = import("fwsave");//
    m_fwsaveNamespace = m_fwsaveModule.attr("__dict__");//
    ui->frame_3->setAutoFillBackground(true);//
    ui->frame_4->setAutoFillBackground(true);//
    ui->frame_3->setPalette(QPalette(QBrush(),QBrush(),QBrush(),
                                 QBrush(),QBrush(),QBrush(),
                                 QBrush(),QBrush(),QBrush(Qt::Dense7Pattern)));//Background Brushes
    ui->frame_4->setPalette(QPalette(QBrush(),QBrush(),QBrush(),
                                 QBrush(),QBrush(),QBrush(),
                                 QBrush(),QBrush(),QBrush(Qt::Dense7Pattern)));//
    m_pHFLabel = new HFLabel();
    //ui->scrollArea->addScrollBarWidget(m_pHFLabel,Qt::AlignCenter);
    ui->verticalLayout_2->addWidget(m_pHFLabel);
    //ui->frame_3->setCursor(QCursor());
    //ui->frame_4->setCursor(QCursor());

}
//UPROG destructor
MainWindow::~MainWindow()
{
    m_progThread.wait();
    delete ui;
}
//Set thread for programmer
void MainWindow::setupThreads()
{
    m_progThread.setParent(this);//Programmer's thread for programming process
    m_pUDevice->moveToThread(&m_progThread);
}
//Setting menu's signals and slots
void MainWindow::connectSlots()
{
    connect(&m_openFileDialog,&QFileDialog::filterSelected,this,&MainWindow::updateProxyModel);
    connect(&m_saveFileDialog,&QFileDialog::filterSelected,this,&MainWindow::updateProxyModel);
    connect(m_pHFComboBox,&HFComboBox::itemPressed,this,&MainWindow::getManufactureInfo);
    connect(m_pHFComboBox_2,&HFComboBox::itemPressed,this,&MainWindow::getDataSheet);
    connect(m_pHFComboBox_3,&HFComboBox::itemPressed,this,&MainWindow::getSchematics);
    connect(m_pHFLabel,&HFLabel::itemPressed,this,&MainWindow::getSchematicsPixmap);
    connect(m_pHFComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_hfcomboBox_currentIndexChanged(QString)));
    connect(m_pHFComboBox_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_hfcomboBox_2_currentIndexChanged(QString)));
    connect(m_pHFComboBox_3,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_hfcomboBox_3_currentIndexChanged(QString)));
}
//Setup or Reconnect signals and slots when changing Device (IC)
void MainWindow::setupProgrammer()
{
    if(m_pUDevice != 0)
    {
        disconnect(&m_progThread,&QThread::started,m_pUDevice,&UProgBase::progRun);
        disconnect(m_pUDevice,&UProgBase::writeError,&m_progThread,&QThread::terminate);
        disconnect(m_pUDevice,&UProgBase::writeError,this,&MainWindow::writeError);
        disconnect(m_pUDevice,&UProgBase::readError,&m_progThread,&QThread::terminate);
        disconnect(m_pUDevice,&UProgBase::readError,this,&MainWindow::readError);
        disconnect(m_pUDevice,&UProgBase::error,this,&MainWindow::error);
        disconnect(m_pUDevice,&UProgBase::error,&m_progThread,&QThread::terminate);
        disconnect(m_pUDevice,&UProgBase::writeDone,&m_progThread,&QThread::terminate);
        disconnect(m_pUDevice,&UProgBase::writeDone,this,&MainWindow::writeDone);
        disconnect(m_pUDevice,&UProgBase::readDone,&m_progThread,&QThread::terminate);
        disconnect(m_pUDevice,&UProgBase::readDone,this,&MainWindow::readDone);
        disconnect(m_pUDevice,&UProgBase::progStatus,this,&MainWindow::updateProgressBar);
        delete m_pUDevice;
        m_pUDevice = 0;
    }
    m_pUDevice = m_DeviceCommon.createDevice(m_pHFComboBox_2->currentText(),m_pHFComboBox_3->currentText());
    if(m_pUDevice)
    {
        m_pUDevice->moveToThread(&m_progThread);
        connect(&m_progThread,&QThread::started,m_pUDevice,&UProgBase::progRun);
        connect(m_pUDevice,&UProgBase::writeError,&m_progThread,&QThread::terminate);
        connect(m_pUDevice,&UProgBase::writeError,this,&MainWindow::writeError);
        connect(m_pUDevice,&UProgBase::readError,&m_progThread,&QThread::terminate);
        connect(m_pUDevice,&UProgBase::readError,this,&MainWindow::readError);
        connect(m_pUDevice,&UProgBase::error,this,&MainWindow::error);
        connect(m_pUDevice,&UProgBase::error,&m_progThread,&QThread::terminate);
        connect(m_pUDevice,&UProgBase::writeDone,&m_progThread,&QThread::terminate);
        connect(m_pUDevice,&UProgBase::writeDone,this,&MainWindow::writeDone);
        connect(m_pUDevice,&UProgBase::readDone,&m_progThread,&QThread::terminate);
        connect(m_pUDevice,&UProgBase::readDone,this,&MainWindow::readDone,Qt::QueuedConnection);
        connect(m_pUDevice,&UProgBase::progStatus,this,&MainWindow::updateProgressBar);
    }
}
//Setup Model-View-Delegate of HEX table window
void MainWindow::setupHEXTable()
{
    QString szItemPath(IMAGE_PATH); //Path to images
    szItemPath += "/coilwire.png"; //(open image every frame, change algorithm in future!!!)
    QImage itemImage(szItemPath); //Image of items in HEX table
    m_pFWTableModel = new FWTableModel(); //Model
    m_pFWTableView = new FWTableView(); //View
    m_pFWItemDelegate = new FWItemDelegate(); //Delegate
    m_pFWTableView->setItemDelegate(m_pFWItemDelegate); //Set Delegate for View
    m_pFWTableModel->setFirmwareData(m_pUDevice->getFirmware()); //Set Model
    m_pFWTableModel->setDeviceSize(m_pUDevice->getSize());
    m_pFWTableView->setModel(m_pFWTableModel); //Set View by Model
    m_pFWTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);//Size of Table's Headers
    m_pFWTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);//
    m_pFWTableView->verticalHeader()->setDefaultSectionSize(HEX_TABLE_COLUMN_WIDTH);//
    m_pFWTableView->horizontalHeader()->setDefaultSectionSize(HEX_TABLE_ROW_HEIGHT);//
    m_pFWTableView->verticalHeader()->setDefaultSectionSize(HEX_TABLE_COLUMN_WIDTH);//
    ui->verticalLayout->addWidget(m_pFWTableView); //Set View in Layout
    ui->tab_2->setLayout(ui->verticalLayout); //Set Layout in a Tab
    m_pFWItemDelegate->setItemImage1(0,0,itemImage); //Set HEX table Item Background Image
    m_pFWItemDelegate->setItemImage2(0,m_pUDevice->getSize(),itemImage); //
    m_pFWItemDelegate->setItemImage3(m_pUDevice->getSize(),m_pUDevice->getSize(),itemImage);//
    m_pFWTableView->forceUpdateView(); //Update View to Redraw window
}
//Update HEX Table Model with Data
void MainWindow::updateHEXTable()
{
    if(m_pUDevice)
    {
        m_pFWTableModel->setFirmwareData(m_pUDevice->getFirmware());
        m_pFWTableModel->setDeviceSize(m_pUDevice->getSize());
    }
    else
    {
        m_pFWTableModel->setFirmwareData(0);
        m_pFWTableModel->setDeviceSize(0);
    }
    m_pFWTableView->setModel(m_pFWTableModel);
}
//Update Main Menu Manufactures List from JSON files objects
void MainWindow::updateManList()
{
    QJsonObject::Iterator iMan;
    QJsonObject::Iterator iDev;
    m_szManInfoPath.clear();
    for(int i = 0;i<m_pJsonObjList->size();i++) //Find all Manufactures from JSON files
    {
        QJsonObject jsonMan = m_pJsonObjList->at(i);
        for(iMan = jsonMan.begin();iMan != jsonMan.end();iMan++)
            m_pHFComboBox->addItem(iMan.key());
    }
}
//Update Main Menu Manufacture's Devices List from JSON files objects
void MainWindow::updateDevList()
{
    QJsonObject::Iterator iMan; //JSON object iterator for manufacture records
    QJsonObject::Iterator iDev; //JSON object iterator for device records
    QJsonObject::Iterator iIntf; //JSON object iterator for interface records
    m_pHFComboBox_2->clear();
    m_pHFComboBox_3->clear();
    m_szDataSheetPath.clear();
    for(int i = 0;i<m_pJsonObjList->size();i++) //Find all Manufactures from JSON files
    {
        QJsonObject jsonMan = m_pJsonObjList->at(i);
        for(iMan = jsonMan.begin();iMan != jsonMan.end();iMan++)
        {
            if(iMan.key() == m_pHFComboBox->currentText())
            {
                m_jsonDev = iMan.value().toObject();
                for(iDev = m_jsonDev.begin();iDev != m_jsonDev.end();iDev++) //Find all Devices by this Manufacture in JSON file
                {
                    if(iDev.value().toString() == "ManInfo")
                    {
                        m_szManInfoPath = iDev.key(); //Current Manufacture's info documentation or website
                    }
                    else
                    {
                        m_pHFComboBox_2->addItem(iDev.key());//Add Current Manufacture's Devices List in ComboBox
                        m_jsonIntf = iDev.value().toObject();
                        for(iIntf = m_jsonIntf.begin();iIntf != m_jsonIntf.end();iIntf++) //Find all Interfaces by this Device in JSON file
                        {
                            if((iIntf.value().toString() == "DataSheet") && (iDev.key() == m_pHFComboBox_2->currentText())) //Find DataSheet for Device
                                m_szDataSheetPath = iIntf.key();
                            if(iIntf.value().isObject() && iDev.key() == m_pHFComboBox_2->currentText()) //Add Interfaces in ComboBox
                                m_pHFComboBox_3->addItem(iIntf.key());                                  // associated to this Device
                        }
                    }
                }
            }
        }
    }
    if(m_pHFComboBox->currentText() == "")
        m_pHFComboBox->addItem(tr("<Нет производителя>"));
    if(m_pHFComboBox_2->currentText() == "")
        m_pHFComboBox_2->addItem(tr("<Нет микросхем>"));
    if(m_pHFComboBox_3->currentText() == "")
    {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        m_pHFComboBox_3->addItem(tr("<Нет интерфейса>"));
        m_pHFComboBox_3->setEnabled(false);
    }
    else
    {
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        m_pHFComboBox_3->setEnabled(true);
        enableMenu(true);
    }
}
//Update & Build Device's menu from JSON file object
void MainWindow::updateDevMenu()
{
    QJsonObject::Iterator iMan;
    QJsonObject::Iterator iDev;
    QJsonObject::Iterator iDevMenu;
    for(int i = 0;i<m_pJsonObjList->size();i++) //Find all Manufactures from JSON files
    {
        QJsonObject jsonMan = m_pJsonObjList->at(i);
        for(iMan = jsonMan.begin();iMan != jsonMan.end();iMan++)
        {
            if(iMan.key() == m_pHFComboBox->currentText())
            {
                m_jsonDev = iMan.value().toObject();
                for(iDev = m_jsonDev.begin();iDev != m_jsonDev.end();iDev++) //Find all Devices by this Manufacture
                {
                    if(iDev.key() == m_pHFComboBox_2->currentText())
                    {
                        m_jsonDevMenu = iDev.value().toObject();
                        m_pMenuDevice->deleteWidgets();
                        m_pMenuDevice->buildFromJson(&m_jsonDevMenu); //Build Device's Configuration Menu from JSON file
                    }
                }
            }
        }
    }
    if(m_pMenuDevice->isEmpty())
        m_pMenuDevice->addLabelBlink(tr("<Нет микросхемы>"));
}
//Update & Build Interface menu for this Device
void MainWindow::updateIntfMenu()
{
    QJsonObject::Iterator iMan;
    QJsonObject::Iterator iDev;
    QJsonObject::Iterator iDevMenu;
    QJsonObject::Iterator iIntfMenu;
    m_pHFLabel->clear();
    m_pHFLabel->setText(tr("<Схема отсутсвует>"));
    m_pHFLabel->setStyleSheet("QLabel{color:red;font-size:20px;font:bold;}");
    m_pHFLabel->setAlignment(Qt::AlignCenter);
    for(int i = 0;i<m_pJsonObjList->size();i++)
    {
        QJsonObject jsonMan = m_pJsonObjList->at(i);
        for(iMan = jsonMan.begin();iMan != jsonMan.end();iMan++) //Find all Manufactures from JSON files
        {
            if(iMan.key() == m_pHFComboBox->currentText())
            {
                m_jsonDev = iMan.value().toObject();
                for(iDev = m_jsonDev.begin();iDev != m_jsonDev.end();iDev++) //Find all Devices by this Manufacture
                {
                    if(iDev.key() == m_pHFComboBox_2->currentText())
                    {
                        m_jsonDevMenu = iDev.value().toObject();
                        m_pMenuInterface->deleteWidgets();
                        for(iDevMenu = m_jsonDevMenu.begin();iDevMenu != m_jsonDevMenu.end();iDevMenu++)
                        {
                            if(iDevMenu.value().isObject())
                            {
                                m_jsonIntfMenu = iDevMenu.value().toObject();
                                m_pMenuInterface->buildFromJson(&m_jsonIntfMenu); //Build Interface Configuration Menu from JSON file
                                for(iIntfMenu = m_jsonIntfMenu.begin();iIntfMenu != m_jsonIntfMenu.end();iIntfMenu++) //Find all Interfaces by this Device in JSON file
                                {
                                    if(iIntfMenu.value().isString())
                                    {
                                        if(iIntfMenu.value().toString() == "Schematic")
                                        {
                                            m_szSchematicPath = iIntfMenu.key(); //Add Schematic's Pixmap associated to this Device & Interface
                                            if(!m_szSchematicPath.isEmpty())
                                            {
                                                m_schemPixmap = QPixmap(m_szSchematicPath);
                                                if(!m_schemPixmap.isNull())
                                                {
                                                    m_schemPixmap = m_schemPixmap.scaled(ui->tabWidget->size(),Qt::IgnoreAspectRatio);
                                                    m_pHFLabel->setPixmap(m_schemPixmap);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(m_pMenuInterface->isEmpty())
        m_pMenuInterface->addLabelBlink(tr("<Нет интерфейса>"));
}
//Update File Dialogs Proxy Models with current filter
void MainWindow::updateProxyModel(const QString& filter)
{
    QString szNewFilter = filter.mid(filter.indexOf("."),filter.indexOf(")")-filter.indexOf("."));
    m_pFileSaveProxyModel->setFileFilter(szNewFilter);
    m_pFileOpenProxyModel->setFileFilter(szNewFilter);
}
//Update Progress Bar & Firmware Download Progress
void MainWindow::updateProgressBar(int nProgress)
{
    QString szItemPathAction(IMAGE_PATH);
    QString szItemPathReady(IMAGE_PATH);
    QString szItemPathRemain(IMAGE_PATH);
    szItemPathReady += "/coilwire_ready.png";
    szItemPathAction += "/coilwire_action.png";
    szItemPathRemain += "/coilwire.png";
    QImage itemImageReady(szItemPathReady); //Background Image indicates already downloaded firmware's word in HEX Table
    QImage itemImageAction(szItemPathAction); //Background Image indicates downloading firmware's word in HEX Table
    QImage itemImageRemain(szItemPathRemain);
    ui->progressBar->setValue(nProgress); //Set Progress Bar current progress value
    m_pFWItemDelegate->setItemImage1(0,nProgress,itemImageReady); //Set Items images with Delegate
    m_pFWItemDelegate->setItemImage2(nProgress+1,nProgress+1,itemImageAction);//
    m_pFWItemDelegate->setItemImage3(nProgress+2,m_pUDevice->getSize(),itemImageRemain);//
    m_pFWTableModel->setFirmwareData(m_pUDevice->getFirmware());//
    m_pFWTableView->forceUpdateView();//Update Viewport while downloading process
}
//Enable/Disable Menu Controls (Blocking user interact with main menu)
void MainWindow::enableMenu(bool bEnabled)
{
    ui->pushButton->setEnabled(bEnabled);
    ui->pushButton_2->setEnabled(bEnabled);
    m_pHFComboBox->setEnabled(bEnabled);
    m_pHFComboBox_2->setEnabled(bEnabled);
    m_pHFComboBox_3->setEnabled(bEnabled);
    m_pMenuDevice->enableWidgets(bEnabled);
    m_pMenuInterface->enableWidgets(bEnabled);
}
//Event when closing Main Window
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_pUDevice)
        m_pUDevice->progAbort();
    m_progThread.terminate();
}
//Error event when programmer fail Device recognize
void MainWindow::error(int nLastError)
{
    if(nLastError)
    {
        MessageBoxCriticalOk(DEVICE_NOT_FOUND_TITLE,DEVICE_NOT_FOUND_TEXT);
        enableMenu(true);
    }
}
//Write Done event when programmer's device writing process done
void MainWindow::writeDone()
{
    MessageBoxInfoOk(WRITE_DONE_TITLE,WRITE_DONE_TEXT);
    enableMenu(true);
}
//Read Done event when programmer's device reading process done
void MainWindow::readDone()
{
    MessageBoxInfoOk(READ_DONE_TITLE,READ_DONE_TEXT);
    updateHEXTable();
    if(m_bSaveFirmData)
    {
        m_fwsaveModule.attr("fwSave")(m_szFirmFile.toStdString(),m_pUDevice->getFirmware());
        m_pPythonInterpreter->showOutput();
    }
    enableMenu(true);
}
//Read Error event when error detected in Device firmware reading process
void MainWindow::readError()
{
    MessageBoxCriticalOk(READ_ERROR_TITLE,READ_ERROR_TEXT);
    enableMenu(true);
}
//Write Error event when error detected in Device firmware writing process
void MainWindow::writeError()
{
    MessageBoxCriticalOk(WRITE_ERROR_TITLE,WRITE_ERROR_TEXT);
    enableMenu(true);
}
//Device write firmware push button
void MainWindow::on_pushButton_pressed()
{
    if(!m_pMenuDevice->isEditDone() && !m_pMenuInterface->isEditDone())
    {
        m_pUDevice->setType(m_pHFComboBox_2->currentText());
        m_pUDevice->setInterface(m_pHFComboBox_3->currentText());
        if(m_pUDevice->getInterface() == "LPT_I2C")
        {
            if(MessageBoxWarningNoYes(LPT_ADDRESS_WARNING_TITLE,LPT_ADDRESS_WARNING_TEXT) == QMessageBox::No) return;
        }
        if(setupDevice())
            writeDevice(); //Write Firmware into Device
        else
            return;
    }
    else
    {
        MessageBoxWarningOk(CONFIG_CHANGED_TITLE,CONFIG_CHANGED_TEXT);
    }
}
//Device read firmware push button
void MainWindow::on_pushButton_2_pressed()
{
    if(!m_pMenuDevice->isEditDone() && !m_pMenuInterface->isEditDone())
    {
        m_pUDevice->setType(m_pHFComboBox_2->currentText());
        m_pUDevice->setInterface(m_pHFComboBox_3->currentText());
        if(m_pUDevice->getInterface() == "LPT_I2C")
        {
            if(MessageBoxWarningNoYes(LPT_ADDRESS_WARNING_TITLE,LPT_ADDRESS_WARNING_TEXT) == QMessageBox::No) return;
        }
        if(setupDevice())
            readDevice(); //Read Firmware from Device
        else
            return;
    }
    else
    {
        MessageBoxWarningOk(CONFIG_CHANGED_TITLE,CONFIG_CHANGED_TEXT);
    }
}
//Event when mouse button is already released
void MainWindow::mouseReleaseEvent(QMouseEvent *vm)
{
    setCursor(QCursor(Qt::ArrowCursor));
    m_pHFComboBox->enableSubMenu(false);
    m_pHFComboBox_2->enableSubMenu(false);
    m_pHFComboBox_3->enableSubMenu(false);
}
//Ctrl Key Press Event first & second times
void MainWindow::keyPressEvent(QKeyEvent *vk)
{
    if(vk->key() == Qt::Key_Control)
    {
        if(m_pHFComboBox->subMenuEnabled()) //ComboBox version with HREF
        {
            setCursor(QCursor(Qt::ArrowCursor));
            m_pHFComboBox->enableSubMenu(false);
            m_pHFComboBox_2->enableSubMenu(false);
            m_pHFComboBox_3->enableSubMenu(false);
            m_pHFLabel->enableSubMenu(false);
        }
        else
        {
            setCursor(QCursor(Qt::PointingHandCursor));
            m_pHFComboBox->enableSubMenu(true);
            m_pHFComboBox_2->enableSubMenu(true);
            m_pHFComboBox_3->enableSubMenu(true);
            m_pHFLabel->enableSubMenu(true);
        }
    }
    if(vk->key() == Qt::Key_Escape)
    {
        m_pUDevice->progAbort();
    }
}
//Key Release Event (Reserved)
void MainWindow::keyReleaseEvent(QKeyEvent *vk)
{

}
//Update Menu when Manufacture's comboBox item changed
void MainWindow::on_hfcomboBox_currentIndexChanged(const QString &arg1)
{
    setupProgrammer();
    updateDevList();
    updateDevMenu();
    updateHEXTable();
    updateIntfMenu();
}
//Update Menu when Device's comboBox item changed
void MainWindow::on_hfcomboBox_2_currentIndexChanged(const QString &arg1)
{
    setupProgrammer();
    updateDevMenu();
    updateHEXTable();
    updateIntfMenu();
}
//Update Menu when Interface comboBox item changed
void MainWindow::on_hfcomboBox_3_currentIndexChanged(const QString &arg1)
{
    updateIntfMenu();
}
//Write Firmware into Device
void MainWindow::writeDevice()
{
    m_szFirmFormatLoad = QString(extract<char*>(m_fwloadNamespace["fwFormat"])); //Read Firmware Formats from Python script
    m_openFileDialog.setWindowTitle(tr("Выберите прошивку"));
    m_openFileDialog.setNameFilter(m_szFirmFormatLoad); //Set Firmware format filter from Python Module script
    m_openFileDialog.setFixedSize(600,300);//set size of file dialog
    m_openFileDialog.setOptions(QFileDialog::DontUseNativeDialog);//Use own dialog style
    m_openFileDialog.setViewMode(QFileDialog::Detail);//How files display in dialog
    m_openFileDialog.setDirectory("/");//Set start directory
    QString szCurrentFilter = m_openFileDialog.selectedNameFilter();//Initial file extension filter
    m_pFileOpenProxyModel->setFileFilter(szCurrentFilter.mid(szCurrentFilter.indexOf("."),szCurrentFilter.indexOf(")")-szCurrentFilter.indexOf(".")));//get extension
    m_pFileOpenProxyModel->resetModel();//Update current Proxy Model with new filter
    m_openFileDialog.setProxyModel(m_pFileOpenProxyModel);//Set proxy model
    m_openFileDialog.setAcceptMode(QFileDialog::AcceptOpen);//File open mode
    if(m_openFileDialog.exec())
        m_szFirmFile = m_openFileDialog.selectedFiles()[0];//Firmware file name
    if(m_szFirmFile.isEmpty())
    {
        if(MessageBoxWarningNoYes(NO_FIRMWARE_OPEN_TITLE,NO_FIRMWARE_OPEN_TEXT) == QMessageBox::Yes)
        {
            m_fwDataWrite.resize(m_pUDevice->getSize()); //if no firmware choosed, resize firmware Data
            m_fwDataWrite.fill(0xFF); //with maximum size and fill all firmware with 0xFF
        }
        else
        {
            return;
        }
    }
    else
    {
        object retlist = m_fwloadModule.attr("fwLoad")(m_szFirmFile.toStdString());//Run python module function with file name
        m_fwDataWrite = TypeFromPython< QVector<unsigned long> >::convert(retlist.ptr()); //Convert list from python to QVector
    }
    m_pUDevice->setFirmware(&m_fwDataWrite); //Set firmware pointer to Universal Programmer
    if(m_fwDataWrite.size() > m_pUDevice->getSize()) //If size of Device less than Frimware Size then error
    {
        MessageBoxCriticalOk(LENGTH_GREATER_TITLE,LENGTH_GREATER_TEXT);
        return;
    }

    if(m_fwDataWrite.size() == 2 && m_fwDataWrite[0] == HEXFILE_CSUM_ERROR) //If returned CheckSum error from python script then CheckSum firmware file error
    {
        MessageBoxCriticalOk(HEX_FILE_CSUMERR_TITLE,QString(HEX_FILE_CRC_ERROR + QVariant("%1").toString().arg(m_fwDataWrite[1],0,10)));
        return;
    }

    if(m_fwDataWrite.size() == 2 && m_fwDataWrite[0] == HEXFILE_RECTYPE_ERROR) //If returned invalid record from python script then display error
    {
        MessageBoxCriticalOk(HEX_FILE_RECTYPEERR_TITLE,QString(HEX_FILE_UNKNOWN_RECORD_TYPE + QVariant("%1").toString().arg(m_fwDataWrite[1],0,10)));
        return;
    }

    if(m_fwDataWrite.size() == 2 && m_fwDataWrite[0] == HEXFILE_BEGINRECORD_ERROR) //If returned invalid begin of record in firmware file then display error
    {
        MessageBoxCriticalOk(HEX_FILE_BEGINRECORD_ERROR_TITLE,QString(HEX_FILE_BEGIN_SYMBOL_EMPTY + QVariant("%1").toString().arg(m_fwDataWrite[1],0,10)));
        return;
    }

    if(m_fwDataWrite.size() == 0) //If file size NULL then display error
    {
        MessageBoxCriticalOk(HEX_FILE_EMPTY_TITLE,HEX_FILE_EMPTY_TEXT);
        return;
    }

    if(m_fwDataWrite.size()%m_pUDevice->getPageSize()) //If firmware data size on page size division result is not integer value then append 0xFF bytes into tail to page size
    {
        qDebug() << "Len " << m_fwDataWrite.size();
        qDebug() << "Remain bytes from firmware : " << m_fwDataWrite.size()%m_pUDevice->getPageSize();
        int writeBytes = m_pUDevice->getPageSize() + m_pUDevice->getPageSize() - m_fwDataWrite.size()%m_pUDevice->getPageSize();
        qDebug() << "Bytes need to write : " << writeBytes;
        for(int i = 0;i < writeBytes;i++)
            m_fwDataWrite.append(0x00FF);
    }

    updateHEXTable(); //Update HEX Table Model with Data
    ui->tabWidget->setCurrentWidget(ui->tab_2); //set current tab - tab_2
    m_pUDevice->init(); //initialize Universal Programmer
    int nMBResult = MessageBoxWarningYesNo(DEVICE_INIT_TITLE,DEVICE_INIT_WRITE_TEXT);
    if(nMBResult == QMessageBox::Yes)
    {
        if(!m_pUDevice->checkInfo()) //Check device info
        {
            QString szDevInfo = "0x" + QString("%1").arg(m_pUDevice->getInfo().byte0,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte1,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte2,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte3,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte4,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte5,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte6,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte7,0,16).toUpper(); //if device not found by our info then warn user
            if(MessageBoxWarningYesNo(DEVICE_NOT_FOUND_TITLE,QString(DEVICE_NOT_FOUND_TEXT_B + szDevInfo + DEVICE_NOT_FOUND_TEXT_E)) == QMessageBox::Yes)
            {
                QString szItemPath(IMAGE_PATH);//
                szItemPath += "/coilwire.png";//
                QImage itemImage(szItemPath);//set items background images in HEX table
                ui->progressBar->setRange(0,m_pUDevice->getSize()-1);//setup progress bar
                ui->progressBar->setVisible(true);//
                m_pFWItemDelegate->setItemImage1(0,0,itemImage);//
                m_pFWItemDelegate->setItemImage2(0,m_pUDevice->getSize(),itemImage);//
                m_pFWItemDelegate->setItemImage3(m_pUDevice->getSize(),m_pUDevice->getSize(),itemImage);//
                enableMenu(false);//disable main menu for user
                m_pUDevice->writeConfiguration(m_pMenuDevice);//write device's configuration memory
                m_pUDevice->writeFull();//write full device
                m_progThread.start();//go to thread function in programmer's class
            }
            else
            {
                return;
            }
        }
        else
        {
            QString szItemPath(IMAGE_PATH);//
            szItemPath += "/coilwire.png";//
            QImage itemImage(szItemPath);//set items background images in HEX talbe
            ui->progressBar->setRange(0,m_pUDevice->getPageSize()-1);//setup progress bar
            ui->progressBar->setVisible(true);//
            m_pFWItemDelegate->setItemImage1(0,0,itemImage);//
            m_pFWItemDelegate->setItemImage2(0,m_pUDevice->getSize(),itemImage);//
            m_pFWItemDelegate->setItemImage3(m_pUDevice->getSize(),m_pUDevice->getSize(),itemImage);//
            enableMenu(false);//disable main menu for user
            m_progThread.start();//go to thread function in programmer's class
        }
    }
    if(nMBResult == QMessageBox::No)
    {
        MessageBoxWarningOk(PART_BURN_NOT_SUPPORT_TITLE,PART_BURN_NOT_SUPPORT_TEXT);
        return;
    }
}
//Read Firmware from Device
void MainWindow::readDevice()
{
    m_szFirmFormatSave = QString(extract<char*>(m_fwsaveNamespace["fwFormat"])); //Read Firmware Formats from Python script
    m_saveFileDialog.setWindowTitle(tr("Сохранить файл прошивки"));
    m_saveFileDialog.setNameFilter(m_szFirmFormatSave); //set filename filter
    m_saveFileDialog.setFixedSize(600,300);//set dialog window size
    m_saveFileDialog.setOptions(QFileDialog::DontUseNativeDialog);//use own dialog style
    m_saveFileDialog.setViewMode(QFileDialog::Detail);//
    m_saveFileDialog.setDirectory("/");//home directory
    QString szCurrentFilter = m_saveFileDialog.selectedNameFilter();//
    m_pFileSaveProxyModel->setFileFilter(szCurrentFilter.mid(szCurrentFilter.indexOf("."),szCurrentFilter.indexOf(")")-szCurrentFilter.indexOf(".")));//
    m_pFileSaveProxyModel->resetModel();//reload model
    m_saveFileDialog.setProxyModel(m_pFileSaveProxyModel);//set proxy model with new filter
    m_saveFileDialog.setAcceptMode(QFileDialog::AcceptSave);//
    if(m_saveFileDialog.exec())
        m_szFirmFile = m_saveFileDialog.selectedFiles()[0];//firmware filename
    m_bSaveFirmData = true;
    if(m_szFirmFile.isEmpty()) //if firmware filename empty then read firmware without saving
    {
        if(MessageBoxWarningNoYes(NO_FIRMWARE_SAVE_TITLE,NO_FIRMWARE_SAVE_TEXT) == QMessageBox::Yes)
            m_bSaveFirmData = false;
        else
            return;
    }
    ui->tabWidget->setCurrentWidget(ui->tab_2);//current tab is tab_2
    m_pUDevice->init(); //initialize Programmer
    int nMBResult = MessageBoxWarningYesNo(DEVICE_INIT_TITLE,DEVICE_INIT_READ_TEXT);
    if(nMBResult == QMessageBox::Yes)
    {
        if(!m_pUDevice->checkInfo()) //check device info
        {
            QString szDevInfo = "0x" + QString("%1").arg(m_pUDevice->getInfo().byte0,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte1,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte2,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte3,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte4,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte5,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte6,0,16).toUpper()\
                    + " 0x" + QString("%1").arg(m_pUDevice->getInfo().byte7,0,16).toUpper();
            if(MessageBoxWarningYesNo(DEVICE_NOT_FOUND_TITLE,QString(DEVICE_NOT_FOUND_TEXT_B + szDevInfo + DEVICE_NOT_FOUND_TEXT_E)) == QMessageBox::Yes)
            {
                QString szItemPath(IMAGE_PATH);
                szItemPath += "/coilwire.png";
                QImage itemImage(szItemPath);//set background image to item in HEX table
                ui->progressBar->setRange(0,m_pUDevice->getSize()-1);//setup progress bar
                ui->progressBar->setVisible(true);
                m_pFWItemDelegate->setItemImage1(0,0,itemImage);//
                m_pFWItemDelegate->setItemImage2(0,m_pUDevice->getSize(),itemImage);//
                m_pFWItemDelegate->setItemImage3(m_pUDevice->getSize(),m_pUDevice->getSize(),itemImage);//
                enableMenu(false);//disable user's main menu
                m_pUDevice->readFull();//read full firmware from device full memory
                m_progThread.start(); //run programmer's thread
            }
            else
            {
                return;
            }
        }
        else
        {
            QString szItemPath(IMAGE_PATH);
            szItemPath += "/coilwire.png";
            QImage itemImage(szItemPath);//set background image to item in HEX table
            ui->progressBar->setRange(0,m_pUDevice->getSize()-1);//setup progress bar
            ui->progressBar->setVisible(true);
            m_pFWItemDelegate->setItemImage1(0,0,itemImage);
            m_pFWItemDelegate->setItemImage2(0,m_pUDevice->getSize(),itemImage);
            m_pFWItemDelegate->setItemImage3(m_pUDevice->getSize(),m_pUDevice->getSize(),itemImage);//
            enableMenu(false);//disable user's main menu
            m_pUDevice->readFull();//read full firmware from device full memory
            m_progThread.start(); //run programmer's thread
        }
    }
}
//Clear firmware filename & data and setup Device's interface
bool MainWindow::setupDevice()
{
    m_fwDataWrite.clear();
    m_szFirmFile.clear();
    QString szSetupResult = m_pUDevice->setupInterface(m_pMenuInterface);
    if(!szSetupResult.isEmpty())
    {
        MessageBoxCriticalOk(INTERFACE_SETUP_ERROR_TITLE,szSetupResult);
        return 0;
    }
    return 1;
}
//Get DataSheet (with path in JSON file) for current device from WebSite or from local storage
void MainWindow::getDataSheet()
{
    QRegExp regExp("[A-Z]:/");
    setCursor(QCursor(Qt::ArrowCursor));//disable HREF when access item in submenu
    m_pHFComboBox->enableSubMenu(false);
    m_pHFComboBox_2->enableSubMenu(false);
    m_pHFComboBox_3->enableSubMenu(false);
    if(!m_szDataSheetPath.isEmpty())
    {
        regExp.indexIn(m_szDataSheetPath);//open URL like a WebSite in browser
        if(m_szDataSheetPath.mid(0,4) == "http" || m_szDataSheetPath.mid(0,4) == "ftp")
            QDesktopServices::openUrl(QUrl(m_szDataSheetPath,QUrl::TolerantMode));
        else if(m_szDataSheetPath.mid(0,2) == regExp.cap(0))
        {
            QString szFilePath("file:///"); //if 'file:///' prefix used, then open URL like a simple TXT or PDF file in OS
            szFilePath += m_szDataSheetPath;
            QUrl fileUrl(szFilePath,QUrl::TolerantMode);
            QDesktopServices::openUrl(fileUrl);
        }
        else
            MessageBoxWarningOk(DATASHEET_NOT_FOUND_TITLE,DATASHEET_NOT_FOUND_TEXT);
    }
    else
    {
        MessageBoxWarningOk(DATASHEET_NOT_FOUND_TITLE,DATASHEET_NOT_FOUND_PATH_TEXT);
    }
}
//Get Manufacture info (with path in JSON file) for current divices from WebSize or from local storage
void MainWindow::getManufactureInfo()
{
    QRegExp regExp("[A-Z]:/");
    setCursor(QCursor(Qt::ArrowCursor));//disable HREF when access item in submenu
    m_pHFComboBox->enableSubMenu(false);
    m_pHFComboBox_2->enableSubMenu(false);
    m_pHFComboBox_3->enableSubMenu(false);
    if(!m_szManInfoPath.isEmpty())
    {
        regExp.indexIn(m_szManInfoPath);//open URL like a WebSite in browser
        if(m_szManInfoPath.mid(0,4) == "http" || m_szManInfoPath.mid(0,4) == "ftp")
            QDesktopServices::openUrl(QUrl(m_szManInfoPath,QUrl::TolerantMode));
        else if(m_szManInfoPath.mid(0,2) == regExp.cap(0))
        {
            QString szFilePath("file:///"); //if 'file:///' prefix used, then open URL like a simple TXT or PDF file in OS
            szFilePath += m_szManInfoPath;
            QUrl fileUrl(szFilePath,QUrl::TolerantMode);
            QDesktopServices::openUrl(fileUrl);
        }
        else
            MessageBoxWarningOk(MANINFO_NOT_FOUND_TITLE,MANINFO_NOT_FOUND_TEXT);
    }
    else
    {
        MessageBoxWarningOk(MANINFO_NOT_FOUND_TITLE,MANINFO_NOT_FOUND_PATH_TEXT);
    }
}
//Open tab with schematics image
void MainWindow::getSchematics()
{
    setCursor(QCursor(Qt::ArrowCursor));//disable HREF when access item in submenu
    m_pHFComboBox->enableSubMenu(false);
    m_pHFComboBox_2->enableSubMenu(false);
    m_pHFComboBox_3->enableSubMenu(false);
    ui->tabWidget->setCurrentWidget(ui->tab_3);
}
//Open schematics pixmap in system's picture viewer
void MainWindow::getSchematicsPixmap()
{
    setCursor(QCursor(Qt::ArrowCursor));//disable HREF when access item in submenu
    m_pHFLabel->enableSubMenu(false);
    if(!m_szSchematicPath.isEmpty() && !m_schemPixmap.isNull())
    {
        //m_szSchematicPath = QString("file:///") + m_szSchematicPath;
        //qDebug() << "file URL : " << m_szSchematicPath;
        QUrl fileUrl(m_szSchematicPath,QUrl::TolerantMode);
        QDesktopServices::openUrl(fileUrl);
    }
}
//Disable submenu's HREFs when changing tab when user in submenu
void MainWindow::on_tabWidget_currentChanged(int index)
{
    setCursor(QCursor(Qt::ArrowCursor));
    m_pHFComboBox->enableSubMenu(false);
    m_pHFComboBox_2->enableSubMenu(false);
    m_pHFComboBox_3->enableSubMenu(false);
}
