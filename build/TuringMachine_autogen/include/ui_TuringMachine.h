/********************************************************************************
** Form generated from reading UI file 'TuringMachine.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TURINGMACHINE_H
#define UI_TURINGMACHINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TuringMachine
{
public:
    QWidget *centralwidget;
    QPushButton *loadButton;
    QListView *rulerView;
    QTextEdit *textEdit;
    QListView *listView;
    QPushButton *continueButton;
    QLineEdit *lineEdit;
    QPushButton *startButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TuringMachine)
    {
        if (TuringMachine->objectName().isEmpty())
            TuringMachine->setObjectName(QString::fromUtf8("TuringMachine"));
        TuringMachine->resize(800, 600);
        TuringMachine->setMinimumSize(QSize(800, 600));
        TuringMachine->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(TuringMachine);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(20, 20, 201, 41));
        rulerView = new QListView(centralwidget);
        rulerView->setObjectName(QString::fromUtf8("rulerView"));
        rulerView->setGeometry(QRect(20, 70, 201, 461));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(230, 20, 551, 131));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(230, 160, 551, 321));
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(670, 490, 111, 41));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 490, 311, 41));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(550, 490, 111, 41));
        TuringMachine->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TuringMachine);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        TuringMachine->setMenuBar(menubar);
        statusbar = new QStatusBar(TuringMachine);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TuringMachine->setStatusBar(statusbar);

        retranslateUi(TuringMachine);

        QMetaObject::connectSlotsByName(TuringMachine);
    } // setupUi

    void retranslateUi(QMainWindow *TuringMachine)
    {
        TuringMachine->setWindowTitle(QCoreApplication::translate("TuringMachine", "TuringMachine", nullptr));
        loadButton->setText(QCoreApplication::translate("TuringMachine", "\350\275\275\345\205\245\350\247\204\345\210\231", nullptr));
        textEdit->setHtml(QCoreApplication::translate("TuringMachine", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\275\277\347\224\250\350\247\204\345\210\231\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1\344\273\243\350\241\250\345\210\235\345\247\213\347\212\266\346\200\201\357\274\214#\344\273\243\350\241\250\347\273\210\346\255\242\347\212\266\346\200\201\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">a,b,c,d,e\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\241\250\347\244\272a\347\212\266\346\200\201\344\270\213\350\257\273\345\217\226b\345\260\206\350\275\254\347\247\273\350\207\263c\347\212\266\346\200\201\345\206\231\345\205\245d\345\271\266\345\220\221e\346\226\271\345\220\221\347\247\273\345\212\250\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">L\344\273\243\350\241\250\345\267\246\357\274\214R\344\273\243\350\241\250\345\217\263\343\200\202</p></body></html>", nullptr));
        continueButton->setText(QCoreApplication::translate("TuringMachine", "\347\273\247\347\273\255", nullptr));
        lineEdit->setText(QCoreApplication::translate("TuringMachine", "(\350\276\223\345\205\245\347\272\270\345\270\246)", nullptr));
        startButton->setText(QCoreApplication::translate("TuringMachine", "\345\220\257\345\212\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TuringMachine: public Ui_TuringMachine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TURINGMACHINE_H
