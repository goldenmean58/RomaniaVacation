#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWidget>
#include "drawboard.h"
#include <QPainter>
#include <QGraphicsView>
#include <QToolBar>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "A-star.h"
#include "dfs_bfs.h"
#include "graphics.h"
#include "greedy.h"
#include "utils.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void cmd_btn_click(bool);

private:
    Ui::MainWindow *ui;
    Map map;
    DrawBoard *db;
    QToolBar *tb;
    QLabel *algorithmLabel;
    QComboBox *al_cb;
    QPushButton *cmd;
    QLabel *startLabel;
    QLabel *endLabel;
    QComboBox *start_cb;
    QComboBox *end_cb;
    QLabel *distance_label;
    QLabel *distance_show;
    QLabel *time_label;
    QLabel *time_show;
    QLabel *visit_label;
    QLabel *visit_show;
};

#endif // MAINWINDOW_H
