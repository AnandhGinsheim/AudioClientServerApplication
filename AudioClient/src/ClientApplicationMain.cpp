#include <iostream>
#include <windows.h>
#include <SFML/Network.hpp>

char command = 0;
char previouscommand = 0;

int main() {

	std::cout << "Client socket creation " << std::endl;
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("127.0.0.1", 53740);
	if (status != sf::Socket::Done) {
		std::cout << "Client : Error in creating client socket" << std::endl;
	}

	std::cout << "Starting Audio Application" << std::endl;
	std::cout << "Enter p to play : " << std::endl;
	std::cout << "Enter p to pause when playing: " << std::endl;
	std::cout << "Enter s to start playing from the beginning  : " << std::endl;
	std::cout << "Enter s to stop when playing: " << std::endl;
	std::cout << "Enter x to exit the program " << std::endl;

	char dataSent[2] = "A";
	while (1) {
		std::cin >> command;
		std::cout << "Client : command received from user : " << command << std::endl;
		if (command == 'q' || command == 'p' || command == 's') {
			dataSent[0] = command;
			// TCP socket:
			if (socket.send(dataSent, 2) != sf::Socket::Done) {
				std::cout << "Client : Error creating socket  " << std::endl;
			}
			if (command == 'q') {
				std::cout << "Client : Exit client program" << std::endl;
				return 0;
			}
		} else {
			std::cout << "Enter correct value p S or q" << std::endl;
		}
	}
	std::cout << "Exit program" << std::endl;
	return 0;
}

