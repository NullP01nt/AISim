#include <Engine/NeuralAgent.hpp>

class StudentAgent : public Engine::NeuralAgent {
    Q_OBJECT
public:
    StudentAgent(void);
    StudentAgent(unsigned x, unsigned y);
    ~StudentAgent(void);

    QString getDesc(void) { return "StudentAgent"; }
    bool isDrawable(void) { return drawable; }
public slots:
    void processMessage(unsigned sender, QString msg, bool isTrainingMsg, QVector<double> &target);
protected:
    const QString className = "StudentAgent";
    const bool drawable = true;

    void InitNeuralNetwork(void);
};
