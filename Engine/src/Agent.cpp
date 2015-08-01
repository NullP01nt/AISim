#include <Engine/Agent.hpp>

unsigned int Engine::Agent::ID = 1;

Engine::Agent::Agent(void) : mID(ID++) {}
Engine::Agent::Agent(unsigned _x, unsigned _y) : p(QPoint(_x,_y)), mID(ID++) {}
Engine::Agent::Agent(QPoint _pos) : p(_pos), mID(ID++) {}
Engine::Agent::~Agent(void) {}

void Engine::Agent::setEnvironment(Engine::Environment* _env) {
    env = _env;
}

QVector<bool> Engine::Agent::getSurroundings(void) {
    QVector<bool> result;
    int newX,newY;
    for(int dy=-1; dy<2; dy++) {
        for(int dx=-1; dx<2; dx++) {
            if(dx==0 && dy==0) continue;
            newX = p.x()+dx;
            newY = p.y()+dy;
            if(env->getMap()->isOutbound(newX,newY)) {
                result.push_back(true);
            } else if(env->getMap()->isObstacle(newX,newY)) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
    }
    return result;
}

void Engine::Agent::processMessage(unsigned sender, QString msg, bool isTrainingMsg, QVector<double> &target) {
}

unsigned int Engine::Agent::x(void) { return p.x(); }
unsigned int Engine::Agent::y(void) { return p.y(); }
QPoint Engine::Agent::pos(void) { return p; }
