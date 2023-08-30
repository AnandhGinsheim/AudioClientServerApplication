#include "AudioController.h"

namespace audio_app {

ProcessStatus AudioController::processCommand(Command t_command) {
	if (t_command == Command::COMMAND_QUIT) {
		quitApplication();
	} else if (getProcessStatus() == ProcessStatus::PROCESSSTATUS_PROCESSING) {
		std::cout << "No action taken. Because, Processing" << std::endl;
		m_processStatus = ProcessStatus::PROCESSSTATUS_PROCESSING;
		return ProcessStatus::PROCESSSTATUS_PROCESSING;
	}
	if ((getMusicStatus() == sf::Music::Stopped
			&& (t_command == Command::COMMAND_PLAY
					|| t_command == Command::COMMAND_STOP))
			|| (getMusicStatus() == sf::Music::Paused
					&& (t_command == Command::COMMAND_PLAY
							|| t_command == Command::COMMAND_STOP))) {
		startPlaying();
		std::cout << "Music is playing " << getMusicStatus() << std::endl;
	} else if ((getMusicStatus() == sf::Music::Playing
			&& t_command == Command::COMMAND_STOP)) {
		pausePlaying();
		std::cout << "Music paused " << getMusicStatus() << std::endl;
	}

	sf::sleep(sf::milliseconds(1000));
	m_processStatus = ProcessStatus::PROCESSSTATUS_SUCCESS;
	return m_processStatus;
}

ProcessStatus AudioController::startPlaying() {
	InstanceFactory<sf::Music>::getInstance()->play();
	return ProcessStatus::PROCESSSTATUS_SUCCESS;
}

ProcessStatus AudioController::pausePlaying() {
	InstanceFactory<sf::Music>::getInstance()->pause();
	return ProcessStatus::PROCESSSTATUS_SUCCESS;
}

ProcessStatus AudioController::quitApplication() {
	std::cout << "Quit command received - Quiting Application " << std::endl;
	return ProcessStatus::PROCESSSTATUS_QUIT;
}

ProcessStatus AudioController::getProcessStatus() const {
	return m_processStatus;
}

sf::Music::Status AudioController::getMusicStatus() const {
	return InstanceFactory<sf::Music>::getInstance()->getStatus();
}

}
