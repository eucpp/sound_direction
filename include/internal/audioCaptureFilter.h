#ifndef AUDIOCAPTUREFILTER_H
#define AUDIOCAPTUREFILTER_H

#include <QObject>
#include <QSharedPointer>

#include "iAudioFilter.h"
#include "audioDeviceManager.h"

class AudioCaptureFilter: public QObject, public IAudioFilter
{
    Q_OBJECT
public:
    AudioCaptureFilter(const QSharedPointer<AudioDeviceManager>& deviceManager,
                       size_t frameLength,
                       QObject* parent = 0);

signals:
    void output(AudioBuffer buf);
public slots:
    AudioBuffer input(const AudioBuffer &buf);
private slots:
    void bufferReadyReadHandler();
private:
    QSharedPointer<AudioDeviceManager> mDeviceManager;
    QSharedPointer<QIODevice> mBuffer;
    quint16 mFrameLength;
};

#endif // AUDIOCAPTUREFILTER_H
