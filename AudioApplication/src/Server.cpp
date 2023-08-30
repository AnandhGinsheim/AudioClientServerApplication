/*
 * Server.cpp
 *
 *  Created on: 2 Aug 2023
 *      Author: Anandh
 */

#include "Server.h"

namespace audio_app {

ServerStatus Server::startServer() {
	std::cout << "Server socket creation" << std::endl;

	if (InstanceFactory<sf::TcpListener>::getInstance()->listen(53740)
			!= sf::Socket::Done) {
		std::cout << "Server : Cannot listen to port  " << std::endl;
		return ServerStatus::SERVER_ERRORPORTBINDING;
	}

	if (InstanceFactory<sf::TcpListener>::getInstance()->accept(
			*(InstanceFactory<sf::TcpSocket>::getInstance()))
			!= sf::Socket::Done) {
		std::cout << "Server : Cannot accept client  " << std::endl;
		return ServerStatus::SERVER_ERRORCLIENTCONNECTION;
	}
	std::cout << "Server : Server started  " << std::endl;
	return ServerStatus::SERVER_STARTED;
}

ServerStatus Server::stopServer() {
	return ServerStatus::SERVER_STOPPED;
}

ServerStatus Server::getServerStatus() const {
	return m_serverstatus;
}

}
