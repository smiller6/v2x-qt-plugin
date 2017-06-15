#include "v2xcontrol.h"

#include <QtCore/QProcess>
#include <QIODevice>
#include <QTimer>
// #include <QQuickView>

V2xControl::V2xControl(QObject *parent) : QObject(parent)
{
    this->_controlScriptPath = "/usr/sbin";
    this->_controlScriptName = "v2x-example.sh";
    this->_cOption = "-c";
    this->_bashProcess = "/bin/bash";

    this->_command = new V2xCommand();
}

void V2xControl::requestPowerOff(const int time_ms)
{
    // emit the signal that asks for the power off after a time
    qDebug() << "calling poweroff after time milliseconds: " + time_ms;
   // auto timer = new QTimer(this);
   // timer->setSingleShot(true);
   // QObject::connect(timer, SIGNAL(timeout()), this, SLOT(onRequestPowerOff(int)));
   // timer->start(time_ms);
   // timer->
    // immediately emit a notification signal that the power will be turning off in a time
    emit notifyPowerOff(time_ms);
    // emit requested signal after requested time, to request actual power off action
    QTimer::singleShot(time_ms, this, SLOT(onRequestPowerOff(time_ms)));
}

void V2xControl::onRequestPowerOff() {
   qDebug() << "requestPowerOff slot called";
   sendCommandPowerOff();

}

void V2xControl::sendCommandPowerOff()
{
    this->sendCommand(_command->commandPowerOff);
}

void V2xControl::sendCommand(int v2x_command)
{

}

void V2xControl::sendCommand(QString v2x_command_string)
{
    qDebug() << "Control got command: " << v2x_command_string;
    //send this command to the bash script
    QProcess process;
    QStringList list;
    list << this->_cOption
         << this->_controlScriptPath
         << this->_controlScriptName
         << v2x_command_string
         << "\r";
    process.setProgram(_bashProcess);
    process.setArguments(list);
    process.start(QIODevice::ReadWrite);
}

V2xControl::~V2xControl()
{
    if(_command) delete _command;
}
