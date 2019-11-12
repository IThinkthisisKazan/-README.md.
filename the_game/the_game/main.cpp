#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(600, 400), "Lesson 1. kychka-pc.ru");
	
	Image heroimage;
	heroimage.loadFromFile("image/hero_3.png");

	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	float currentFrame = 0;

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 65, 35, 65));
	herosprite.setPosition(50, 25);

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Left))

		{
			herosprite.move(-0.1* time, 0);   //первая координата Х отрицательна =>идём влево
			currentFrame += 0.01;
			if (currentFrame > 4) currentFrame -= 4;
			herosprite.setTextureRect(IntRect(35 * int(currentFrame) + 40, 65, -35, 65));
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
		
		{ herosprite.move(0.1* time, 0);
		currentFrame += 0.01;
		if (currentFrame > 4) currentFrame -= 4;
         herosprite.setTextureRect(IntRect(38*int(currentFrame), 65, 35, 65));} //первая координата Х положительна =>идём вправо
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		
		{ herosprite.move(0, -0.1* time); } //вторая координата (У) отрицательна =>идём вверх

		if (Keyboard::isKeyPressed(Keyboard::Down)) 
		{ herosprite.move(0, 0.1* time); } //вторая координата (У) положительна =>идём вниз 

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}

