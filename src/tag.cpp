#include "tag.h"

Tag::Tag() : m_logic_tiles{}
{
	texture_tag.loadFromFile("resources\\img\\tiles.jpg");

	int32_t s{1};
	// Вырезаем спрайты у текстуры
	for (size_t i{}; i < m_logic_tiles.size() - 2; ++i) {
		for (size_t j{}; j < m_logic_tiles.size() - 2; ++j) {
			// Проходимся по всей текстуре и вырезаем игровые ячейки
			m_sprite_tiles.at(s).setTexture(texture_tag);
			m_sprite_tiles.at(s).setTextureRect(sf::IntRect(i * 144, j * 144, 144, 144));
			// У каждого спрайта свой уникальный номер - его индекс на игровом поле
			m_logic_tiles.at(i + 1).at(j + 1) = s++;
		}
	}

	// Перемешиваем сгенерированные ячейки в случайном порядке друг с другом
	for (size_t i{}; i < m_logic_tiles.size() - 2; ++i) {
		for (size_t j{}; j < m_logic_tiles.size() - 2; ++j) {
			std::swap(m_logic_tiles.at(i + 1).at(j + 1), m_logic_tiles.at(get_random_number()).at(get_random_number()));
		}
	}
}

int32_t Tag::get_random_number()
{
	return 1 + std::mt19937(std::random_device{}())() % (m_logic_tiles.size() - 2);
}

void Tag::swap_tiles(int32_t &x_mouse, int32_t &y_mouse, int32_t &dx, int32_t &dy)
{
	std::swap(m_logic_tiles.at(x_mouse).at(y_mouse), m_logic_tiles.at(x_mouse + dx).at(y_mouse + dy));
}

void Tag::new_set_position(sf::RenderWindow &main_window)
{
	for (size_t x{0}; x < m_logic_tiles.size() - 2; ++x) {
		for (size_t y {0}; y < m_logic_tiles.size() - 2; ++y) {
			m_sprite_tiles.at(m_logic_tiles.at(x + 1).at(y + 1)).setPosition(x * 144, y * 144);
			m_sprite_tiles.at(m_logic_tiles.at(x + 1).at(y + 1)).move(35, 52);
			main_window.draw(m_sprite_tiles.at(m_logic_tiles.at(x + 1).at(y + 1)));
		}
	}
}

std::array<sf::Sprite, 17> Tag::get_sprite_tiles() const
{
	return m_sprite_tiles;
}

std::array<std::array<int32_t, 6>, 6> Tag::get_logic_tiles() const
{
	return m_logic_tiles;
}