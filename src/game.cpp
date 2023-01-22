#include "game.h"
#include <iostream>

float Game::m_timer = 0;
float Game::m_minuts = 0;

Game::Game()
{
    settings.antialiasingLevel = 8;
    // Создание главного окна
    main_window.create(sf::VideoMode(885, 572), "Tag", sf::Style::Default, settings);
    // Максимальная частота кадров
    main_window.setFramerateLimit(60);
    // Загрузка шрифта для времени
    font_time.loadFromFile("resources\\fonts\\Comic-Sans MS.ttf");
}

void Game::start_game()
{
    while (main_window.isOpen()) 
    {
        print_time.str("");
        seconds = clock.getElapsedTime().asSeconds();

        minuts = seconds / 60;
        seconds = seconds - minuts * 60;

        if (minuts < 10) print_time << "0" << minuts;
        else print_time << minuts;

        if (seconds < 10) print_time << ":" << "0" << seconds;
        else print_time << ":" << seconds;

        sf::Text text_time(std::to_string(m_timer), font_time, 40);
        text_time.setFillColor(sf::Color::Black);
        text_time.setPosition(768, 77);


        text_time.setString(print_time.str());
        main_window.draw(text_time);
        main_window.display();

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
    int32_t x_mouse = pos.x / 143 + 1;
    int32_t y_mouse = pos.y / 143 + 1;

    int32_t dx{}, dy{};

    switch (mouse_click)
    {
        case Mouse::LEFT_CLICK:
        {
            // Ищем ячейку с пустым местом вокруг выбранной ячейки      
            if (logic.at(x_mouse - 1).at(y_mouse) == 16)        { dx = -1; dy = 0; }
            else if (logic.at(x_mouse).at(y_mouse - 1) == 16)   { dx = 0; dy = -1; }
            else if (logic.at(x_mouse).at(y_mouse + 1) == 16)   { dx = 0; dy = 1; }
            else if (logic.at(x_mouse + 1).at(y_mouse) == 16)   { dx = 1; dy = 0; }

            m_tag.swap_tiles(x_mouse, y_mouse, dx, dy);
        }
    }
}

void Game::draw_window()
{
    std::array<sf::Sprite, 17> sprite = m_tag.get_sprite_tiles();
    std::array<std::array<int32_t, 6>, 6> logic = m_tag.get_logic_tiles();

    main_window.clear(sf::Color::White);

    for (size_t x{0}; x < logic.size() - 2; ++x) {
        for (size_t y{0}; y < logic.size() - 2; ++y) {
            sprite.at(logic.at(x + 1).at(y + 1)).setPosition(x * 144, y * 144);
            main_window.draw(sprite.at(logic.at(x + 1).at(y + 1)));
        }
    }

    main_window.display();
}