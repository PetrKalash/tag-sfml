#include "tag.h"

Tag::Tag() : m_logic_tiles{}
{
	texture_tag.loadFromFile("resources\\img\\tiles.jpg");

	int32_t s{1};
	// �������� ������� � ��������
	for (size_t i{}; i < m_logic_tiles.size() - 2; ++i) {
		for (size_t j{}; j < m_logic_tiles.size() - 2; ++j) {
			// ���������� �� ���� �������� � �������� ������� ������
			m_sprite_tiles.at(s).setTexture(texture_tag);
			m_sprite_tiles.at(s).setTextureRect(sf::IntRect(i * 144, j * 144, 144, 144));
			// � ������� ������� ���� ���������� ����� - ��� ������ �� ������� ����
			m_logic_tiles.at(i + 1).at(j + 1) = s++;
		}
	}

	// ������������ ��������������� ������ � ��������� ������� ���� � ������
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

std::array<sf::Sprite, 17> Tag::get_sprite_tiles() const
{
	return m_sprite_tiles;
}

std::array<std::array<int32_t, 6>, 6> Tag::get_logic_tiles() const
{
	return m_logic_tiles;
}