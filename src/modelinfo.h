#ifndef MODELINFO_H
#define MODELINFO_H

#include <QObject>
#include <QString>

class QTimer;

class ModelInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString state READ state NOTIFY stateChanged)

public:
    explicit ModelInfo(QObject *parent = nullptr);

    QString state() const;

    void setState(const QString &state);

signals:
    void stateChanged();

public slots:
    bool timer_is_active() const;
    void updateState(const QString &value);
    void start_timer();
    void stop_timer();

private slots:
    void updateStateTimer();

private:
    QTimer *m_timer{ nullptr };
    QString m_state = "init";
    quint16 m_total = 0;

    QString calcState();
};

#endif // MODELINFO_H
