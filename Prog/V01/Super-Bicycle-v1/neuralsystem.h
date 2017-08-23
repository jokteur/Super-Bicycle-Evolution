#ifndef NEURALSYSTEM_H
#define NEURALSYSTEM_H

#include <cstdint>
#include <array>

typedef struct decision
{
    uint8_t decisionID; //256 décisions max, c'est ok ?
    uint16_t waitTime;
    float value;
} decision;


typedef struct neuron
{
    uint16_t neuronID; //65536 neurons max, ça me semble ok
    float biais;
    char label[10]; //Facultatif
} neuron;
typedef struct connection
{
    neuron* from;
    neuron* to;
    float weight;
} connection;

class NeuralSystem
{
private:
    uint8_t m_depth;
    //std::array<neuron>* m_neurons = nullptr;
    //std::array<connection>* m_connections = nullptr;

    float linear(connection *con1, connection *con2);
    float binaryThreshold(connection *con1, connection *con2);
    float rectifiedLinear(connection *con1, connection *con2);
    float sigmoid(connection *con1, connection *con2);

public:
    NeuralSystem();
    ~NeuralSystem();

    decision makeDecision();

};

#endif // NEURALSYSTEM_H
