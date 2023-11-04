#pragma once
#include "ui_TuringMachine.h"
#include <QMainWindow>

#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QMessageBox>

#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 100

class TuringMachine : public QMainWindow
{
    Q_OBJECT

public:
    bool exitRuler = false;
    string turingRuler;
    string paper;
    vector<string> turingRulerList;
    char rulers[MAXSIZE][5];
    char state;
    int rulersLen = 0;
    int paperPtr;
    void readRuler(string& turingRuler);
    void printPaper();
    void checkPaper();
    QStandardItemModel * listModel = new QStandardItemModel;
    TuringMachine(QWidget *parent = nullptr);
    ~TuringMachine();
    


public slots:
    void loadRuler();
    void inputPaper();
    void move();

private:
    Ui_TuringMachine *ui;
};
