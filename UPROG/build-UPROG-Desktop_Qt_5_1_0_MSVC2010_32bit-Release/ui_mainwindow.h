/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFdgd;
    QAction *actionOPen;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QFrame *frame;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QFrame *frame_4;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *tab_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(421, 316);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(421, 316));
        MainWindow->setMaximumSize(QSize(421, 316));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("QTabWidget::pane {\n"
"    background: rgba(200,200,200,100);\n"
"	border:2;\n"
"	border-style:dashed;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"	    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 gold, stop: 0.4 white,\n"
"                                stop: 0.5 gold, stop: 1.0 gold);\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}\n"
"\n"
"QFrame#frame{\n"
"	color:white;\n"
"	background-color:green;\n"
"	border-radius: 5px;\n"
"	border-style: solid;\n"
"	border-width:2px;\n"
"	border-color:gray;\n"
"}\n"
"\n"
"QFrame#frame_2{\n"
"	color:white;\n"
"	background-color:green;\n"
"	border-radius: 5px;\n"
"	border-style: solid;\n"
"	border-width:2px;\n"
"	border-color:gray;\n"
"}\n"
"\n"
"QFrame#frame_3{\n"
"	background: rgba(169,169,169,150);\n"
""
                        "	border-radius: 5px;\n"
"}\n"
"\n"
"QFrame#frame_4{\n"
"	background: rgba(169,169,169,150);\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background-color: blue;\n"
"    border: 2px solid white;\n"
"    border-radius: 0px;\n"
"    margin-top: 2ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	font: bold \"Times New Roman\";\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center; \n"
"    padding: 0 3px;\n"
"    background-color: blue;\n"
"	color:yellow;\n"
"	border: 2px solid white;\n"
"	margin-top: 1ex;\n"
"}\n"
"\n"
"QMainWindow{\n"
"	background-image: url(\"../images/background.jpg\");\n"
"	background-position:center;\n"
"}\n"
"\n"
"QProgressBar{\n"
"	font-family:\"Terminal\";\n"
"	border: 2px solid grey;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QProgressBar::chunk{\n"
"	background-color: gold;\n"
"	width: 10px;\n"
"	margin: 0.5px;\n"
"}\n"
"\n"
"QTableView{\n"
"	selection-background-color: rgb(255,137,39);\n"
"	gridline-color:rgb(255,137,39);\n"
"}\n"
"\n"
"::section{\n"
"	backgro"
                        "und-color:rgb(255,137,39);\n"
"}\n"
"\n"
"QStatusBar{\n"
"   background-color:rgba(255,255,255,200);\n"
"}\n"
"\n"
"QScrollBar{\n"
"		background-color:rgb(255,137,39);\n"
"}"));
        MainWindow->setAnimated(true);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionFdgd = new QAction(MainWindow);
        actionFdgd->setObjectName(QStringLiteral("actionFdgd"));
        actionOPen = new QAction(MainWindow);
        actionOPen->setObjectName(QStringLiteral("actionOPen"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(false);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 403, 281));
        tabWidget->setMaximumSize(QSize(408, 16777215));
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setEnabled(true);
        tab->setAutoFillBackground(false);
        tab->setStyleSheet(QStringLiteral(""));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(7, 10, 391, 241));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 5, 0);
        frame_3 = new QFrame(horizontalLayoutWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(190, 0));
        frame_3->setMaximumSize(QSize(180, 16777215));
        frame_3->setStyleSheet(QLatin1String("QLabel{\n"
"	font: \"Times New Roman\";\n"
"	color:black;\n"
"}\n"
"\n"
"QWidget#widgetEdit{\n"
"	background: rgba(118,220,200,100);\n"
"	background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #dcdcdc,\n"
"                                stop: 0.5 #dcdcdc, stop: 1.0 #fafafa);\n"
"	border-radius: 5px;\n"
"	border-style: solid;\n"
"	border-width:2px;\n"
"}\n"
"\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame = new QFrame(frame_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(5, 10, 180, 101));
        frame->setStyleSheet(QLatin1String("QLabel{\n"
"	color:white;\n"
"	font: bold italic large \"Courier New\";\n"
"	font-size:19px;\n"
"}\n"
"\n"
"QComboBox{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	background-color:black;\n"
"	color:white;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:4px;\n"
"	padding-left: 5px;\n"
"}\n"
"\n"
"QComboBox:hover{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	color:white;\n"
"	background-color: grey;\n"
"	border-width:2px;\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border-style:none;\n"
"	width:20px;\n"
"	image:url(\"images/dropdown.png\");\n"
"}\n"
"\n"
"QComboBox::drop-down:hover{\n"
"}\n"
"\n"
"QComboBox:disabled{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	background-color:green;\n"
"	color:gray;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:4px;\n"
"	padding-left: 5px;\n"
"}\n"
"\n"
"QPushButton{\n"
"	background-color: rgb(118,200,50);\n"
"	border-style: outset;\n"
""
                        "	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(118,250,50);\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(118,200,50);\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton:disabled{\n"
"    background-color:green;\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton#pushButton_2{\n"
"	background-color: rgb(200,0,0);\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover{\n"
"	background-color: rgb(250,0,0);\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton#pushButton_2:pressed{\n"
"	backgroun"
                        "d-color: rgb(200,0,0);\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"}\n"
"\n"
"QPushButton#pushButton_2:disabled{\n"
"	background-color: green;\n"
"	border-style: outset;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:8px;\n"
"	color:gray;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 1, 161, 93));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Courier New"));
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(70, 20));
        pushButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(70, 20));
        pushButton_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);
        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 171, 111));
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"	border-radius: 0px;\n"
"	border-style: none;\n"
"	border-width:0px;	\n"
"	border-color:white;\n"
"	background-color:blue;\n"
"	color:white;\n"
"    font-family: \"Terminal\";\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"    font-family: \"Terminal\";\n"
"}\n"
"\n"
"QRadioButton{\n"
"	color:white;\n"
"	border-style: none;\n"
"    font-family: \"Terminal\";\n"
"	color:white;\n"
"}\n"
"\n"
"QRadioButton::indicator:uncheked{\n"
"		image: url(\"images/radiooff.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:cheked{\n"
"		image: url(\"images/radioon.png\");\n"
"}"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);

        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(horizontalLayoutWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setEnabled(true);
        frame_4->setMinimumSize(QSize(190, 0));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setStyleSheet(QLatin1String("QLabel{\n"
"	font: \"Times New Roman\";\n"
"	color:black;\n"
"}\n"
"\n"
"QWidget#widgetEdit{\n"
"	background: rgba(118,220,200,100);\n"
"	background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #dcdcdc,\n"
"                                stop: 0.5 #dcdcdc, stop: 1.0 #fafafa);\n"
"	border-radius: 5px;\n"
"	border-style: solid;\n"
"	border-width:2px;\n"
"}\n"
""));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(5, 10, 180, 101));
        frame_2->setStyleSheet(QLatin1String("QLabel{\n"
"	color:white;\n"
"	font: bold italic large \"Courier New\";\n"
"	font-size:19px;\n"
"}\n"
"\n"
"QComboBox{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	background-color:black;\n"
"	color:white;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:4px;\n"
"	padding-left: 5px;\n"
"}\n"
"\n"
"QComboBox:hover{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	color:white;\n"
"	background-color: grey;\n"
"	border-width:2px;\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border-style:none;\n"
"	width:20px;\n"
"	image:url(\"images/dropdown.png\");\n"
"}\n"
"\n"
"QComboBox::drop-down:hover{\n"
"}\n"
"\n"
"QComboBox:disabled{\n"
"	border-style: dashed;\n"
"	border-color: white;\n"
"	background-color:green;\n"
"	color:gray;\n"
"	border-width:2px;\n"
"	border-color:beige;\n"
"	border-radius:4px;\n"
"	padding-left: 5px;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_4 = new QWidget(frame_2);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 0, 161, 91));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(frame_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 120, 171, 111));
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        groupBox->setFont(font2);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QLatin1String("QRadioButton{\n"
"	color:white;\n"
"	border-style: none;\n"
"    font-family: \"Terminal\";\n"
"	color:white;\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"    font-family: \"Terminal\";\n"
"}"));

        horizontalLayout->addWidget(frame_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayoutWidget = new QWidget(tab_2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, 0, 401, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayoutWidget_2 = new QWidget(tab_3);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(-1, -1, 401, 271));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab_3, QString());
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(343, 276, 69, 16));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\243\320\275\320\270\320\262\320\265\321\200\321\201\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\276\321\200 UProg 1.0", 0));
        actionFdgd->setText(QApplication::translate("MainWindow", "fdgd", 0));
        actionOPen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        actionClose->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\210\320\270\320\262\320\272\320\260", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\276\321\200\320\260", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\274\320\270\320\272\321\200\320\276\321\201\321\205\320\265\320\274\321\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260\321\202\320\276\321\200", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\260 \320\277\320\260\320\274\321\217\321\202\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\241\321\205\320\265\320\274\320\260 \320\277\321\200\320\270\320\275\321\206\320\270\320\277\320\270\320\260\320\273\321\214\320\275\320\260\321\217", 0));
        progressBar->setFormat(QApplication::translate("MainWindow", "%p%", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
