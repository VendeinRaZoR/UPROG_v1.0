/*###############################################################*/
/*######################====MAIN WINDOW====######################*/
/*###############################################################*/
/*Description:
UPROG Universal Programmer's Main Window class
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QThread>
#include <QVBoxLayout>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDesktopServices>
#include <QtGlobal>
#include <QPalette>
#include <QDebug>
#include "QPython2.h"
#include "MenuBuilder.h"
#include "../../UCommon.h"
#include "submenu/HFComboBox.h"
#include "submenu/HFLabel.h"
#include "filedialog/FileFilterProxyModel.h"
#include "fwtable/FWTableModel.h"
#include "fwtable/FWItemDelegate.h"
#include "fwtable/FWTableView.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    UProgBase *m_pUDevice;
    UDeviceCommon m_DeviceCommon;
private:
    QString m_szFirmFile;
    QString m_szFirmFormatLoad;
    QString m_szFirmFormatSave;
    QString m_szDataSheetPath;
    QString m_szSchematicPath;
    QString m_szManInfoPath;
    QVector<unsigned long> m_fwDataWrite;
private:
    QPython *m_pPythonInterpreter;
    boost::python::object m_mainModule;
    boost::python::object m_mainNamespace;
    boost::python::object m_fwloadModule;
    boost::python::object m_fwloadNamespace;
    boost::python::object m_fwsaveModule;
    boost::python::object m_fwsaveNamespace;
private:
    QThread m_progThread;
private:
    MenuBuilder* m_pMenuDevice;
    MenuBuilder* m_pMenuInterface;
private:
    QVector<QJsonObject> *m_pJsonObjList;
    QJsonObject m_jsonDev;
    QJsonObject m_jsonIntf;
    QJsonObject m_jsonDevMenu;
    QJsonObject m_jsonIntfMenu;
private:
    QLabel *m_pManLabel;
    HFComboBox *m_pHFComboBox;
    QLabel *m_pDevLabel;
    HFComboBox *m_pHFComboBox_2;
    QLabel *m_pIntfLabel;
    HFComboBox *m_pHFComboBox_3;
    HFLabel *m_pHFLabel;
private:
    QFileDialog m_openFileDialog;
    QFileDialog m_saveFileDialog;
private:
    FileFilterProxyModel *m_pFileOpenProxyModel;
    FileFilterProxyModel *m_pFileSaveProxyModel;
private:
    FWTableView *m_pFWTableView;
    QStringList m_fwRow;
    QStringList m_fwCol;
    FWTableModel *m_pFWTableModel;
    FWItemDelegate *m_pFWItemDelegate;
private:
    bool m_bSaveFirmData;
private:
    QPixmap m_schemPixmap;
public:
    MainWindow(QPython *pPythonInterpreter,QVector<QJsonObject> *pJsonObjList,QWidget *parent = 0);//Initialization of menu, python scripts, JSON, python interpreter, window
    void closeEvent(QCloseEvent *event);//Event when closing Main Window
    void connectSlots();//Setting menu's signals and slots
    void setupThreads();//Set thread for programmer
    void setupProgrammer();//Setup or Reconnect signals and slots when changing Device (IC)
    void setupHEXTable();//Setup Model-View-Delegate of HEX table window
    void updateHEXTable();//Update HEX Table Model with Data
    void updateManList();//Update Main Menu Manufactures List from JSON files objects
    void updateDevMenu();//Update & Build Device's menu from JSON file object
    void updateIntfMenu();//Update & Build Interface menu for this Device
    void updateDevList();//Update Main Menu Manufacture's Devices List from JSON files objects
    void updateProxyModel(const QString& filter);//Update File Dialogs Proxy Models with current filter
    void updateProgressBar(int nProgress);//Update Progress Bar & Firmware Download Progress
    void enableMenu(bool bEnabled);//Enable/Disable Menu Controls (Blocking user interact with main menu)
    ~MainWindow();//UPROG destructor
private:
    void readDevice();//Read Firmware from Device
    void writeDevice();//Write Firmware into Device
    bool setupDevice();//Clear firmware filename & data and setup Device's interface

public slots:
    void writeDone();//Write Done event when programmer's device writing process done
    void readDone();//Read Done event when programmer's device reading process done
    void writeError();//Write Error event when error detected in Device firmware writing process
    void readError();//Read Error event when error detected in Device firmware reading process
    void error(int nLastError);//Error event when programmer fail Device recognize
    void on_pushButton_2_pressed();//Device read firmware push button
    void on_pushButton_pressed();//Device write firmware push button

    void getDataSheet();//Get DataSheet (with path in JSON file) for current device from WebSite or from local storage
    void getManufactureInfo();//Get Manufacture info (with path in JSON file) for current divices from WebSize or from local storage
    void getSchematics();//Open tab with schematics image
    void getSchematicsPixmap();//Open schematics pixmap in system's picture viewer
    void keyPressEvent(QKeyEvent *vk);//Ctrl Key Press Event first & second times
    void keyReleaseEvent(QKeyEvent *vk);//Key Release Event (Reserved)
    void mouseReleaseEvent(QMouseEvent *vm);//Event when mouse button is already released

public slots:
    void on_hfcomboBox_3_currentIndexChanged(const QString &arg1);//Update Menu when Interface comboBox item changed
    void on_hfcomboBox_2_currentIndexChanged(const QString &arg1);//Update Menu when Device's comboBox item changed
    void on_hfcomboBox_currentIndexChanged(const QString &arg1);//Update Menu when Manufacture's comboBox item changed

private slots:
    void on_tabWidget_currentChanged(int index);//Disable submenu's HREFs when changing tab when user in submenu

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
