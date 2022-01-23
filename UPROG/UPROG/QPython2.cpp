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

#include "QPython2.h"

using namespace boost::python; //using Boost::Python namespace
//Template realization of convertion QList to python's list type
template <> PyObject *TypeIntoPython<QList<unsigned long>>::convert(QList<unsigned long> qList)
{
    PyObject* pPyList = PyList_New(NULL);
    for(int i=0;i<qList.length();i++)
        PyList_Append(pPyList,PyInt_FromLong(qList[i]));
    return pPyList;
}
//Template realization of convertion QVector to python's list type
template <> PyObject *TypeIntoPython<QVector<unsigned long>>::convert(QVector<unsigned long> qVector)
{
    PyObject* pPyVector = PyList_New(NULL);
    for(int i=0;i<qVector.size();i++)
        PyList_Append(pPyVector,PyInt_FromLong(qVector[i]));
    return pPyVector;
}
//Template realization of convertion QString to python's str type
template <> PyObject *TypeIntoPython<QString>::convert(QString qStr)
{
    QByteArray utf8String = qStr.toUtf8();
    char *utf8Array = new char[utf8String.length()];
    for(int i=0;i<utf8String.length();i++)
        utf8Array[i] = utf8String[i];
    PyObject* pPyUString = PyString_Decode(utf8Array,qStr.length(),"utf-8","");//Python string in UTF-8
    return pPyUString;
}
//Template realization of convertion python's list to QList type
template <> QList<unsigned long> TypeFromPython<QList<unsigned long>>::convert(PyObject *pPyObject)
{
    QList<unsigned long>data;
    if (PyList_Check(pPyObject))
    {
        for(Py_ssize_t i = 0; i < PyList_Size(pPyObject); i++)
        {
            PyObject *value = PyList_GetItem(pPyObject, i);
            data.push_back( PyFloat_AsDouble(value));
        }
    }
    else
    {
       throw std::logic_error("Passed PyObject pointer was not a list!");
    }
    return data;
}
//Template realization of convertion python's list to QVector type
template <> QVector<unsigned long> TypeFromPython<QVector<unsigned long>>::convert(PyObject *pPyObject)
{
    QVector<unsigned long>data;
    if (PyList_Check(pPyObject))
    {
        for(Py_ssize_t i = 0; i < PyList_Size(pPyObject); i++)
        {
            PyObject *value = PyList_GetItem(pPyObject, i);
            data.push_back( PyFloat_AsDouble(value));
        }
    }
    else
    {
       throw std::logic_error("Passed PyObject pointer was not a list!");
    }
    return data;
}
//Python Initialization (Interpreter and other necessary functions)
QPython::QPython()
{
    Py_Initialize();
    m_mainModule = import("__main__");
    m_mainNamespace = m_mainModule.attr("__dict__");
    exec(PYTHON_STDOUT_CATCHER,m_mainNamespace,m_mainNamespace);//Run console output stream catcher script
    exec(PYTHON_SET_PATH,m_mainNamespace,m_mainNamespace);//Run python script that sets python modules directory
    m_pPyCatcher = PyObject_GetAttrString(m_mainModule.ptr(),"catchOutErr"); //Get string variable assigned to python's stdout
    to_python_converter<QList<unsigned long>,TypeIntoPython<QList<unsigned long>>>();//Register convertions
    to_python_converter<QVector<unsigned long>,TypeIntoPython<QVector<unsigned long>>>();//
    to_python_converter<QString,TypeIntoPython<QString>>();//
    qDebug() << "Python was Initialized...\n";//Proper Initialization Python indicator
}
//reserved
QPython::QPython(QPython&)
{
    //reserved
}
//cleanup
QPython::~QPython()
{
   // if(Py_IsInitialized())
      //  Py_Finalize(); //optional finalization interpreter
}
//Separate python interpreter initialization function
void QPython::Init()
{
    Py_Initialize();
}
//Check if interpreter initialized
bool QPython::isInit()
{
    return Py_IsInitialized();
}
//Print python's script error message to console
void QPython::ErrorMessage()
{
    PyErr_Print();
}
//Necessarily to call this funciton to show python's output to console
//after every python script that outputs messages
void QPython::showOutput()
{
    qDebug() << PyString_AsString(PyObject_GetAttrString(m_pPyCatcher,"value"));
}
//Separate function to finalize interpreter
void QPython::Release()
{
    Py_Finalize();
}

