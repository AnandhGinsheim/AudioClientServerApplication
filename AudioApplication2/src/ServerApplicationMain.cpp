#include <iostream>
#include <windows.h>
#include <SFML/Audio/Music.hpp>
#include <SFML/Network.hpp>


sf::Music music;
char command = 0;
char previouscommand = 0;
void action() {
	std::cout << "Action function called" << std::endl;
	std::cout << "Music status " << music.getStatus() << std::endl;
	if ((music.getStatus() == sf::Music::Stopped
			&& (command == 'p' || command == 's'))
			|| (music.getStatus() == sf::Music::Paused
					&& (command == 'p' || command == 's'))) {
		music.play();
		std::cout << "Music is playing " << music.getStatus() << std::endl;
	} else if ((music.getStatus() == sf::Music::Playing && command == 's')) {
		music.pause();
		std::cout << "Music paused " << music.getStatus() << std::endl;
	}
}
int main() {

	std::cout << "Server socket creation" << std::endl;

	sf::TcpListener listener;

	// bind the listener to a port
	if (listener.listen(53740) != sf::Socket::Done) {
		std::cout << "Server : Cannot listen to port  " << std::endl;
	}

	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done) {
		std::cout << "Server : Cannot accept client  " << std::endl;
	}

	char dataReceived[2];
	std::size_t received;

	if (!music.openFromFile("MusicSample1.mp3")) {

		std::cout << "Error Loading file : " << std::endl;
	} else {
		std::cout << "Music loaded successfully" << std::endl;
		std::cout << "Start listening to client" << std::endl;
	while(1){
// TCP socket:
	if (client.receive(dataReceived, 2, received) != sf::Socket::Done) {
		std::cout << "Server : Error in receiving the data  " << std::endl;
	}else{
	std::cout << "Server Received " << received << " bytes" << std::endl;
	std::cout << "Data from client is " << dataReceived << " bytes"
			<< std::endl;
	command = dataReceived[0];
		if (command == 'q'){
			std::cout << "Server exit "  << std::endl;
			return 0;
		}else{
								action();
								Sleep(1000);
		}
	}
	Sleep(1000);
	}
	}
	std::cout << "Exit program" << std::endl;
				return 0;
}

