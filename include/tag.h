#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

class Tag
{
protected:
	sf::Texture texture_tag;
	sf::Sprite sprite_tag;

private:
	std::array<std::array<int32_t, 6>, 6> m_logic_tiles;
	std::array<sf::Sprite, 17> m_sprite_tiles;

public:
	Tag();

	void swap_tiles(int32_t &y_mouse, int32_t &x_mouse, int32_t &dx, int32_t &dy);

	std::array<sf::Sprite, 17> get_sprite_tiles() const;
	std::array<std::array<int32_t, 6>, 6> get_logic_tiles() const;
};