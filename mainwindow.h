#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
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
    Ui::MainWindow *ui;
    ~MainWindow();

public slots:
    void saveGame();
    void loadGame();
    void setRedLimit(int limit);

private:

    QTimer* stTimer;
    GameWidget* game;
    void keyPressEvent(QKeyEvent *e);

private slots:
    void updateStats();
    void startResume();
    void setStartResume();
};

#endif // MAINWINDOW_H
