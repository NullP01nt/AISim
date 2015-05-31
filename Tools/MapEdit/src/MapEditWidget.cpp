#include "MapEditWidget.hpp"

#include <QMouseEvent>
#include <QPainter>
#include <QRect>

#include <QTextStream>
#define cout QTextStream(stdout)
#define endl '\n'

MapEditWidget::MapEditWidget(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_StaticContents);
    setMinimumSize(WIDG_W,WIDG_H);
    setMaximumSize(WIDG_W,WIDG_H);
    setFixedSize(WIDG_W, WIDG_H);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    map = new MutableMap();
    connect(this,SIGNAL(mapChanged()),this,SLOT(update()));
    drawing = false;
    draw_grid = false;
}

QSize MapEditWidget::size() const {
    return QSize(WIDG_W,WIDG_H);
}

QSize MapEditWidget::sizeHint() const {
    return QSize(WIDG_W,WIDG_H);
}

void MapEditWidget::newMapFile(QString filename) {
    map = new MutableMap(filename);
    emit this->mapChanged();
}

void MapEditWidget::clearMap(void) {
    map = new MutableMap();
    emit this->mapChanged();
}

void MapEditWidget::toggle_grid(bool newval) {
    draw_grid=newval;
    emit this->mapChanged();
}

MutableMap* MapEditWidget::getMap(void) {
    return map;
}

void MapEditWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush bg = QBrush(Qt::black);
    QBrush fg = QBrush(Qt::white);
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);
    painter.fillRect(0,0,1024,512,bg.color());    
    if(map != nullptr) {
        for(unsigned y=0; y < map->getHeight(); y++) {
            for(unsigned x=0; x < map->getWidth(); x++ ) {
                if(map->isObstacle(x,y)) {
                    QRect r(GRID_SIZE*x,GRID_SIZE*y,GRID_SIZE, GRID_SIZE);
                    painter.fillRect(r,fg.color());
                }
            }
        }
    }

    if(draw_grid) {
        for(unsigned x=0; x<=WIDG_W;x+=GRID_SIZE)
            painter.drawLine(x,0,x,32*GRID_SIZE);
        for(unsigned y=0; y<=WIDG_H;y+=GRID_SIZE)
            painter.drawLine(0,y,64*GRID_SIZE,y);
    }
}

bool MapEditWidget::getValueAt(QPoint pos) {
    unsigned x, y;
    x = pos.x()/GRID_SIZE;
    y = pos.y()/GRID_SIZE;
    return map->isObstacle(x,y);
}

void MapEditWidget::mousePressEvent(QMouseEvent* event) {
//    cout << __func__ << " E(" << event->x() << ", " << event->y() << ") G(" << x <<","<<y<<")" << endl
    if(event->buttons() & Qt::LeftButton) {
        drawVal = true;
    } else if (event->buttons() & Qt::RightButton) {
        drawVal = false;
    }

    if (event->buttons() > Qt::NoButton) {
        drawing=true;
        drawAt(event->pos());
    }
}

void MapEditWidget::mouseReleaseEvent(QMouseEvent *event) {
    if(event->buttons() > Qt::NoButton) {
        drawing = false;
        drawAt(event->pos());
    }
}

void MapEditWidget::mouseMoveEvent(QMouseEvent *event) {
    if((event->buttons() > Qt::NoButton) && drawing) {
        drawAt(event->pos());
    }
}

void MapEditWidget::drawAt(QPoint pos) {
    unsigned x, y;
    x = pos.x()/GRID_SIZE;
    y = pos.y()/GRID_SIZE;
    map->setObstacle(x,y,drawVal);
    emit this->mapChanged();
}

void MapEditWidget::toggleAt(QPoint pos) {
    unsigned x, y;
    x = pos.x()/GRID_SIZE;
    y = pos.y()/GRID_SIZE;
    map->toggle(x,y);
    emit this->mapChanged();
}
