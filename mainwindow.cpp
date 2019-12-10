#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    char file_name[] = "RomaniaMap.txt";
    map.read_map(file_name);
    tb = addToolBar("Tool");
    algorithmLabel = new QLabel("算法选择:");
    al_cb = new QComboBox();
    cmd = new QPushButton("执行");
    tb->addWidget(algorithmLabel);
    al_cb->addItem("DFS算法", 0);
    al_cb->addItem("BFS算法", 1);
    al_cb->addItem("贪婪算法", 2);
    al_cb->addItem("A*算法", 3);
    tb->addWidget(al_cb);
    startLabel = new QLabel("出发地点:");
    start_cb = new QComboBox();
    endLabel = new QLabel("出发地点:");
    end_cb = new QComboBox();
    for(int i = 0; i < map.get_city_count(); ++i) {
        start_cb->addItem(QString::fromStdString(map.index2name(i)), i);
        end_cb->addItem(QString::fromStdString(map.index2name(i)), i);
    }
    tb->addWidget(startLabel);
    tb->addWidget(start_cb);
    tb->addWidget(endLabel);
    tb->addWidget(end_cb);
    distance_label = new QLabel("总距离:");
    distance_show = new QLabel("未知...");
    time_label = new QLabel("算法运行时间:");
    time_show = new QLabel("未知...");
    visit_label = new QLabel("生成结点数:");
    visit_show = new QLabel("未知...");
    tb->addWidget(distance_label);
    tb->addWidget(distance_show);
    tb->addWidget(time_label);
    tb->addWidget(time_show);
    tb->addWidget(visit_label);
    tb->addWidget(visit_show);
    connect(cmd, SIGNAL(clicked(bool)), this, SLOT(cmd_btn_click(bool)));
    tb->addWidget(cmd);
    setMinimumSize(1200, 600);
    ui->setupUi(this);
    db = new DrawBoard();
    setCentralWidget(db);
    db->draw_background(map);
}

void MainWindow::cmd_btn_click(bool) {
    db->draw_background(map);
    int al_choice = al_cb->currentData().toInt();
    int start, end;
    int f[255];
    size_t size;
    char file_name[] = "RomaniaHSLD.txt";
    read_hsld(file_name, f, &size);
    start = start_cb->currentData().toInt();
    end = end_cb->currentData().toInt();
    if(start == end) return;
    Result ret;
    switch(al_choice) {
    case 0:
        ret = dfs(&map, start, end);
        break;
    case 1:
        ret = bfs(&map, start, end);
        break;
    case 2:
        ret = greedy(&map, f, start, end);
        break;
    case 3:
        ret = A_star(&map, f, start, end);
        break;
    }
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    for(int i = 0; i < ret.tracks.size() - 1; ++i){
        db->draw_edge(ret.tracks[i], ret.tracks[i + 1], pen);
    }
    visit_show->setText(QString::number(ret.visit_count));
    time_show->setText(QString::number(ret.run_milsec));
    distance_show->setText(QString::number(ret.distance));
}

MainWindow::~MainWindow()
{
    delete ui;
}
