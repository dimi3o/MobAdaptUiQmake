#include <QtCore/QTimer>
#include "modelinfo.h"

ModelInfo::ModelInfo(QObject *parent) : QObject(parent), m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &ModelInfo::updateStateTimer);

//    m_timer->start(100);
}

QString ModelInfo::state() const
{
    return m_state;
}

void ModelInfo::setState(const QString &state)
{
    if (m_state == state)
        return;
    m_state = state;
    emit stateChanged();
}

void ModelInfo::updateState(const QString &new_state = "")
{
    if (new_state.isEmpty() or new_state.isNull())
            return;
    setState(new_state);
}

void ModelInfo::updateStateTimer()
{
    if (ModelInfo::timer_is_active())
    {
        m_total += 100;
        setState(calcState());
    }
}

QString ModelInfo::calcState()
{
    int total = (100 - ModelInfo::m_timer->remainingTime()) + m_total;
    QString state = "state "+QString::number(total);
    return state;
}

bool ModelInfo::timer_is_active() const
{
    return m_timer->isActive();
}

void ModelInfo::start_timer()
{
    if (m_timer->isActive())
        return;
    m_timer->start(100);
}

void ModelInfo::stop_timer()
{
    if (m_timer->isActive())
        m_timer->stop();
}
