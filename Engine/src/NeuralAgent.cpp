#include <Engine/NeuralAgent.hpp>

namespace Engine {

NeuralAgent::NeuralAgent() : Agent()
{
    InitNeuralNetwork();
}

NeuralAgent::NeuralAgent(unsigned _x, unsigned _y) : Agent(_x,_y) {
    InitNeuralNetwork();
}

NeuralAgent::NeuralAgent(QPoint _pos) : Agent(_pos) {
    InitNeuralNetwork();
}

NeuralAgent::~NeuralAgent() {

}

void NeuralAgent::InitNeuralNetwork() {

}

}
