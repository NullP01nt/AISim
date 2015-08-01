#ifndef MAPWIDGET_HPP
#define MAPWIDGET_HPP

#include <QWidget>
#include <QPixmap>

#include <Engine/Environment.hpp>
#include <Engine/Agent.hpp>
#include <Engine/Map.hpp>

#include "ColorMap.hpp"

#define WIDG_W 1024
#define WIDG_H 512
#define GRID_SIZE 16

class EnvWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EnvWidget(QWidget *parent = 0);
    QSize size() const;
    QSize sizeHint() const Q_DECL_OVERRIDE;
public slots:
    void new_env(Engine::Environment*);
signals:
    void map_changed(void);

protected:
    Engine::Environment* env;
    Engine::Map* map;

    ColorMap cMap;
    QPixmap map_render;
    void render_map();
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
};

#endif // MAPWIDGET_HPP
