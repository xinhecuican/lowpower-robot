#ifndef SHERPATTS_H
#define SHERPATTS_H
#include "TTSModel.h"
#include "sherpa-onnx/c-api/c-api.h"

class SherpaTTS : public TTSModel
{
public:
    SherpaTTS(QObject* parent=nullptr);
    ~SherpaTTS();
    void detect(const QString& text, const QString& type, int id) override;
    void stop() override;
private:
    const SherpaOnnxOfflineTts* tts;
    int speakerid;
    int extraVol;
    float speed;
};

#endif // SHERPATTS_H
