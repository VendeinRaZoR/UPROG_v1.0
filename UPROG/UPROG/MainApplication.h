/*####################################################################*/
/*######################====MAIN APPLICATION====######################*/
/*####################################################################*/
/*Description:
    UPROG Universal Programmer's QT Main Application class
*/
#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <QApplication>
#include <QDebug>

class MainApplication : public QApplication
{
    int m_nArgc;
    char **m_szArgv;
public:
    MainApplication(int &argc, char **argv); //Start initialize application with this constructor
    ~MainApplication(); //cleanup
    bool notify(QObject * receiver, QEvent * e); //Not used anymore
};

#endif // MAINAPPLICATION_H
