#include "InstanceFactory.h"

namespace audio_app {

template<typename T>
std::unique_ptr<T> InstanceFactory<T>::m_Ptr = nullptr;

template<typename T>
std::unique_ptr<T>& InstanceFactory<T>::getInstance() {
	if (m_Ptr == nullptr) {
		m_Ptr = std::make_unique<T>();
	}
	return m_Ptr;
}

template class InstanceFactory<sf::Music> ;
template class InstanceFactory<sf::TcpListener> ;
template class InstanceFactory<sf::TcpSocket> ;
template class InstanceFactory<Server> ;
template class InstanceFactory<AudioModel> ;
template class InstanceFactory<UserInput> ;
template class InstanceFactory<AudioController> ;
template class InstanceFactory<ApplicationMain> ;

}
