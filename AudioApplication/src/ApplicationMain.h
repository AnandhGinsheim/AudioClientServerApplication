#ifndef APPLICATIONMAIN_H
#define APPLICATIONMAIN_H

#include "InstanceFactory.h"

namespace audio_app {
class ApplicationMain {
public:
	ServerStatus startServer();
	ServerStatus stopServer();
	FileLoadStatus loadAudioFile();
	FileLoadStatus unloadAudioFile();
	Command receiveData();
	ProcessStatus processData();
	void setExitFlag(const bool t_exitFlag);
	bool getExitFlag() const;
private:
	bool m_exitFlag;
	Command m_command;
};
}
#endif
