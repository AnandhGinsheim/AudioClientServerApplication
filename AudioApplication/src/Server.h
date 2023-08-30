/*
 * Server.h
 *
 *  Created on: 2 Aug 2023
 *      Author: Anandh
 */
#include <string>
#include <SFML/Network.hpp>
#include <iostream>
#include "InstanceFactory.h"
#ifndef SERVER_H_
#define SERVER_H_

namespace audio_app {

class Server {
public:
	ServerStatus startServer();
	ServerStatus stopServer();
	ServerStatus getServerStatus() const;

private:
	ServerStatus m_serverstatus;
};

}

#endif /* SERVER_H_ */
