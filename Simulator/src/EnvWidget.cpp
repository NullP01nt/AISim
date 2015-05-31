#include "EnvWidget.hpp"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>

#include <Agent.hpp>

EnvWidget::EnvWidget(QWidget *parent) :
    QWidget(parent)
{
    map_render = QPixmap(WIDG_W,WIDG_H);
}

QSize EnvWidget::size() const {
    return QSize(WIDG_W,WIDG_H);
}

QSize EnvWidget::sizeHint() const {
    return QSize(WIDG_W,WIDG_H);
}

void EnvWidget::new_env(Engine::Environment * _e) {
    env = _e;
    if(env!=nullptr) {
        map = env->getMap();
    }
    render_map();
    emit this->map_changed();
}

void EnvWidget::render_map(void) {
    QPainter painter(&map_render);
    painter.fillRect(0,0,WIDG_W,WIDG_H,Qt::black);
    if(map!=nullptr) {
        for(unsigned y=0; y<map->getHeight();y++) {
            for(unsigned x=0; x<map->getWidth();x++) {
                if(map->isObstacle(x,y))
                    painter.fillRect(x*GRID_SIZE,y*GRID_SIZE,GRID_SIZE,GRID_SIZE,Qt::white);
            }
        }
    }
}

void EnvWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(0,0,map_render);

    Engine::Agent* A = nullptr;
    for(int aid =0; aid < env->getAgents()->size(); aid++) {
        A = env->getAgents()->at(aid);
        if(A!=nullptr) {
            if(A->isDrawable()) {
                painter.fillRect(A->x()*GRID_SIZE, A->y()*GRID_SIZE, GRID_SIZE, GRID_SIZE, cMap.getColor(A->getID()));
            }
        }
    }
}
