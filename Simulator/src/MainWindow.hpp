#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Engine/Map.hpp>
#include <Engine/Environment.hpp>

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
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
