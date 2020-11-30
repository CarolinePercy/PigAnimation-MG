// Game with text, shapes,sprites and collision

// Author Caroline Percy
// Date: 16/11/2020
// Brief: A 2D shooter, similar to space invaders, where the player fights off waves of enemies using guns. Once an enemy dies, they do not come back, but they will if they reach the bottom of the screen.
// Every 5-10 seconds an extra life floats down from the top, which the player will get if they hit off it (they start with three)
// player wins if they destroy all the enemies, the enemies win if the player runs out of lives


#ifdef _DEBUG

#pragma comment(lib,"sfml-graphics-d.lib")

#pragma comment(lib,"sfml-audio-d.lib")

#pragma comment(lib,"sfml-system-d.lib")

#pragma comment(lib,"sfml-window-d.lib")

#pragma comment(lib,"sfml-network-d.lib")

#else

#pragma comment(lib,"sfml-graphics.lib")

#pragma comment(lib,"sfml-audio.lib")

#pragma comment(lib,"sfml-system.lib")

#pragma comment(lib,"sfml-window.lib")

#pragma comment(lib,"sfml-network.lib")

#endif

#include "Game.h"

int main()
{
	Game game;

	game.run();

	return 0;
}