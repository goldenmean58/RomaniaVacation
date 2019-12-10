#include "drawboard.h"
#include "graphics.h"
#include "A-star.h"

DrawBoard::DrawBoard(QWidget *parent) : QWidget(parent), back_pix(nullptr),
    vertex{
            {72,164}, {744, 437}, {424, 499}, {236, 484},
            {1099, 495}, {535, 226}, {687, 527}, {1037, 397},
            {902, 132}, {232, 347}, {239, 416}, {757, 89},
            {160, 30}, {572,367}, {382, 296}, {324, 217},
            {81, 292}, {868, 397}, {979, 241}, {110, 93}
    }
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    back_pix = new QPixmap(size());
    back_pix->fill(Qt::white);
    setMinimumSize(1200, 600);
}
DrawBoard::~DrawBoard() {
    if(back_pix != nullptr){
        delete back_pix;
        back_pix = nullptr;
    }
}
void DrawBoard::clear() {
    if(back_pix != nullptr){
        delete back_pix;
        back_pix = nullptr;
    }
    back_pix = new QPixmap(size());
    back_pix->fill(Qt::white);
    update();
}
void DrawBoard::draw_vertex(QPoint p) {
    QPainter *painter = new QPainter();
    painter->begin(back_pix);
    painter->drawPoint(p);
    int w, h;
    w = 10;
    h = 10;
    QBrush brush(Qt::black);
    painter->fillRect(p.x() - w / 2, p.y() - h /2, w, h, brush);
    painter->end();
    update();
    delete painter;
}
void DrawBoard::draw_string(int x, int y, QString str) {
    QPainter *painter = new QPainter();
    painter->begin(back_pix);
    painter->setPen(QPen(Qt::red));
    painter->drawText(x, y, str);
    painter->end();
    update();
    delete painter;
}
void DrawBoard::_draw_edge(QPoint p1, QPoint p2, QPen &pen){
    QPainter *painter = new QPainter();
    painter->begin(back_pix);
    painter->setPen(pen);
    painter->drawLine(p1, p2);
    painter->end();
    update();
    delete painter;
}
void DrawBoard::draw_edge(int v1, int v2, QPen &pen){
    _draw_edge(vertex[v1], vertex[v2], pen);
}
void DrawBoard::draw_background(Map &map) {
    clear();
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(1);
    for (int i = 0; i < 20; i++) {
        draw_vertex(vertex[i]);
        auto neighbors = map.get_neighbors(i);
        for(auto neighbor : neighbors)
            draw_edge(i, neighbor, pen);
        QString place_name = QString::fromStdString(map.index2name(i));
        draw_string(vertex[i].x() - 10, vertex[i].y() - 10, place_name);
    };
    update();
}
void DrawBoard::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(QPoint(0, 0), *back_pix);
}
