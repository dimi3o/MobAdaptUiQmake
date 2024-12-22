#ifndef STRINGOBJECT_H
#define STRINGOBJECT_H

#include <QObject>
#include <QString>
#include "trainingdata.h"
#include "net.h"

class StringObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit StringObject(QObject *parent = nullptr);

    QString value() const;
    void setValue(const QString &value);

    QString showVectorVals(string label, vector<double> &v);

public slots:
    void updateValue(const QString &value);

signals:
    void valueChanged();

private:
    QString m_value = "init";
    TrainingData trainData;
    int trainingPass;
    std::vector<double> errors;
    vector<double> inputVals, targetVals, resultVals;
    Net myNet;
    vector<unsigned> topology;
};

#endif // STRINGOBJECT_H
