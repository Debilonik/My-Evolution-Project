#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include "gamewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void saveGame();
    void loadGame();

private:
    Ui::MainWindow *ui;
    QTimer* stTimer;
    GameWidget* game;
    void keyPressEvent(QKeyEvent *e);

private slots:
    void updateStats();
    void startResume();
    void setStartResume();
};

#endif // MAINWINDOW_H
