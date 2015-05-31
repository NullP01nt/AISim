#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <QObject>
#include <QVector>
#include <Agent.hpp>
#include <Map.hpp>

namespace Engine {
    class Agent;
    class Environment : public QObject
    {
        Q_OBJECT

    public:
        Environment();
        ~Environment();

        void registerAgent(Engine::Agent* a);
        QVector<Engine::Agent*>* getAgents(void);

        void setMap(Map* _map);
        Engine::Map*    getMap(void);

    protected:
        Engine::Map* map;
        QVector<Engine::Agent* > agents;

    };
}

#endif // ENVIRONMENT_HPP
