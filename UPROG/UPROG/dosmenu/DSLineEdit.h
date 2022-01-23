#ifndef DSLINEEDIT_H
#define DSLINEEDIT_H

#include <QLineEdit>

class DSLineEdit : public QLineEdit
{
public:
    DSLineEdit(QWidget *parent = 0);
    DSLineEdit(const QString &, QWidget *parent = 0);
};

#endif // DSLINEEDIT_H
