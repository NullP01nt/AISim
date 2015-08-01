#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <Engine/Agent.hpp>
#include <StudentAgent.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(env_loaded(Engine::Environment*)),ui->envView,SLOT(new_env(Engine::Environment*)));
    env = new Engine::Environment();
    map = new Engine::Map("env.map");
    env->setMap(map);

    StudentAgent* b = new StudentAgent(20,20);
    Engine::Agent* a = new Engine::Agent(10,10);
    env->registerAgent(b);
    env->registerAgent(a);
    emit env_loaded(env);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QVector<double> v = {1.0,2.0,3.0,4.0};

   env->publishMessage(0,"AF",false,v);
}
