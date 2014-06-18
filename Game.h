#ifndef _GAME_H__
#define _GAME_H__

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Game
{
	
	public:
	static void Start();

	private:
	static bool isExiting();
	static void GameLoop();

	enum GameState { Uninitialized, ShowSplash, Paused, ShowingMenu,
	Playing, Exiting };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};

#endif