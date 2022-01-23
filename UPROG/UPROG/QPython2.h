/*###########################################################*/
/*######################====QPYTHON====######################*/
/*###########################################################*/
/*Description:
    QPython class is wrapper class over Boost::Python library using
    QT library classes and functions and python 2 library
    It implements useful and necessary features such as helpful scripts,
    type convertors (into and from python), wrapper functions and others
    that needed when application use python library
*/
#ifndef QPYTHON2_H
#define QPYTHON2_H

//#include <Python.h>
//#include <boost/python/detail/wrap_python.hpp>
#include <boost/python.hpp>
#include <boost/python/call.hpp>
#include <boost/log/exceptions.hpp>
//#include <vector>
#include <QObject>
#include <QList>
#include <QMap>
#include <QVector>
#include "../../UCommon.h"

#define NONE_TYPE(obj) obj.ptr() == Py_None ? 1 : 0
//Python's STDOUT catch into QT console output
#define PYTHON_STDOUT_CATCHER "import sys\n\
class CatchOutErr:\n\
    \tdef __init__(self):\n\
        \tself.value = ''\n\
    \tdef write(self, txt):\n\
        \tself.value += txt\n\
if __name__ == '__main__':\n\
    \tcatchOutErr = CatchOutErr()\n\
    \tsys.stdout = catchOutErr\n\
   \tsys.stderr = catchOutErr"
//Set path to python's modules directory
#define PYTHON_SET_PATH "import sys\n\
import os\n\
sys.path.insert(1,os.path.abspath(os.getcwd()) + '"PYTHON_PATH"')"
//Convert types into python script
template<typename T> struct TypeIntoPython
{
    static PyObject *convert(T);
};
//Convert types from python script
template<typename T> struct TypeFromPython
{
    static T convert(PyObject*);
};
//QPython class inherited from QObject and uses QT library
class QPython : public QObject
{
    PyObject *m_pPyCatcher;
    boost::python::object m_mainModule;
    boost::python::object m_mainNamespace;
public:
    QPython();//Python Initialization (Interpreter and other necessary functions)
    QPython(QPython &);//reserved
    ~QPython();//cleanup
    void ErrorMessage();//Print python's script error message to console
    void Init();//Separate python interpreter initialization function
    void Release();//Separate function to finalize interpreter
    void showOutput();//Necessarily to call this funciton to show python's output to QT console
    bool isInit();//Check if interpreter initialized
public:
    ////////////////////////////////////////////////////////////////////
};

#endif // QPYTHON2_H
