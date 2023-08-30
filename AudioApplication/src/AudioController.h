#ifndef AUDIOCONTROLLER_H
#define AUDIOCONTROLLER_H

#include <iostream>
#include "Constants.h"
#include <SFML/Audio/Music.hpp>
#include "InstanceFactory.h"

namespace audio_app {

class AudioController {
public:
	ProcessStatus processCommand(const Command t_command);
	ProcessStatus getProcessStatus() const;
	sf::Music::Status getMusicStatus() const;
	Command getCommand() const;

private:
	ProcessStatus startPlaying();
	ProcessStatus pausePlaying();
	ProcessStatus quitApplication();
	ProcessStatus m_processStatus;
	Command m_command;

};
}

#endif
