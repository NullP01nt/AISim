#include <Engine/Environment.hpp>

Engine::Environment::Environment() { map = nullptr; }
Engine::Environment::~Environment(void) {}

void Engine::Environment::registerAgent(Engine::Agent *a) {
    agents.push_back(a);
    a->setEnvironment(this);
}

QVector<Engine::Agent*>* Engine::Environment::getAgents(void) {
    return &agents;
}

void Engine::Environment::setMap(Engine::Map *_map) {
    map = _map;
}

Engine::Map* Engine::Environment::getMap(void) {
    return map;
}
