#ifndef REMOTEAGENT_HPP
#define REMOTEAGENT_HPP

#include <QObject>
#include <Engine/Agent.hpp>

class RemoteAgent : public Engine::Agent
{
    Q_OBJECT
public:
    RemoteAgent(void);
    RemoteAgent(unsigned x, unsigned y);
    ~RemoteAgent(void);

    QString getDesc(void) { return "RemoteAgent"; }
    bool isDrawable(void) { return true; }

public slots:
    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveRight(void);

protected:

};

#endif // REMOTEAGENT_HPP
