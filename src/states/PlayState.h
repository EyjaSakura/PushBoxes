#include "states/State.h"
#include "game/Game.h"
#include"map/Map.h"

class PlayState :public State {
private:
	Map map;
	sf::Clock ignoreMouseTimer;
	bool shouleReloadWindow{ true };
public:
	PlayState(Game& game, bool isGamePaused);

	void enter(Game& game);
	void handleEvent(Game& game, const std::optional<sf::Event>& event)override;
	void draw(Game& game);
};