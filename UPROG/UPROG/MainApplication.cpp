/*####################################################################*/
/*######################====MAIN APPLICATION====######################*/
/*####################################################################*/
/*Description:
    UPROG Universal Programmer's QT Main Application class
*/
#include "MainApplication.h"
//Start initialize application with this constructor
MainApplication::MainApplication(int &argc, char **argv):QApplication(argc,argv)
{
    m_nArgc = argc;
    m_szArgv = argv;
    qDebug() << "Application Init...";
}
//cleanup
MainApplication::~MainApplication()
{

}
//May be useful for catching some errors like python errors, but not used anymore
bool MainApplication::notify(QObject * receiver, QEvent * e)
{
    return QApplication::notify(receiver,e);
}
