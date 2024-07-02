#include "stringobject.h"
#include "net.h"
#include "trainingdata.h"
#include "iostream"
using namespace std;

StringObject::StringObject(QObject *parent) : QObject(parent)
{

}

QString StringObject::value() const
{
    return m_value;
}

void StringObject::setValue(const QString &value)
{
    if (m_value == value)
        return;
    m_value = "Message "+value;
//    std::cout.write(m_value.toLocal8Bit().data(), m_value.size());
//    vector<unsigned> topology;
//    vector<vector<double>> inputValsA, targetValuesA;
//    vector<double> inputVals, targetValues, resultValues;
//    int trainingPass = 0;
//    int epochs=0;
//    bool test=false;
//    bool testFile=false;
//    long double minError=0.01;
//    int maxEpochs=10;

//    TrainingData trainData("data\\xor\\xordata.txt");
//    long double eta,momentum;
//    string transferFunction;

//    trainData.getTopology(topology);
//    trainData.getEta(eta);
//    trainData.getMomentum(momentum);
//    trainData.getTransferFunction(transferFunction);

//    //Load trainning data from file
//    while (!trainData.isEof()) {
//        trainingPass++;

//        // Get new input data and feed it forward:
//        if (trainData.getNextInputs(inputVals) != topology[0])
//            break;
//        inputValsA.push_back(inputVals);

//        // Train the net what the outputs should have been:
//        trainData.getTargetOutputs(targetValues);
//        assert(targetValues.size() == topology.back());
//        targetValuesA.push_back(targetValues);
//    }

//    Net net(topology,transferFunction);

    emit valueChanged();
}

void StringObject::updateValue(const QString &value)
{
    setValue(value);
}
