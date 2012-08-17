#include <QTextStream>
#include <QFileDialog>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stTimer(new QTimer(this)),
    game(new GameWidget(this))
{
    ui->setupUi(this);

    stTimer->setInterval(50);
    stTimer->start();

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startResume()));
    connect(ui->clearButton, SIGNAL(clicked()), game, SLOT(clear()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(setStartResume()));

    connect(ui->iterInterval, SIGNAL(valueChanged(int)), game, SLOT(setInterval(int)));
    connect(ui->cellsControl, SIGNAL(valueChanged(int)), game, SLOT(setCellNumber(int)));

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveGame()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadGame()));

    connect(stTimer, SIGNAL(timeout()), this, SLOT(updateStats()));

    connect(ui->cellsControl, SIGNAL(valueChanged(int)), ui->cellsSlider, SLOT(setValue(int)));
    connect(ui->cellsSlider, SIGNAL(valueChanged(int)), ui->cellsControl, SLOT(setValue(int)));

    connect(ui->iterInterval, SIGNAL(valueChanged(int)), ui->iterSlider, SLOT(setValue(int)));
    connect(ui->iterSlider, SIGNAL(valueChanged(int)), ui->iterInterval, SLOT(setValue(int)));

    QPalette plt;

    plt.setColor(QPalette::WindowText, Qt::gray);
    ui->stAll->setPalette(plt);
    ui->stAllLab->setPalette(plt);

    plt.setColor(QPalette::WindowText, Qt::green);
    ui->stGreen->setPalette(plt);
    ui->stGreenLab->setPalette(plt);

    plt.setColor(QPalette::WindowText, Qt::red);
    ui->stRed->setPalette(plt);
    ui->stRedLab->setPalette(plt);

    ui->mainLayout->setStretchFactor(ui->gameLayout, 9);
    ui->mainLayout->setStretchFactor(ui->setLayout, 1);
    ui->gameLayout->addWidget(game);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveGame()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save current game"),
                                                    QDir::homePath(),
                                                    tr("Evolution files (*.evol)"));
    if(filename.length() < 1)
        return;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    QString s = QString::number(game->cellNumber())+"\n";
    file.write(s.toAscii());
    file.write(game->dump().toAscii());
    QString buf = QString::number(ui->iterInterval->value())+"\n";
    file.write(buf.toAscii());
    file.close();
}

void MainWindow::loadGame()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open saved game"),
                                                    QDir::homePath(),
                                                    tr("Evolution files  (*.evol)"));
    if(filename.length() < 1)
        return;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QTextStream in(&file);

    int sv;
    in >> sv;
    ui->cellsControl->setValue(sv);

    game->setCellNumber(sv);
    QString dump="";
    for(int k=0; k != sv; k++) {
        QString t;
        in >> t;
        dump.append(t+"\n");
    }
    game->setDump(dump);
    int interval;
    in >> interval;
    ui->iterInterval->setValue(interval);
    game->setInterval(interval);
}

void MainWindow::updateStats()
{
    ui->stAll->setNum(game->stAllCount);
    ui->stBlack->setNum(game->stBlackCount);
    ui->stGreen->setNum(game->stGreenCount);
    ui->stRed->setNum(game->stRedCount);
    stTimer->setInterval(game->interval());
}

void MainWindow::startResume()
{
    if (game->paused){
        game->startGame();
        ui->startButton->setText("Pause");
    } else {
        game->stopGame();
        ui->startButton->setText("Start");
    }
}

void MainWindow::setStartResume()
{
    if (! game->paused){
        game->stopGame();
        ui->startButton->setText("Start");
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return){
        startResume();
    }
}

