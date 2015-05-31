#ifndef MAPEDITWINDOW_HPP
#define MAPEDITWINDOW_HPP

#include <QMainWindow>
#include "MutableMap.hpp"

namespace Ui {
class MapEditWindow;
}

class MapEditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapEditWindow(QWidget *parent = 0);
    ~MapEditWindow();

public slots:
    void newClicked(void);
    void openClicked(void);
    void saveClicked(void);
    void saveAsClicked(void);

signals:
    void newMap(void);
    void mapChanged(QString filename);

private:
    Ui::MapEditWindow *ui;
    MutableMap* map;
};

#endif // MAPEDITWINDOW_HPP
