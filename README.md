# AudioClientServerApplication
Project Name - AudioApplication for Server application. Project Name - AudioClient for client application.
Author: Anandh
About this Readme file: Gives an overview of the application.
Project Name: AudioApplication for Server application.  AudioClient for client application.
Features Implemented: P for playing the music, S for stoping the music, q for quiting the application.
Music file - It is predefined.MusicSample1.mp3.
Library used: SFML.

High Level Design on Server side:
MVC pattern - Model View Controller pattern.
AudioModel is the Model of the application.
Server,UserInput are view of the server.
AudioController is the controller part.

Class details on Server side :
ApplicationMain has main function, starts the server, Loads the file and Start listening to client.
AudioController process the command received from the client.
InstanceFactory provides interface for all the objects used by the application with smart pointers.
AudioModel provides access to Music file by loading it.
Server provides the implementaion and interface to start the server.
UserInput check and converts text received from the client to command required by server.
Constants has all enumerations defined.  

TODO or Required Code Improvement:
1. Comments are missing. It is to be added.
2. Message box can be added to store the received data from the client and processed accordingly.
3. Authentication and Session is missing for server application.
4. IP, portnumber, Music name are hardcoded. It should be avoided.
5. Trace class to be used instead of standard library std::cout interface.
6. Member variables to be initialised with default values.
7. AudioClient application is not checked for improvement. 



