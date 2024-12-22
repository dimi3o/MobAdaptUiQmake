#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include "layer.h"
#include "math.h"
#include "connection.h"

using namespace std;

class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned myIndex);
    void setOutputVal(double val) { m_outputVal = val; }
    double getOutputVal(void) const { return m_outputVal; }
    void feedForward(const Layer &prevLayer);
    void calcOutputGradients(double targetVals);
    void calcHiddenGradients(const Layer &nextLayer);
    void updateInputWeights(Layer &prevLayer);
private:
    static double eta; // [0.0...1.0] overall net training rate
    static double alpha; // [0.0...n] multiplier of last weight change [momentum]
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    // randomWeight: 0 - 1
    static double randomWeight(void) { return rand() / double(RAND_MAX); }
    double sumDOW(const Layer &nextLayer) const;
    double m_outputVal;
    vector<Connection> m_outputWeights;
    unsigned m_myIndex;
    double m_gradient;
};

//class Neuron{

//	long double outputValue;

//	long double gradient;

//	string transferFunction;

//	unsigned index;

// 	// [0.0..1.0] overall net training rate
// 	// 0.0 slow learner
// 	// 0.2 medium learner
// 	// 1.0 reckless learner

//	// [0.0..n] multiplier of last weight change (momentum)
//	// 0.0 no momentum
//	// 0.5 moderate momentum

//	//conections weights
//	vector<Connection> outputWeights;

//	//	---- transfer Functions hiperbolic tangent
//    static long double transferFunctionTanH(long double x);

//	static long double transferFunctionTanHDerivative(long double x);

//	//	---- transfer Functions sigmoid
//    static long double transferFunctionSig(long double x);

//	static long double transferFunctionSigDerivative(long double x);

//	//	---- transfer Functions step
//    static long double transferFunctionStep(long double x);

//	static long double transferFunctionStepDerivative();

//    // sum of diff of weights of next layer
//    long double sumDOW(const Layer &nextLayer) const;

//public:
//	Neuron(unsigned numberOutputs, unsigned index);

//	Neuron(unsigned numberOutputs, unsigned index, const string &transferFunction);

//	void setOutputValue(long double value);

//	long double getOutputValue() const;

//	void feedForward(const Layer &prevLayer);

//	void calculateOutputGradients(long double targetValue);
//	void calculateHiddenGradients(const Layer &nextLayer);
//	void updateInputWeights(Layer &prevLayer, const long double &eta, const long double &alpha);
//};

#endif
