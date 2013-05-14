#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include <iostream>
#include "gamewidget.h"
#include "mainwindow.h"
#include "cell.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this)),
    universeSize(50)
{
    stAllCount = 0;
    stBlackCount = 0;
    stGreenCount = 0;
    stRedCount = 0;
    gen = 0;
    redLimit = 20;
    paused = true;
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    memset(&universe, false, sizeof(universe));
    memset(&next, false, sizeof(next));
    clear();
}

void GameWidget::startGame(const int &number)
{
    generations = number;
    timer->start();
    paused = false;
}

void GameWidget::stopGame()
{
    timer->stop();
    paused = true;
}

void GameWidget::clear()
{
    for(int k = 0; k <= 101; k++) {
        for(int j = 0; j <= 101; j++) {
            universe[k][j].clear();
            next[k][j].clear();
        }
    }
    update();
}

int GameWidget::cellNumber()
{
    return universeSize;
}

void GameWidget::setCellNumber(const int &s)
{
    universeSize = s;
    update();
}

QString GameWidget::dump()
{
    char temp;
    QString master = "";
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
            if (universe[k][j].type == 0){
                temp = '0';
            } else {
                if (universe[k][j].type == 1) {
                    temp = '1';
                } else {
                    if (universe[k][j].type == 2) {
                        temp = '2';
                    } else {
                        temp = 'x';
                    }
                }
            }
            master.append(temp);
        }
        master.append("\n");
    }
    return master;
}

void GameWidget::setDump(const QString &data)
{
    int current = 0;
    for(int k = 1; k <= universeSize; k++) {
        for(int j = 1; j <= universeSize; j++) {
            universe[k][j].clear();
            if (data[current] != 'x') {
                if (data[current] == '0')
                    universe[k][j].fill(0);
                if (data[current] == '1')
                    universe[k][j].fill(1);
                if (data[current] == '2')
                    universe[k][j].fill(2);
            }
            current++;
        }
        current++;
    }
    update();
}

int GameWidget::interval()
{
    return timer->interval();
}

void GameWidget::setInterval(int msec)
{
    timer->setInterval(msec);
}

void GameWidget::recalculateDirection(int k, int j)
{
    if (universe[k][j].type == -1) return;
    if (k == 1)
        universe[k][j].direction = 1; //down
    if (k == universeSize)
        universe[k][j].direction = 3; //up
    if (j == 1)
        universe[k][j].direction = 0; //left
    if (j == universeSize)
        universe[k][j].direction = 2; //right
    int dest_k = 0, dest_j = 0;
    switch (universe[k][j].direction){
    case 0:
        dest_k = k;
        dest_j = j + 1;
        break;
    case 1:
        dest_k = k + 1;
        dest_j = j;
        break;
    case 2:
        dest_k = k;
        dest_j = j - 1;
        break;
    case 3:
        dest_k = k - 1;
        dest_j = j;
        break;
    }

    checkCollision(dest_k, dest_j, k, j);
}

void GameWidget::checkCollision(int dest_k, int dest_j, int k, int j)
{
    int bp0 = 0, bp1 = 0;
    switch (universe[k][j].type){
    case 0:
    {
        if (next[dest_k][dest_j].type == 0) {
            if (next[dest_k - 1][dest_j - 1].type == -1) {
                next[dest_k - 1][dest_j - 1].fill(1);
            } else {
                next[dest_k + 1][dest_j - 1].fill(1);
            }
            next[k][j].fill(0);
        } else {bp0++;}
        if (next[dest_k][dest_j].type == 1) {
            if (next[dest_k - 1][dest_j - 1].type == -1) {
                next[dest_k - 1][dest_j - 1].fill(0);
            } else {
                next[dest_k + 1][dest_j - 1].fill(0);
            }
            next[k][j].fill(0);
        } else {bp0++;}
        if (next[dest_k][dest_j].type == 2) {
        } else {bp0++;}
        if (bp0 == 3){
            if (gen%3 == 0) {
                next[dest_k][dest_j].fill(0);
            } else {
                next[dest_k][dest_j] = universe[k][j];
            }
        }
        break;
     }
    case 1:
    {
        if (next[dest_k][dest_j].type == 0) {
            if (next[dest_k - 1][dest_j - 1].type == -1) {
                next[dest_k - 1][dest_j - 1].fill(0);
            } else {
                next[dest_k + 1][dest_j - 1].fill(0);
            }
            next[k][j].fill(0);
        } else {bp1++;}
        if (next[dest_k][dest_j].type == 1) {
            if (next[dest_k - 1][dest_j - 1].type == -1) {
                next[dest_k - 1][dest_j - 1].fill(2);
            } else {
                next[dest_k + 1][dest_j - 1].fill(2);
            }
            next[k][j].fill(0);
        } else {bp1++;}
        if (next[dest_k][dest_j].type == 2) {
        } else {bp1++;}
        if (bp1 == 3){
            if (gen%3 == 0) {
                next[dest_k][dest_j].fill(1);
            } else {
                next[dest_k][dest_j] = universe[k][j];
            }
        }
        break;
    }
    case 2:
    {
        checkCollisionRed(dest_k, dest_j, k, j);
        if (gen%3 == 0) {
            int tmp = universe[k][j].numTurn;
            next[dest_k][dest_j].fill(2);
            next[dest_k][dest_j].numTurn = tmp;
        } else {
            next[dest_k][dest_j] = universe[k][j];
        }
        break;
    }
    }
}

void GameWidget::checkCollisionRed(int dest_k, int dest_j, int k, int j)
{
    if (next[dest_k][dest_j].type == 2) {
        int tmp = universe[k][j].numTurn;
        next[k][j].fill(2);
        next[k][j].numTurn = tmp;
        return;
    }
}

void GameWidget::redAlertAndHungry()
{
    for (int k=1; k <= universeSize; k++){
        for (int j=1; j <universeSize; j++){
            if(next[k][j].type == 2 ){
                if (next[k][j].numTurn >= redLimit) {
                    next[k][j].clear();
                } else {
                    int tmp = next[k][j].numTurn;
                    next[k][j].numTurn = tmp + 1;
                }
            }
        }
    }

    for (int k=1; k <= universeSize; k++) {
        for (int j=1; j <= universeSize; j++) {
            if (next[k][j].type == 2){
                if ( (next[k - 1][j].type == 0) || (next[k - 1][j].type == 1) ) {
                    next[k - 1][j].clear();
                    next[k][j].numTurn = 0;
                }
                if ( (next[k + 1][j].type == 0) || (next[k + 1][j].type == 1) ) {
                    next[k + 1][j].clear();
                    next[k][j].numTurn = 0;
                }
                if ( (next[k][j + 1].type == 0) || (next[k][j + 1].type == 1) ) {
                    next[k][j + 1].clear();
                    next[k][j].numTurn = 0;
                }
                if ( (next[k][j - 1].type == 0) || (next[k][j - 1].type == 1) ) {
                    next[k][j - 1].clear();
                    next[k][j].numTurn = 0;
                }
            }
        }
    }
}

void GameWidget::newGeneration()
{
    stAllCountNow = 0;
    stBlackCountNow = 0;
    stGreenCountNow = 0;
    stRedCountNow = 0;
    gen++;
    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            switch (universe[k][j].type){
                case -1:
                    break;
                case 0:
                    stBlackCountNow++;
                    break;
                case 1:
                    stGreenCountNow++;
                    break;
                case 2:
                    stRedCountNow++;
                    break;
            }
            if (universe[k][j].type != -1)
                recalculateDirection(k, j);
        }
    }
    redAlertAndHungry();

    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            universe[k][j].clear();
            universe[k][j] = next[k][j];
            next[k][j].clear();
        }
    }
    stAllCountNow = stBlackCountNow + stGreenCountNow + stRedCountNow;
    if (stAllCountNow == 0) stopGame();
    stAllCount = stAllCountNow;
    stBlackCount = stBlackCountNow;
    stGreenCount = stGreenCountNow;
    stRedCount = stRedCountNow;
    update();
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUniverse(p);
}

void GameWidget::mousePressEvent(QMouseEvent *e)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    if (e->button() == Qt::LeftButton){
        if (universe[k][j].type == -1) {
            universe[k][j].fill(0);
        } else {
            if (universe[k][j].type == 0){
                universe[k][j].fill(1);
            } else {
                if(universe[k][j].type == 1){
                    universe[k][j].fill(2);
                } else {
                    universe[k][j].clear();
                }
            }
        }
    } else {
        universe[k][j].clear();
    }
    update();
}

void GameWidget::keyPressEvent(QKeyEvent *key)
{
    if (key->key() == Qt::Key_S) {
        if (!paused) {
            stopGame();
            paused = true;
        } else {
            startGame();
            paused = false;
        }
        std::cout << paused << std::endl;
    }

}

void GameWidget::paintGrid(QPainter &p)
{
    QRect borders(0, 0, width()-1, height()-1); // borders of the universe
    QColor gridColor = Qt::black; // color of the grid
    gridColor.setAlpha(10); // must be lighter than main color
    p.setPen(gridColor);
    double cellWidth = (double)width()/universeSize; // width of the widget / number of cells at one row
    for(double k = cellWidth; k <= width(); k += cellWidth)
        p.drawLine(k, 0, k, height());
    double cellHeight = (double)height()/universeSize; // height of the widget / number of cells at one row
    for(double k = cellHeight; k <= height(); k += cellHeight)
        p.drawLine(0, k, width(), k);
    p.drawRect(borders);
}

void GameWidget::paintUniverse(QPainter &p)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    for(int k=1; k <= universeSize; k++) {
        for(int j=1; j <= universeSize; j++) {
            if(universe[k][j].type != -1) { // if there is any sense to paint it
                qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
                qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                if (universe[k][j].type == 0)
                    p.fillRect(r, QBrush(Qt::black)); // fill cell with brush of main color
                if (universe[k][j].type == 1)
                    p.fillRect(r, QBrush(Qt::green)); // fill cell with brush of main color
                if (universe[k][j].type == 2)
                    p.fillRect(r, QBrush(Qt::red)); // fill cell with brush of main color
            }
        }
    }
}
