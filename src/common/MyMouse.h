#include<SFML/Graphics.hpp>

//已经弃用，被以下代码取代：
//if (auto* mb = event->getIf<sf::Event::MouseButtonPressed>()) {
//	if (mb->button == sf::Mouse::Left) {
//		...
//	}
//}
namespace MyMouse {
	bool isLeftBtnClick();
}