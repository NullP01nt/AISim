#include <Engine/NeuralAgent.hpp>

Engine::NeuralAgent::NeuralAgent() : Agent()
{
}

Engine::NeuralAgent::NeuralAgent(unsigned _x, unsigned _y) : Agent(_x,_y) {

}

Engine::NeuralAgent::NeuralAgent(QPoint _pos) : Agent(_pos) {

}

Engine::NeuralAgent::~NeuralAgent() {

}
