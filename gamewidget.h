#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QtWidgets/QWidget>
#include "cell.h"

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

    //stats
    int stAllCount;
    int stAllCountNow;
    int stBlackCount;
    int stBlackCountNow;
    int stGreenCount;
    int stGreenCountNow;
    int stRedCount;
    int stRedCountNow;
    //stats
    int redLimit;
    bool paused;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *key);

public slots:
    void startGame(const int &number = -1); // start
    void stopGame(); // finish
    void clear(); // clear

    int cellNumber(); // number of the cells in one row
    void setCellNumber(const int &s); // set number of the cells in one row

    int interval(); // interval between generations
    void setInterval(int msec); // set interval between generations

//    QColor masterColor(); // color of the cells
//    void setMasterColor(const QColor &color); // set color of the cells

    QString dump(); // dump of current universe
    void setDump(const QString &data); // set current universe from it's dump

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();

private:
    QTimer* timer;
    int generations;
    Cell universe[102][102]; // map
    Cell next[102][102]; // map
    int universeSize;
    int gen;
    void recalculateDirection(int k, int j);
    void checkCollision(int dest_k, int dest_j, int k, int j);
    void checkCollisionRed(int dest_k, int dest_j, int k, int j);
    void redAlertAndHungry ();
};

#endif // GAMEWIDGET_H
