#include "neuron.h"

double Neuron::eta = 0.15; // overall net learning rate
double Neuron::alpha = 0.5; // momentum, multiplier of last deltaWeight, [0.0..n]

void Neuron::updateInputWeights(Layer &prevLayer)
{
    // The weights to be updated are in the Connection container
    // in the nuerons in the preceding layer

    for(unsigned n = 0; n < prevLayer.size(); ++n)
    {
        Neuron &neuron = prevLayer[n];
        double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

        double newDeltaWeight =
                // Individual input, magnified by the gradient and train rate:
                eta
                * neuron.getOutputVal()
                * m_gradient
                // Also add momentum = a fraction of the previous delta weight
                + alpha
                * oldDeltaWeight;
        neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
        neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
    }
}
double Neuron::sumDOW(const Layer &nextLayer) const
{
    double sum = 0.0;

    // Sum our contributions of the errors at the nodes we feed

    for (unsigned n = 0; n < nextLayer.size() - 1; ++n)
    {
        sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
    }

    return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer)
{
    double dow = sumDOW(nextLayer);
    m_gradient = dow * Neuron::transferFunctionDerivative(m_outputVal);
}
void Neuron::calcOutputGradients(double targetVals)
{
    double delta = targetVals - m_outputVal;
    m_gradient = delta * Neuron::transferFunctionDerivative(m_outputVal);
}

double Neuron::transferFunction(double x)
{
    // tanh - output range [-1.0..1.0]
    return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
    // tanh derivative
    return 1.0 - x * x;
}

void Neuron::feedForward(const Layer &prevLayer)
{
    double sum = 0.0;

    // Sum the previous layer's outputs (which are our inputs)
    // Include the bias node from the previous layer.

    for(unsigned n = 0 ; n < prevLayer.size(); ++n)
    {
        sum += prevLayer[n].getOutputVal() *
                 prevLayer[n].m_outputWeights[m_myIndex].weight;
    }

    m_outputVal = Neuron::transferFunction(sum);
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
    for(unsigned c = 0; c < numOutputs; ++c){
        m_outputWeights.push_back(Connection());
        m_outputWeights.back().weight = randomWeight();
    }

    m_myIndex = myIndex;
}

//long double Neuron::eta = 0.15;    // overall net learning rate, [0.0..1.0]
//long double Neuron::alpha = 0.5;   // momentum, multiplier of last deltaWeight, [0.0..1.0]

//Neuron::Neuron(unsigned numberOutputs, unsigned index){
//	for (unsigned c = 0; c < numberOutputs; c++){
//		outputWeights.push_back(Connection());
//	}
//	this->index=index;
//}

//Neuron::Neuron(unsigned numberOutputs, unsigned index,  const string &transferFunction){
//	for (unsigned c = 0; c < numberOutputs; c++){
//		outputWeights.push_back(Connection());
//	}
//	this->index=index;
//	this->transferFunction=transferFunction;
//}

//void  Neuron::setOutputValue(long double value) {
//  outputValue = value;
//}

//long double  Neuron::getOutputValue() const{
//  return outputValue;
//}

//long double Neuron::transferFunctionTanH(long double x){
//	// tanh - output range [-1.0..1.0]
//    return tanh(x);
//}

//long double Neuron::transferFunctionTanHDerivative(long double x){
//	// tanh derivative aproximation
//	//return 1.0 - x * x;

//	return 1.0 - tanh(x) * tanh(x);
//}

//long double Neuron::transferFunctionSig(long double x){
//	// tanh - output range [-1.0..1.0]
//    return 1/(1+exp(-1*x));
//}

//long double Neuron::transferFunctionSigDerivative(long double x){
//	// tanh derivative aproximation
//	return exp(-1*x)/pow((1+exp(-1*x)),2);
//}

//long double Neuron::transferFunctionStep(long double x){
//	return (x<0)?0:x;
//}

//long double Neuron::transferFunctionStepDerivative(){
//	// step derivative aproximation
//	return 1.0 ;
//}

//void Neuron::feedForward(const Layer &prevLayer){
//	long double sum=0.0;

//	// Sum the previous layer's outputs (which are our inputs)
//    // Include the bias node from the previous layer.
//	for (unsigned n = 0; n < prevLayer.size();  n++){
//		sum+=prevLayer[n].getOutputValue() * prevLayer[n].outputWeights[index].weight;
//	}

//	// activate function or transfer /sig /gaussian /linear/ step
//	if (this->transferFunction=="th")
//		outputValue = Neuron::transferFunctionTanH(sum);
//	else if (this->transferFunction=="sig")
//		outputValue = Neuron::transferFunctionSig(sum);

//}

//void Neuron::calculateOutputGradients(long double targetValue){
//	long double delta= targetValue - outputValue;
//	if (this->transferFunction=="th")
//		gradient =delta * Neuron::transferFunctionTanHDerivative(outputValue);
// 	else if (this->transferFunction=="sig")
//		gradient =delta * Neuron::transferFunctionSigDerivative(outputValue);
//}

//long double Neuron::sumDOW(const Layer &nextLayer) const{
//	long double sum = 0.0;

//	// Sum our contributions of the errors at the nodes we feed.
//	for(unsigned n = 0; n < nextLayer.size() -1; n++){
//		sum+=outputWeights[n].weight * nextLayer[n].gradient;
//  	}

//  	return sum;
//}

//void Neuron::calculateHiddenGradients(const Layer &nextLayer){
//	long double dow= sumDOW(nextLayer);
//	gradient = dow * Neuron::transferFunctionTanHDerivative(outputValue);
//}

//void Neuron::updateInputWeights(Layer &prevLayer, const long double &eta, const long double &alpha){
// 	// 	The weights to be updated are in the Connection container
//    // in the neurons in the preceding layer
//	for(unsigned n = 0; n < prevLayer.size(); n++){
//		Neuron &neuron = prevLayer[n];
//		Connection &conn=neuron.outputWeights[index];

//		long double oldDeltaWeight = conn.deltaWeight;
//		long double newDeltaWeight =
//                // Individual input, magnified by the gradient and train rate:
//                eta
//                * neuron.getOutputValue()
//                * gradient
//                // Also add momentum = a fraction of the previous delta weight;
//                + alpha
//                * oldDeltaWeight;

//        conn.deltaWeight = newDeltaWeight;
//        conn.weight += newDeltaWeight;
//  	}

//}
