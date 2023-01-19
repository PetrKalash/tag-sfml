#pragma once
#include <SFML/Graphics.hpp>
#include <tag.h>

class Game
{
public:
	enum class Mouse
	{
		LEFT_CLICK,
		RIGHT_CLICK,
		MAX_MOUSE_VALUES
	};

protected:
	sf::RenderWindow main_window;
	sf::Texture texture_background;
	sf::Sprite sprite_backround;

private:
	void event_processing();
	void tag_game(Mouse mouse_click);
	void draw_window();

	Tag m_tag;

public:
	Game();

	void start_game();
};