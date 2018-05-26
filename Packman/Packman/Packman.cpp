#include "stdafx.h"
#include "Packman.h"

using namespace sf;
using namespace std;

Packman::Packman(float x, float y, Map *mapa, Game *gra)
{
	map = mapa;
	game = gra;
	width = 23;
	height = 23;
	texture.loadFromFile("packman.png");
	object.setTexture(texture);

	Vector2f textureSize{ texture.getSize() };
	Vector2f sizeVector{(float)(width), (float)height };
	Vector2f scaleVector( sizeVector.x / textureSize.x, sizeVector.y / textureSize.y );

	object.setScale(scaleVector);
	object.setPosition(x, y);
	object.setOrigin(width/2,height/2);
}

void Packman::update()
{
	bool keyFlag = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {

		if (checkCollision(velocityVectorLeft)) {

			object.move(velocityVectorLeft);
			object.setRotation(180);
			keyFlag = true;
			lastMovment = 1;
		} else if (checkCollision(sf::Vector2f(-1.1, 0))) {

			object.move(sf::Vector2f(-1, 0));
			object.setRotation(180);
			keyFlag = true;
			lastMovment = 1;
		}
	} 
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

		if (checkCollision(velocityVectorRight)) {

			object.move(velocityVectorRight);
			object.setRotation(0);
			keyFlag = true;
			lastMovment = 2;
		} else if (checkCollision(sf::Vector2f(1.1, 0))) {

			object.move(sf::Vector2f(1, 0));
			object.setRotation(0);
			keyFlag = true;
			lastMovment = 2;
		}
	} 
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		
		if (checkCollision(velocityVectorTop)) {

			object.move(velocityVectorTop);
			object.setRotation(270);
			keyFlag = true;
			lastMovment = 3;
		} else if (checkCollision(sf::Vector2f(0, -1.1))) {

			object.move(sf::Vector2f(0, -1));
			object.setRotation(270);
			keyFlag = true;
			lastMovment = 3;
		}
	} 
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		if (checkCollision(velocityVectorBottom)) {

			object.move(velocityVectorBottom);
		    object.setRotation(90);
			keyFlag = true;
			lastMovment = 4;
	    } else if (checkCollision(sf::Vector2f(0, 1.1))) {

			object.move(sf::Vector2f(0, 1));
		    object.setRotation(90);
			keyFlag = true;
			lastMovment = 4;
	    }
	}

	if (!keyFlag) {

		makeMove(lastMovment);
	}
}

void Packman::makeMove(int direction)
{
	if (direction == 1) {

		if (checkCollision(velocityVectorLeft)) {

			object.move(velocityVectorLeft);
			object.setRotation(180);
		}
		else if (checkCollision(sf::Vector2f(-1, 0))) {

			object.move(sf::Vector2f(-1, 0));
			object.setRotation(180);
		}
	} else if (direction == 2) {

		if (checkCollision(velocityVectorRight)) {

			object.move(velocityVectorRight);
			object.setRotation(0);
		}
		else if (checkCollision(sf::Vector2f(1, 0))) {

			object.move(sf::Vector2f(1, 0));
			object.setRotation(0);
		}
	} else if (direction == 3) {

		if (checkCollision(velocityVectorTop)) {

			object.move(velocityVectorTop);
			object.setRotation(270);
		}
		else if (checkCollision(sf::Vector2f(0, -1))) {

			object.move(sf::Vector2f(0, -1));
			object.setRotation(270);
		}
	} else if (direction == 4) {

		if (checkCollision(velocityVectorBottom)) {

			object.move(velocityVectorBottom);
			object.setRotation(90);
		}
		else if (checkCollision(sf::Vector2f(0, 1))) {

			object.move(sf::Vector2f(0, 1));
			object.setRotation(90);
		}
	}
}

void Packman::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->object, state);
}


