#ifndef USERINPUT_H
#define USERINPUT_H
#include <iostream>
#include "Constants.h"

namespace audio_app {

class UserInput {
public:
	Command readInputCommand(const char t_clientInput);
	Command getCommand() const;
private:
	Command m_command;
};

}
#endif
