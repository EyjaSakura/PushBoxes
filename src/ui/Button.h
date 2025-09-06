#pragma once
#include<SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape shape;
	sf::Text text;
	bool prevClicked{ false };

	bool isMouseOver(sf::RenderWindow& window)const;
	bool isClicked(sf::RenderWindow& window)const;

public:
	Button(const std::string& btnText, sf::Vector2f size, sf::Vector2f position);
	
	void draw(sf::RenderWindow& window)const;
	bool updateClicked(sf::RenderWindow& window);	//Ïû¶¶
};