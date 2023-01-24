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
	// Общее время игры
	void all_time();
	// Обработка событий
	void event_processing();
	// Изменение программы
	void tag_game(Mouse mouse_click);
	// Отрисовка окна
	void draw_window();

	// Измерение времени в игре
	static float m_timer;
	static float m_minuts;

	// Экземпляр пятнашек
	Tag m_tag;

public:
	Game();
	// Начало игры
	void start_game();
};