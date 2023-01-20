#include "game.h"

Game::Game()
{
    sf::ContextSettings settings; settings.antialiasingLevel = 8;
    main_window.create(sf::VideoMode(572, 572), "Tag", sf::Style::Default, settings);
    // Задаем максимальную частоту кадров (иначе эффект анимации может быть незаметен)
    main_window.setFramerateLimit(60);
}

void Game::start_game()
{
    while (main_window.isOpen()) 
    {
        event_processing();
        draw_window();
    }
}

void Game::event_processing()
{
    sf::Event e;
    while (main_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed) main_window.close();

        if (e.type == sf::Event::MouseButtonPressed)
        {
            if (e.key.code == sf::Mouse::Left) tag_game(Mouse::LEFT_CLICK);
        }
    }
}

void Game::tag_game(Mouse mouse_click)
{
    std::array<sf::Sprite, 17> sprite = m_tag.get_sprite_tiles();
    std::array<std::array<int32_t, 6>, 6> logic = m_tag.get_logic_tiles();

    sf::Vector2i pos = sf::Mouse::getPosition(main_window);
    int32_t x_mouse = pos.x / 144 + 1;
    int32_t y_mouse = pos.y / 144 + 1;

    int32_t dx{}, dy{};

    switch (mouse_click)
    {
        case Mouse::LEFT_CLICK:
        {
            std::cout << x_mouse << "\t" << y_mouse << std::endl;
            std::cout << logic.at(y_mouse).at(x_mouse) << std::endl;
            // Ищем ячейку с пустым местом вокруг выбранной ячейки
            
            if (logic.at(x_mouse - 1).at(y_mouse) == 16)        { dx = -1; dy = 0; }
            else if (logic.at(x_mouse).at(y_mouse - 1) == 16)   { dx = 0; dy = -1; }
            else if (logic.at(x_mouse).at(y_mouse + 1) == 16)   { dx = 0; dy = 1; }
            else if (logic.at(x_mouse + 1).at(y_mouse) == 16)   { dx = 1; dy = 0; }

            m_tag.swap_tiles(x_mouse, y_mouse, dx, dy);

            // Ставим пустой блок на место выбранного пользователем блока
            sprite[16].move(-dx * 144, -dy * 144);
            // Скорость анимации
            float speed = 6;
            for (int i = 0; i < 144; i += speed)
            {
                // Двигаем выбранный блок
                sprite.at([temp]).move(speed*dx, speed*dy);
                // Отрисовываем пустой блок
                main_window.draw(sprite[16]);
                // Отрисовываем выбранный блок
                main_window.draw(sprite.at([temp]));
                // Отображаем всю композицию в окне
                main_window.display();
            }
        }
    }
}

void Game::draw_window()
{
    std::array<sf::Sprite, 17> sprite = m_tag.get_sprite_tiles();
    std::array<std::array<int32_t, 6>, 6> logic = m_tag.get_logic_tiles();

    main_window.clear(sf::Color::White);

    for (size_t x{0}; x < logic.size() - 2; ++x)
        for (size_t y{0}; y < logic.size() - 2; ++y) {
            sprite.at(logic.at(x + 1).at(y + 1)).setPosition(x * 144, y * 144);
            main_window.draw(sprite.at(logic.at(x + 1).at(y + 1)));
        }

    main_window.display();
}