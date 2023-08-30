#include "UserInput.h"

namespace audio_app {

Command UserInput::readInputCommand(const char t_clientInput) {
	if (t_clientInput == 'p') {
		m_command = Command::COMMAND_PLAY;
		return m_command;
	} else if (t_clientInput == 's') {
		m_command = Command::COMMAND_STOP;
		return m_command;
	} else if (t_clientInput == 'q') {
		m_command = Command::COMMAND_QUIT;
		return m_command;
	} else {
		m_command = Command::COMMAND_UNEXPECTEDUSERINPUT;
		return m_command;
	}
}

Command UserInput::getCommand() const {
	return m_command;
}

}
