#include "game.h"

int main(int argc, char *argv[])
{
    // Начало игры
    Game game;
    game.start_game();

    return 0;
}
//
//#include<SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
//#include<iostream>
//#include<sstream>
//
//using namespace std;
//using namespace sf;
//
//RenderWindow W(VideoMode(800,600,32),"Zegar", Style::Titlebar | Style::Close);
//
//int main()
//{
//    W.setFramerateLimit(60);
//    srand(time(NULL));
//
//    Clock clock;
//    stringstream print;
//
//    int32_t seconds{};
//    int32_t minuts{};
//
//    Font czcionka;
//    czcionka.loadFromFile("resources\\fonts\\Comic-Sans MS.ttf");
//
//    Text tekst("", czcionka);
//    tekst.setPosition(200,200);
//    tekst.setCharacterSize(100);
//    tekst.setColor(Color::Black);
//
//    Event e;
//    while(W.isOpen())
//    {
//        while(W.pollEvent(e))
//        {
//            if(e.type==Event::Closed || (Keyboard::isKeyPressed(Keyboard::Escape))) W.close();
//        }
//
//        W.clear(Color::White);
//
//        print.str("");
//        seconds = clock.getElapsedTime().asSeconds();
//
//        minuts = seconds / 60;
//        seconds = seconds - minuts * 60;
//        
//        if (minuts < 10) print << "0" << minuts;
//        else print << minuts;
//
//        if (seconds < 10) print << ":" << "0" << seconds;
//        else print << ":" << seconds;
//
//        tekst.setString(print.str());
//
//        W.draw(tekst);
//        W.display();
//    }
//
//    return 0;
//}