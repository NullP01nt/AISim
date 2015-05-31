#include "Agent.hpp"

unsigned int Engine::Agent::ID = 0;

Engine::Agent::Agent(void) : mID(ID++) {}
Engine::Agent::Agent(unsigned _x, unsigned _y) : p(QPoint(_x,_y)), mID(ID++) {}
Engine::Agent::Agent(QPoint _pos) : p(_pos), mID(ID++) {}
Engine::Agent::~Agent(void) {}

void Engine::Agent::setEnvironment(Engine::Environment* _env) {
    env = _env;
}

unsigned int Engine::Agent::x(void) { return p.x(); }
unsigned int Engine::Agent::y(void) { return p.y(); }
QPoint Engine::Agent::pos(void) { return p; }
