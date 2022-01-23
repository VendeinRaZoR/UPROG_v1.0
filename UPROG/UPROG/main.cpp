/*########################################################*/
/*######################====MAIN====######################*/
/*########################################################*/
/*Description:
Main funciton, JSON file open functions,
main window init, app init and other
*/
#include "QPython2.h"
#include "mainwindow.h"
#include "MainApplication.h"
#include <QMessageBox>
#include <QString>
#include <cstdlib>
#include <QWidget>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDebug>
#include "../../UCommon.h"

using namespace boost::python; //Using Boost::Python

//Open directory with JSON files
QFileInfoList jsonOpenDir(QString szDirName)
{
    QDir jsonDir(szDirName);
    QStringList jsonFilter;
    jsonFilter << "*.json";
    return jsonDir.entryInfoList(jsonFilter,QDir::Files);
}
//Open particular JSON file
QJsonObject jsonOpenFile(QString szFileName)
{
    QFile *jsonFile = new QFile(szFileName);
    jsonFile->open(QIODevice::ReadOnly);//open JSON file
    QJsonParseError jsonParseError;//JSON parse error descriptor
    QJsonDocument *pJsonDocument = new QJsonDocument(QJsonDocument::fromJson(jsonFile->readAll(),&jsonParseError));
    if(jsonParseError.error != QJsonParseError::NoError)
      throw jsonParseError;//throw error with description
    return pJsonDocument->object();
}
//Entry point
int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("./");//Path to libraries (DLL)
    MainApplication a(argc, argv);
    a.addLibraryPath("./");//path to libraries (DLL)
    QPython pythonInterpreter; //Boost::Python wrapper using Qt std libraries
    QString szJsonFileName; //Json fileName to open
    QFileInfoList jsonInfoList = jsonOpenDir(JSON_PATH); //List of JSON files in directory
    QVector<QJsonObject> jsonObjList; //List of JSON Objects in JSON files in directory
    try
    {
        for(int i = 0;i<jsonInfoList.length();i++)
        {
            szJsonFileName = jsonInfoList[i].fileName();//fill JSON objects list
            jsonObjList.append(jsonOpenFile(QString(JSON_PATH) + "/" + szJsonFileName));
        }
        MainWindow w(&pythonInterpreter,&jsonObjList);
        w.updateManList(); //Update Manufactures list
        w.updateDevList(); //Update Devices list
        w.updateDevMenu(); //Update Device Menu
        w.updateIntfMenu(); //Update Interface Menu
        w.setupProgrammer(); //setup Programmer's signals and slots
        w.setupThreads(); // move to thread Programmer's thread
        w.setupHEXTable(); //setup HEX table Model-View
        w.connectSlots(); //connect menu's signals and slots
        w.show(); //show UPROG main window
       // g_PythonInterpreter.Release(); //Optional release
        qDebug() << "Application Exec...";
        return a.exec();//run Application
    }
    catch(error_already_set& e) //catch all errors while python parse
    {
       qDebug() << "Python Error : ";
       pythonInterpreter.ErrorMessage(); //Py_Err Print
       pythonInterpreter.showOutput(); //Show Output by Python String Catcher script
       pythonInterpreter.Release(); //Release Python Interpreter
    }
    catch(QJsonParseError& e) //catch all errors while JSON parse
    {
        qDebug() << "JSON File : " << szJsonFileName; //Catch errors in JSON file
        qDebug() << "JSON Error : " << e.errorString() << "\nString Offset : " << e.offset;
    }
    catch(std::logic_error le) //catch all errors in UPROG logic
    {
        qDebug() << le.what();//message into console
    }
}
