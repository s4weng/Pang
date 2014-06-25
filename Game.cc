#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "splashScreen.h"
using namespace std;

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
PlayerPaddle Game::_player1;

void Game::Start()
{
    if (_gameState != Uninitialized)
    {
        cerr << "Error: game already in session" << endl;
        return;
    }
    _mainWindow.create(sf::VideoMode(1024, 768), "Pang!");
    
    _player1.Load("images/paddle.png");
    _player1.SetPosition((1024/2)-45,700);

    _gameState = Game::ShowingSplash;

    while (!isExiting())
    {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::isExiting()
{
    if (_gameState == Game::Exiting) return true;
    else return false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    while (_mainWindow.pollEvent(currentEvent))
    {
        switch (_gameState)
        {
        case Game::ShowingMenu:
        {
            ShowMenu();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }

        case Game::Playing:
        {
            sf::Event currentEvent;
            while (_mainWindow.pollEvent(currentEvent))
            {
                _mainWindow.clear(sf::Color(255, 0, 0));
                _player1.Draw(_mainWindow);
                _mainWindow.display();

                if (currentEvent.type == sf::Event::Closed)
                {
                    _gameState = Game::Exiting;
                }

                if (currentEvent.type == sf::Event::KeyPressed)
                {
                    if (currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
                }
            }
            break;
        }
        }
    }
}


void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
    switch (result)
    {
    case MainMenu::Exit:
        _gameState = Game::Exiting;
        break;
    case MainMenu::Play:
        _gameState = Game::Playing;
        break;
    }
}
