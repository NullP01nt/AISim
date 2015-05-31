#include "RemoteAgent.hpp"

RemoteAgent::RemoteAgent(void) : Agent() {}
RemoteAgent::RemoteAgent(unsigned x, unsigned y) : Agent(x,y) {}
RemoteAgent::~RemoteAgent() {}

#include <QTextStream>

void RemoteAgent::moveUp(void) {
//    p.setY((p.y()--));
}

void RemoteAgent::moveDown(void) {
//    p.setY((p.y())++);
}

void RemoteAgent::moveLeft(void) {
//    p.setX((p.x())--);
}

void RemoteAgent::moveRight(void) {
//    p.setX((p.x())++);
}
