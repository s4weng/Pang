#include "stdafx.h"
#include "splashScreen.h"
using namespace std;

void SplashScreen::Show(sf::RenderWindow &renderWindow)
{
    sf::Texture texture;
    if (!texture.loadFromFile("images/pangTitle.png"))
    {
        cerr << "Error: title image not found" << endl;
        return;
    }

    sf::Sprite sprite(texture);

    sf::Event event;
    while (renderWindow.isOpen())
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) renderWindow.close();
            if (event.type == sf::Event::KeyPressed) return;
        }
        renderWindow.clear();
        renderWindow.draw(sprite);
        renderWindow.display();
    }
}
