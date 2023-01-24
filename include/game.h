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
	// ќбщее врем¤ игры
	void all_time();
	// ќбработка событий
	void event_processing();
	// »зменение программы
	void tag_game(Mouse mouse_click);
	// ќтрисовка окна
	void draw_window();

	// »змерение времени в игре
	static float m_timer;
	static float m_minuts;

	// Ёкземпл¤р п¤тнашек
	Tag m_tag;

public:
	Game();
	// Ќачало игры
	void start_game();
};