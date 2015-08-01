#include <QDebug>
#include <vector>
#include "StudentAgent.hpp"

StudentAgent::StudentAgent(void) : NeuralAgent() { InitNeuralNetwork();}
StudentAgent::StudentAgent(unsigned x, unsigned y) : NeuralAgent(x,y) { InitNeuralNetwork(); }
StudentAgent::~StudentAgent() {}

void StudentAgent::InitNeuralNetwork(void) {
    std::vector<unsigned> topo = {16, 24, 8};
    nn.setTopology(topo);
}

void StudentAgent::processMessage(unsigned sender, QString msg, bool isTrainingMsg, QVector<double> &target) {
    qDebug() << sender << " " << msg << " " << isTrainingMsg << " " << target << "\r\n";
    if(sender!=getID()) {
        bool bStatus = false;
        uint val = msg.toUInt(&bStatus,16);
        QVector<bool> surround = getSurroundings();
        std::vector<double> inputs;

        qDebug() << val;
        for(unsigned msk = 0x80; msk>0;msk>>=1)
            inputs.push_back((val&msk) ? 1.0 : 0.0);

        for(int i=0; i<surround.size();i++)
            inputs.push_back(surround[i] ? 1.0 : 0.0);

        for(unsigned i=0; i<inputs.size();i++) {
            qDebug() << inputs[i] << "\r\n";
        }

    }
}
