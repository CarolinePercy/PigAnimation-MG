#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	sf::Sprite sprite;
	float playerSpeed{ 1 };
	sf::Vector2f direction;
	sf::Texture playerTexture;

	int totalElapsed{ 0 };
	int animationFrame[2] = { 0,0 };

	void initialise(sf::RenderWindow& t_window)
	{
		if (!playerTexture.loadFromFile("pigwalking.png"))
		{
			// error...
		}
		sprite.setTexture(playerTexture);
	};

	void move()
	{
		sprite.move(direction);
	};

	void animate()
	{
		totalElapsed++;

		if (totalElapsed > 3)
		{
			totalElapsed = 0;

			animationFrame[0] += 128;

			if (animationFrame[0] >= 1024)
			{
				animationFrame[1] += 94;
				animationFrame[0] = 0;
			}

			if (animationFrame[1] >= 282)
			{
				animationFrame[1] = 0;
			}
		}

		sprite.setTextureRect(sf::IntRect(animationFrame[0], animationFrame[1], 128, 94));
	};

	void draw(sf::RenderWindow& t_window)
	{
		t_window.draw(sprite);
	}
};

