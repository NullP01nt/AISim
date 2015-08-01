#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <QObject>
#include <QVector>
#include <QString>

#include <Engine/Agent.hpp>
#include <Engine/Map.hpp>

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
        void publishMessage(unsigned sender, QString content, bool isTrainingMsg, QVector<double> &target);

    signals:
        void messagePublished(unsigned sender, QString content, bool isTrainingMsg, QVector<double> &target);

    protected:
        Engine::Map* map;
        QVector<Engine::Agent* > agents;

    };
}

#endif // ENVIRONMENT_HPP
