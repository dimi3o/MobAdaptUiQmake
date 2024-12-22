#include "stringobject.h"
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

    if (m_value == "init"){
        //"/usr/share/ru.bmstu.MobAdaptUiQmake/trainingData.txt"
        trainData = TrainingData("/usr/share/ru.bmstu.MobAdaptUiQmake/data/trainingData.txt"); //"../data/xor/xordata.txt"
        cout << trainData.isEof() << endl;
        trainData.getTopology(topology);
        myNet = Net(topology);
        trainingPass = 0;
    }
    if(!trainData.isEof())
    {
        ++trainingPass;
        cout << endl << "Pass" << trainingPass;
        m_value = "Pass "+QString::number(trainingPass);


        // Get new input data and feed it forward:
        if(trainData.getNextInputs(inputVals) != topology[0])
        {
            cout << endl << "Done" << endl;
            m_value += "\n";
            goto exit;
        }
        m_value += showVectorVals("\nInputs: ", inputVals);
        myNet.feedForward(inputVals);

        // Collect the net's actual results:
        myNet.getResults(resultVals);
        m_value += showVectorVals("\nOutputs: ", resultVals);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        m_value += showVectorVals("\nTargets: ", targetVals);
        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        // Report how well the training is working, average over recnet
        double error = myNet.getRecentAverageError();
        cout << "\nNet recent average error: "
             << error << endl;
        m_value += "\nAverage error:  "+QString::number(error);
        errors.push_back(error);
    }


exit:
    emit valueChanged();
}

void StringObject::updateValue(const QString &value)
{
    setValue(value);
}

QString StringObject::showVectorVals(string label, vector<double> &v)
{
    QString s = QString::fromStdString(label);
    for(unsigned i = 0; i < v.size(); ++i)
    {
        s += QString::number(v[i]) + "  ";
    }
    return s;
}
