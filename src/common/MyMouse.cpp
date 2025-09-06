#include"common/MyMouse.h"

bool MyMouse::isLeftBtnClick() {
	static bool prevPressed = false;
	bool curPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	bool clicked = !prevPressed && curPressed;
	prevPressed = curPressed;
	return clicked;
}