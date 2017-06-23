#ifndef V2XCONTROL_H
#define V2XCONTROL_H

#include <QObject>
#include <QtDebug>
#include <QThread>
#include "v2xcommand.h"

/* Control script parameters
 * Note: The first iteration of this module will invoke a provided helper script
 * on the host system. Obviously this is not as robust or ideal as simply invoking
 * the V2X control port directly.
 */

class V2xControl : public QObject
{
    Q_OBJECT
public:
    explicit V2xControl(QObject *parent = nullptr);
    ~V2xControl();

    enum Commands {
        PowerOff
    };
    Q_ENUM(Commands)

    Q_INVOKABLE void requestPowerOff(const int time_ms);

signals:
    void notifyPowerOff(const int time_ms);

public slots:
    void onRequestPowerOff();

private:
    V2xCommand* _command;
    QString _controlScriptPath;
    QString _controlScriptName;
    QString _cOption;
    QString _bashProcess;
    void sendCommandPowerOff();
    void sendCommand(int v2x_command);
    void sendCommand(QString v2x_command_string);
};

#endif // V2XCONTROL_H
