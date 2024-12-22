#ifndef NET_H
#define NET_H

#include <vector>
#include <iostream>
#include <cassert>
#include "layer.h"
#include <string.h>

using namespace std;

class Net
{
public:
    Net();
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector<double> &resultVals) const;
    double getRecentAverageError(void) const { return m_recentAverageError; }

private:
    vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
    double m_error;
    double m_recentAverageError = 0;
    static double m_recentAverageSmoothingFactor;
};

//class Net{
//	long double error;
//	long double recentAverageError;
//	vector<Layer> layers ;// layers[layerNumber][neuronNumber]

//public:
//	//Net(const vector<unsigned> &topology);
//	Net(const vector<unsigned> &topology,const string &transferFunction);

//	//feedForward - operation to train the network
//	void feedForward(const vector<double> &inputValues);

//	// backPropagation learning
//	void backPropagation(const vector<double> &targetValues,const long double &eta ,const long double &alpha);

//	void getResults(vector<double> &resultValues) const;

//	long double getRecentAverageError() const;
//};

#endif
