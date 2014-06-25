#ifndef _GAME_H__
#define _GAME_H__

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "PlayerPaddle.h"

class Game
{
	
	public:
	static void Start();

	private:
	static bool isExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenu();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu,
	Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static PlayerPaddle _player1;
};

#endif