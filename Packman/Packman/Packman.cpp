#include "stdafx.h"
#include "Packman.h"

using namespace sf;
using namespace std;

Packman::Packman(float x, float y, Map *mapa)
{
	map = mapa;
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
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {

		object.setRotation(180);
		if (checkCollision(velocityVectorLeft)) 
			object.move(velocityVectorLeft);
		else if (checkCollision(sf::Vector2f(-1, 0))) 
			object.move(sf::Vector2f(-1, 0));

	} else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

		object.setRotation(0);
		if (checkCollision(velocityVectorRight))
		    object.move(velocityVectorRight);
		else if (checkCollision(sf::Vector2f(1, 0)))
			object.move(sf::Vector2f(1, 0));

	} else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

		object.setRotation(270);
		if (checkCollision(velocityVectorTop))
		    object.move(velocityVectorTop);
		else if (checkCollision(sf::Vector2f(0, -1)))
			object.move(sf::Vector2f(0, -1));

	} else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		object.setRotation(90);
		if (checkCollision(velocityVectorBottom))
		    object.move(velocityVectorBottom);
		else if (checkCollision(sf::Vector2f(0, 1)))
			object.move(sf::Vector2f(0, 1));
	}
}

void Packman::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->object, state);
}


