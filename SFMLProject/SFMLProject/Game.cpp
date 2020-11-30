#include "Game.h"

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sprites, text , player and collisions");

	srand(time(NULL));

	bool inGame{ true };

	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	Player newPlayer;
	newPlayer.initialise(window);

	// set timePerFrame to 1 60th of a second. 60 frames per second

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.

	sf::Clock clock;

	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on.
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//add to the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.

		if (timeSinceLastUpdate > timePerFrame)
		{
			if (inGame)
			{
				newPlayer.animate();

				newPlayer.direction = sf::Vector2f(0, 0);
				// get keyboard input.

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					newPlayer.direction = sf::Vector2f(-newPlayer.playerSpeed, 0);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					newPlayer.direction = sf::Vector2f(newPlayer.playerSpeed, 0);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					newPlayer.direction = sf::Vector2f(0, -newPlayer.playerSpeed);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					newPlayer.direction = sf::Vector2f(0, newPlayer.playerSpeed);
				}

				newPlayer.move();

				if (newPlayer.sprite.getPosition().x < 0)
				{
					newPlayer.sprite.setPosition(window.getSize().x - newPlayer.sprite.getGlobalBounds().width,
						newPlayer.sprite.getPosition().y);
				}
			}

			window.clear();

			if (inGame)
			{
				newPlayer.draw(window);
			}

			window.display();

			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
}
