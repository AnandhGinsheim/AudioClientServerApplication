#ifndef AUDIOMODEL_H
#define AUDIOMODEL_H
#include <iostream>
#include "Constants.h"
#include "InstanceFactory.h"

// AudioModel header file

namespace audio_app {

class AudioModel {
public:
	FileLoadStatus loadAudioFile();
	FileLoadStatus unloadAudioFile();

private:
	FileLoadStatus m_FileLoadStatus;
};

}
#endif
