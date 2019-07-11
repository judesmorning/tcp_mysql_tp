#ifndef MYRUN_H
#define MYRUN_H

#include <QObject>
#include <QRunnable>
#include "abspacket.h"

class Myrun : public QObject , public QRunnable
{
    Q_OBJECT
public:
    explicit Myrun(AbsPacket* packet , QObject *parent = nullptr);

    void run();
signals:

public slots:

private:
    AbsPacket* packet = nullptr;
};

#endif // MYRUN_H
