#include <Engine/Environment.hpp>

Engine::Environment::Environment() { map = nullptr; }
Engine::Environment::~Environment(void) {}

void Engine::Environment::registerAgent(Engine::Agent *a) {
    agents.push_back(a);
    a->setEnvironment(this);
    connect(this,SIGNAL(messagePublished(uint,QString,bool,QVector<double>&)), a, SLOT(processMessage(uint,QString,bool,QVector<double>&)));
}

QVector<Engine::Agent*>* Engine::Environment::getAgents(void) {
    return &agents;
}

void Engine::Environment::setMap(Engine::Map *_map) {
    map = _map;
}

void Engine::Environment::publishMessage(unsigned sender, QString content, bool isTrainingMsg, QVector<double> &target) {
    emit(messagePublished(sender,content,isTrainingMsg,target));
}

Engine::Map* Engine::Environment::getMap(void) {
    return map;
}
