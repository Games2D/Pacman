#include "stdafx.h"
#include "Packman.h"

using namespace sf;
using namespace std;

Packman::Packman(float x, float y)
{
	positionX = x;
	positionY = y;

	texture.loadFromFile("C:/Users/bogusia/Source/Repos/Packman/Packman/Packman/packman.png");
	player.setTexture(texture);

	player.setPosition(positionX, positionY);
	player.setOrigin(width/2,height/2);
}

void Packman::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {

		player.setRotation(180);
		player.move(velocityVectorLeft);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {

		player.setRotation(0);
		player.move(velocityVectorRight);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {

		player.setRotation(270);
		player.move(velocityVectorTop);
	} else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		player.setRotation(90);
		player.move(velocityVectorBottom);
	}

}

void Packman::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->player, state);
}


