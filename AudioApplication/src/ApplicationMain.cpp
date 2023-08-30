#include "ApplicationMain.h"

namespace audio_app {

char m_dataReceived[2];
std::size_t m_receivedData;

ServerStatus ApplicationMain::startServer() {
	std::cout << "ApplicationMain - Start Server" << std::endl;
	//ServerStatus serverStatus = InstanceFactory<Server>::getInstance()->startServer();
	//return serverStatus;
	return InstanceFactory<Server>::getInstance()->startServer();
}

FileLoadStatus ApplicationMain::loadAudioFile() {
	std::cout << "ApplicationMain - loadAudioFile" << std::endl;
	return InstanceFactory<AudioModel>::getInstance()->loadAudioFile();
}

Command ApplicationMain::receiveData() {
	std::cout << "ApplicationMain - receiveAndProcessData" << std::endl;
	if (InstanceFactory<sf::TcpSocket>::getInstance()->receive(m_dataReceived,
			2, m_receivedData) != sf::Socket::Done) {
		std::cout << "Server : Cannot receive data " << std::endl;
		return Command::COMMAND_CANNOTRECEIVEDATA;
	} else {
		std::cout << "Server Received " << m_receivedData << " bytes"
				<< std::endl;
		std::cout << "Data from client is " << m_dataReceived << " bytes"
				<< std::endl;

		return InstanceFactory<UserInput>::getInstance()->readInputCommand(
				m_dataReceived[0]);
	}
}

ProcessStatus ApplicationMain::processData() {
	return InstanceFactory<AudioController>::getInstance()->processCommand(
			InstanceFactory<UserInput>::getInstance()->getCommand());
}

void ApplicationMain::setExitFlag(const bool t_exitFlag) {
	m_exitFlag = t_exitFlag;
}
bool ApplicationMain::getExitFlag() const {
	return m_exitFlag;
}

}

int main() {
	if (audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->startServer()
			== audio_app::ServerStatus::SERVER_STARTED) {
		if (audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->loadAudioFile()
				== audio_app::FileLoadStatus::FILELOADSTATUS_SUCCESSFULLYLOADED) {
			audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->setExitFlag(
					true);
			while (audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->getExitFlag()) {
				if (audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->receiveData()
						== audio_app::Command::COMMAND_CANNOTRECEIVEDATA) {
					audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->setExitFlag(
							false);
				} else if (audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->processData()
						== audio_app::ProcessStatus::PROCESSSTATUS_QUIT) {
					audio_app::InstanceFactory<audio_app::ApplicationMain>::getInstance()->setExitFlag(
							false);
				}
				sf::sleep(sf::milliseconds(1000));
			}
		}
	}
	return 0;
}

