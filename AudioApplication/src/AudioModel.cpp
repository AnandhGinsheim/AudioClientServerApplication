#include <iostream>
#include "AudioModel.h"

namespace audio_app {

FileLoadStatus AudioModel::loadAudioFile() {
	if (!(InstanceFactory<sf::Music>::getInstance()->openFromFile(
			"MusicSample1.mp3"))) {
		std::cout << "Error Loading file : " << std::endl;
		return FileLoadStatus::FILELOADSTATUS_ERROR;
	} else {
		std::cout << "Music loaded successfully" << std::endl;
		std::cout << "Loading audio file: " << "MusicSample1.mp3" << std::endl;
		return FileLoadStatus::FILELOADSTATUS_SUCCESSFULLYLOADED;
	}
}

FileLoadStatus AudioModel::unloadAudioFile() {
	return FileLoadStatus::FILELOADSTATUS_SUCCESSFULLYUNLOADED;
}

}

