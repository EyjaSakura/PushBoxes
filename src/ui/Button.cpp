#include"ui/Button.h"
#include"common/Resources.h"

Button::Button(const std::string& btnText, sf::Vector2f size, sf::Vector2f position) :text(Resources::getMainFont(), btnText, 40), prevClicked(false) {
	
	shape.setSize(size);
	shape.setPosition(position);
	shape.setFillColor(sf::Color::White);
	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(20);

	text.setFillColor(sf::Color::Black);

	auto bounds = text.getLocalBounds();
	text.setPosition({
		position.x + (size.x - bounds.size.x) / 2,
		position.y + (size.y - bounds.size.y) / 2
		});
}

void Button::draw(sf::RenderWindow& window)const {
	window.draw(shape);
	window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window)const {
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	auto bounds = shape.getGlobalBounds();
	return bounds.contains(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)));
}

bool Button::isClicked(sf::RenderWindow& window)const {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) { return true; }
	return false;
}

//Ïû¶¶
bool Button::updateClicked(sf::RenderWindow& window) {
	bool curClicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	bool clicked = !prevClicked && curClicked && this->isMouseOver(window);
	prevClicked = curClicked;
	return clicked;
}