#include <QtQml/qqmlextensionplugin.h>
#include <qqml.h>

#include "v2xcontrol.h"

QT_BEGIN_NAMESPACE

class QV2xPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    //Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")

public:
    virtual void registerTypes(const char *uri) {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("com.genivi.v2x"));
        Q_UNUSED(uri)
        qDebug("registerTypes called for v2x plugin...");
        qmlRegisterType<V2xControl>(uri, 1, 0, "V2xControl");
    }
};

QT_END_NAMESPACE

#include "plugin.moc"
