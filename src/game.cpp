#include "game.h"

float Game::m_timer = 0;
float Game::m_minuts = 0;

Game::Game()
{
    // Сглаживание текстур
    settings.antialiasingLevel = 8;
    // Создание главного окна
    main_window.create(sf::VideoMode(649, 667), "Tag", sf::Style::Default, settings);
    // Максимальная частота кадров
    main_window.setFramerateLimit(200);

    // Шрифт времени
    font_time.loadFromFile("resources\\fonts\\Comic-Sans MS.ttf");

    // Задний фон игры
    texture_background.loadFromFile("resources\\img\\background.jpg");
    sprite_backround.setTexture(texture_background);
}

void Game::start_game()
{
    while (main_window.isOpen()) 
    {
        all_time();
        event_processing();
        draw_window();
    }
}

void Game::all_time()
{
    print_time.str("");
    seconds = clock.getElapsedTime().asSeconds();

    minuts = seconds / 60;
    seconds = seconds - minuts * 60;

    if (minuts < 10) print_time << "0" << minuts;
    else print_time << minuts;

    if (seconds < 10) print_time << ":" << "0" << seconds;
    else print_time << ":" << seconds;
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

    int32_t x_mouse = (pos.x - 35) / 144 + 1;
    int32_t y_mouse = (pos.y - 52) / 144 + 1;

    int32_t dx{}, dy{};

    switch (mouse_click)
    {
        case Mouse::LEFT_CLICK:
        {
            // Проверка на выход за границы игрового поля
            if (x_mouse > 5 || y_mouse > 5 || pos.x < 35 || pos.y < 52) break;

            // Ищем ячейку с пустым местом вокруг выбранной ячейки      
            if (logic.at(x_mouse - 1).at(y_mouse) == 16)        { dx = -1; dy = 0; }
            else if (logic.at(x_mouse).at(y_mouse - 1) == 16)   { dx = 0; dy = -1; }
            else if (logic.at(x_mouse).at(y_mouse + 1) == 16)   { dx = 0; dy = 1;  }
            else if (logic.at(x_mouse + 1).at(y_mouse) == 16)   { dx = 1; dy = 0;  }

            // Меняем ячейки местами
            m_tag.swap_tiles(x_mouse, y_mouse, dx, dy);

            // Устанавливаем пустой блок внутри выбранного (выбранный блок находится поверх пустого)
            sprite.at(16).move(-dx * 144, -dy * 144);

            // Скорость анимации
            int32_t speed{4};

            for(int32_t i{}; i < 144; i += speed) {
                // Передвигаем выбранный блок
                sprite.at(logic.at(x_mouse).at(y_mouse)).move(speed * dx, speed * dy);
                // Отрисовываем пустой блок
                main_window.draw(sprite.at(16));
                // Отрисовываем выбранный блок
                main_window.draw(sprite.at(logic.at(x_mouse).at(y_mouse)));
                // Отрисовка всего окна
                main_window.display();
            }
        }
    }
}

void Game::draw_window()
{
    main_window.clear(sf::Color::White);
    main_window.draw(sprite_backround);

    sf::Text text_time(std::to_string(m_timer), font_time, 30);
    text_time.setFillColor(sf::Color::Black);
    text_time.setPosition(292, 9);

    text_time.setString(print_time.str());
    main_window.draw(text_time);

    m_tag.new_set_position(main_window);

    main_window.display();
}