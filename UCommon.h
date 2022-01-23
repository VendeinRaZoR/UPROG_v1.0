/*#############################################################*/
/*######################====UCOMMON====########################*/
/*#############################################################*/
/*Description:
UCOMMON contains common defines and inline functions that often
necessary
*/
#ifndef UCOMMON_H
#define UCOMMON_H

#include <QString>
#include <QMessageBox>
#include "UProgBase.h"
#include "Device/UDevice/UDevice/UDevice.h"
#include "UControlBase.h"

#define ROOT "../" //"../"

#define JSON_PATH ROOT"json"
#define IMAGE_PATH ROOT"images"
#define PYTHON_PATH "/python"
//Message boxes that often are used for dialog with user
inline void MessageBoxCriticalOk(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxCritical(QMessageBox::Critical,szTitle,szText,QMessageBox::Ok);
    MessageBoxCritical.exec();
}

inline void MessageBoxWarningOk(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxWarning(QMessageBox::Warning,szTitle,szText,QMessageBox::Ok);
    MessageBoxWarning.exec();
}

inline void MessageBoxInfoOk(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxInfo(QMessageBox::Information,szTitle,szText,QMessageBox::Ok);
    MessageBoxInfo.exec();
}

inline int MessageBoxCriticalYesNo(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxCritical(QMessageBox::Critical,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxCritical.setDefaultButton(QMessageBox::Yes);
    return MessageBoxCritical.exec();
}

inline int MessageBoxWarningYesNo(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxWarning(QMessageBox::Warning,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxWarning.setDefaultButton(QMessageBox::Yes);
    return MessageBoxWarning.exec();
}

inline int MessageBoxInfoYesNo(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxInfo(QMessageBox::Information,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxInfo.setDefaultButton(QMessageBox::Yes);
    return MessageBoxInfo.exec();
}

inline int MessageBoxCriticalNoYes(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxCritical(QMessageBox::Critical,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxCritical.setDefaultButton(QMessageBox::No);
    return MessageBoxCritical.exec();
}

inline int MessageBoxWarningNoYes(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxWarning(QMessageBox::Warning,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxWarning.setDefaultButton(QMessageBox::No);
    return MessageBoxWarning.exec();
}

inline int MessageBoxInfoNoYes(const QString& szTitle,const QString& szText)
{
    QMessageBox MessageBoxInfo(QMessageBox::Information,szTitle,szText,QMessageBox::Yes | QMessageBox::No);
    MessageBoxInfo.setDefaultButton(QMessageBox::No);
    return MessageBoxInfo.exec();
}

#endif // UCOMMON_H
