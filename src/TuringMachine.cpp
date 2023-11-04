#include "TuringMachine.h"

TuringMachine::TuringMachine(QWidget *parent) : QMainWindow(parent),
                                                ui(new Ui_TuringMachine)
{
    ui->setupUi(this);

    ui->rulerView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setMovement(QListView::Snap);
    ui->textEdit->setReadOnly(true);

    connect(ui->loadButton, &QPushButton::clicked, this, &TuringMachine::loadRuler);
    connect(ui->startButton, &QPushButton::clicked, this, &TuringMachine::inputPaper);
    connect(ui->continueButton, &QPushButton::clicked, this, &TuringMachine::move);
}

TuringMachine::~TuringMachine()
{
    delete ui;
}



void TuringMachine::readRuler(string& turingRuler)
{
    // ifstream file(".\\bin\\ruler.txt");
    ifstream file(".\\ruler.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            turingRuler += line + "\n";
        }
        file.close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Rulers Loading Error!");
        exit(1);
    }
}

void TuringMachine::printPaper()
{
    QString input = "State: q";
    input += state;
    input += ", ";
    for (int i = 0; i < paperPtr; i++)
        input += paper[i];
    input += "->";
    for (int i = paperPtr; i < paper.size(); i++)
        input += paper[i];
    QStandardItem *item = new QStandardItem(input);
    listModel->appendRow(item);
    ui->listView->show();
    ui->listView->scrollToBottom();
}

void TuringMachine::checkPaper()
{
    if (state == '#')
        QMessageBox::information(this, "Readable", "The paper is Readable.");
    if (paperPtr == paper.size())
        paper += 'B';
}

void TuringMachine::loadRuler()
{
    if (!exitRuler)
    {
        readRuler(turingRuler);
        ui->rulerView->setViewMode(QListView::ListMode);
        stringstream strStream(turingRuler);
        string temp;
        for (int i = 0; getline(strStream, temp); i++, rulersLen++)
        {
            turingRulerList.push_back(temp);
            if (rulersLen >= MAXSIZE)
            {
                QMessageBox::warning(this, "Error", "Rulers Length Error!");
                return;
            }
            rulers[i][0] = temp[0];
            rulers[i][1] = temp[2];
            rulers[i][2] = temp[4];
            rulers[i][3] = temp[6];
            rulers[i][4] = temp[8];
        }
        QStandardItemModel * model = new QStandardItemModel;
        for (auto i : turingRulerList)
        {
            QString qTemp(i.c_str());
            QStandardItem *item = new QStandardItem(qTemp);
            model->appendRow(item);
        }
        ui->rulerView->setModel(model);
        ui->rulerView->show();
        exitRuler = true;
    }
    else
    {
        QMessageBox::warning(this, "Error", "Rulers Already Loaded!");
        return;
    }
}

void TuringMachine::inputPaper()
{
    state = '1';
    paperPtr = 0;
    QMessageBox::information(this, "Success!", "Paper Loading Success!");
    QString input = ui->lineEdit->text();
    paper = input.toStdString();
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setModel(listModel);
    printPaper();
}

void TuringMachine::move()
{
    if (!exitRuler)
        return;
    if (state == '#')
    {
        QMessageBox::information(this, "Readable", "The paper is Readable.");
        return;
    }
    int i = 0;
    for (; i < rulersLen; i++)
    {
        if (rulers[i][0] == state && rulers[i][1] == paper[paperPtr])
        {
            state = rulers[i][2];
            paper[paperPtr] = rulers[i][3];
            if (rulers[i][4] == 'L')
                paperPtr--;
            else if (rulers[i][4] == 'R')
                paperPtr++;
            break;
        }
    }
    if (i == rulersLen)
        QMessageBox::information(this, "Unreadable", "The paper is unreadable.");
    else
    {
        printPaper();
        checkPaper();
    }
}
