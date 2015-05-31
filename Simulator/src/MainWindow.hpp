#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Map.hpp>
#include <Environment.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Engine::Environment *env;
    Engine::Map *map;

signals:
    void env_loaded(Engine::Environment* env);
};

#endif // MAINWINDOW_H