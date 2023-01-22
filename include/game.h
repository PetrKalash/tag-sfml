#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "tag.h"

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
	sf::ContextSettings settings;
	sf::RenderWindow main_window;

	sf::Texture texture_background;
	sf::Sprite sprite_backround;

	sf::Clock clock;
	int32_t seconds{};
	int32_t minuts{};

	sf::Font font_time;
	std::stringstream print_time;

private:
	void event_processing();
	void tag_game(Mouse mouse_click);
	void draw_window();

	static float m_timer;
	static float m_minuts;

	Tag m_tag;

public:
	Game();

	void start_game();
};