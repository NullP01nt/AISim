#ifndef AGENT_HPP
#define AGENT_HPP

#include <QPoint>
#include <QString>

#include <Engine/Environment.hpp>

namespace Engine {
    class Environment;
    class Agent : public QObject
    {
        Q_OBJECT

    public:
        Agent(void);
        Agent(unsigned _x, unsigned _y);
        Agent(QPoint _pos);
        ~Agent(void);

        unsigned int getID(void) { return mID; }
        QPoint       pos(void);
        unsigned int x(void);
        unsigned int y(void);

        void         setPos(QPoint _pos);
        void         setX(unsigned _x);
        void         setY(unsigned _y);

        void         setEnvironment(Engine::Environment* _env);
        QVector<bool> getSurroundings(void);

        virtual QString getDesc(void) { return "Agent"; }
        virtual bool isDrawable(void) { return false; }
    public slots:
        void processMessage(unsigned sender, QString msg, bool isTrainingMsg, QVector<double> &target);
    protected:
        QPoint p;
        unsigned int mID; // Currently assigned Agent ID
        Engine::Environment* env;

        static unsigned int ID;
    };
}
#endif // AGENT_HPP
