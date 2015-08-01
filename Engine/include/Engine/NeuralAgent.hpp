#pragma once

#include <Neural/Network.hpp>
#include <Engine/Agent.hpp>
namespace Engine {
    class Agent;
    class NeuralAgent : public Agent
    {
    public:
        NeuralAgent();
        NeuralAgent(unsigned _x, unsigned _y);
        NeuralAgent(QPoint _pos);
        ~NeuralAgent();

        QString getDesc(void) { return "NeuralAgent"; }
        bool isDrawable(void) { return false; }
/*
        virtual void setNNInputs(QVector<double> inputs);
        virtual QVector<double> getNNOutputs(void);

        virtual void setNNWeights(QVector<double> weights);
        virtual QVector<double>* getNNWeights(void);
        */
    protected:
        Neural::Network nn;
        virtual void InitNeuralNetwork(void);
    };
}
