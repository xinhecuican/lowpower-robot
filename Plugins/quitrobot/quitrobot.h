#ifndef QUITROBOT_H
#define QUITROBOT_H
#include "../Plugin.h"
#include <QObject>
class QuitRobot : public QObject, Plugin {
    Q_OBJECT
    Q_INTERFACES(Plugin)
    Q_PLUGIN_METADATA(IID QSmartAssistant_PLUGIN_ID)
public:
    QuitRobot();
    QString getName() override;
    bool handle(const QString &text, const ParsedIntent &parsedIntent, int id,
                bool &isImmersive) override;
    void setPluginHelper(IPluginHelper *helper) override;
    void recvMessage(const QString &text, const ParsedIntent &parsedIntent,
                     const PluginMessage &message) override;
signals:
    void sendMessage(PluginMessage message) override;

private:
    IPluginHelper *helper;
};

#endif // QUITROBOT_H
