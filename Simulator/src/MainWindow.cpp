#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <Agent.hpp>
#include <StudentAgent.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(env_loaded(Engine::Environment*)),ui->envView,SLOT(new_env(Engine::Environment*)));
    env = new Engine::Environment();
    map = new Engine::Map("env.map");
    env->setMap(map);

    Engine::Agent* a = new Engine::Agent(10,10);
    StudentAgent* b = new StudentAgent(20,20);
    env->registerAgent(a);
    env->registerAgent(b);
    emit env_loaded(env);
}

MainWindow::~MainWindow()
{
    delete ui;
}
