#ifndef MAPEDITWIDGET_HPP
#define MAPEDITWIDGET_HPP

#include <QWidget>
#include "MutableMap.hpp"
#define WIDG_W 1024
#define WIDG_H 512
#define GRID_SIZE 16

class MapEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MapEditWidget(QWidget *parent = 0);
    QSize size() const;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    MutableMap* getMap(void);

public slots:
    void newMapFile(QString filename);
    void clearMap(void);
    void toggle_grid(bool);

signals:
    void mapChanged(void);

protected:
    MutableMap* map;
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
//    void resizeEvent(QResizeEvent *) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

private:
    bool getValueAt(QPoint pos);
    void drawAt(QPoint pos);
    void toggleAt(QPoint pos);
    bool drawing;
    bool drawVal;

    bool draw_grid;
};

#endif // MAPEDITWIDGET_HPP
