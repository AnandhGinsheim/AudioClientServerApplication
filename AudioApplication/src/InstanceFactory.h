#ifndef INSTANCEFACTORY_H
#define INSTANCEFACTORY_H
#include "Constants.h"
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "AudioController.h"
#include "AudioModel.h"
#include "Server.h"
#include "UserInput.h"
#include "ApplicationMain.h"

namespace audio_app {

template<typename T>
class InstanceFactory {
public:
	static std::unique_ptr<T>& getInstance();

private:
	static std::unique_ptr<T> m_Ptr;

};

}
#endif
