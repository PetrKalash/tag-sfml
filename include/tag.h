#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <random>

class Tag
{
protected:
	sf::Texture texture_tag;

private:
	std::array<std::array<int32_t, 6>, 6> m_logic_tiles;
	std::array<sf::Sprite, 17> m_sprite_tiles;

public:
	Tag();

	// Генерация случайного числа для ячейки на игровом поле
	int32_t get_random_number();
	// Перемешивание ячеек
	void swap_tiles(int32_t &x_mouse, int32_t &y_mouse, int32_t &dx, int32_t &dy);
	// Перемещение ячейки
	void new_set_position(sf::RenderWindow &main_window);

	std::array<sf::Sprite, 17> get_sprite_tiles() const;
	std::array<std::array<int32_t, 6>, 6> get_logic_tiles() const;
};