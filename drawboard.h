#ifndef DRAWBOARD_H
#define DRAWBOARD_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include "graphics.h"

class DrawBoard : public QWidget
{
    Q_OBJECT
private:
    QPixmap *back_pix;
    QPoint vertex[20];
    void _draw_edge(QPoint, QPoint, QPen &pen);
public:
    explicit DrawBoard(QWidget *parent = nullptr);
    ~DrawBoard() override;
    void clear();
    void draw_vertex(QPoint);
    void draw_string(int x, int y, QString str);
    void draw_edge(int, int, QPen &pen);
    void draw_background(Map &map);
    void paintEvent(QPaintEvent *) override;
signals:

public slots:
};
#endif // DRAWBOARD_H
