#include "tag.h"

Tag::Tag() : m_logic_tiles{}
{
	texture_tag.loadFromFile("resources\\img\\tiles2.jpg");

	int32_t s{1};
	// ¬ырезаем спрайты у текстуры
	for (int32_t i{}; i < m_logic_tiles.size() - 2; ++i) {
		for (int32_t j{}; j < m_logic_tiles.size() - 2; ++j) {
			// ѕроходимс€ по всей текстуре и вырезаем игровые €чейки
			m_sprite_tiles.at(s).setTexture(texture_tag);
			m_sprite_tiles.at(s).setTextureRect(sf::IntRect(i * 144, j * 144, 144, 144));
			// ” каждого спрайта свой уникальный номер - его индекс на игровом поле
			m_logic_tiles.at(i + 1).at(j + 1) = s++;
		}
	}
}

void Tag::swap_tiles(int32_t &y_mouse, int32_t &x_mouse, int32_t &dx, int32_t &dy)
{
	std::swap(m_logic_tiles.at(y_mouse).at(x_mouse), m_logic_tiles.at(y_mouse + dx).at(x_mouse + dy));
}

std::array<sf::Sprite, 17> Tag::get_sprite_tiles() const
{
	return m_sprite_tiles;
}

std::array<std::array<int32_t, 6>, 6> Tag::get_logic_tiles() const
{
	return m_logic_tiles;
}