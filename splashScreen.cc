#include "stdafx.h"
#include "splashScreen.h"
using namespace std;

void SplashScreen::Show(sf::RenderWindow &renderWindow)
{
    sf::Texture texture;
    if (!texture.loadFromFile("images/pangTitle.jpg"))
    {
        cerr << "Error: title image not found" << endl;
        return;
    }

    sf::Sprite sprite(texture);

    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;
    while (true)
    {
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed
                    || event.type == sf::Event::MouseButtonPressed
                    || event.type == sf::Event::Closed)
            {
                return;
            }
        }
    }
}
