#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

//Main Body
#define PI 3.1415926535898
float radius_x = 190;
float radius_y = 130;
unsigned short quality = 50;
sf::ConvexShape ellipse;

sf::CircleShape innerCircle1(100);
sf::CircleShape innerCircle2(75);
sf::CircleShape innerCircle3(60);

//Eyes
sf::RectangleShape lineL(sf::Vector2f(80, 3));
sf::RectangleShape lineLSmol(sf::Vector2f(30, 3));

sf::RectangleShape lineR(sf::Vector2f(80, 3));
sf::RectangleShape lineRSmol(sf::Vector2f(30, 3));

//Variables
int lives;

void drawHearts(Sprite heartSprite,Sprite emptySprite, sf::RenderWindow& window) {
	Vector2f currentPosition = Vector2f(130, 100);
	for (int i = 1; i <= lives; i++)
	{
		heartSprite.setPosition(currentPosition);
		window.draw(heartSprite);
		currentPosition.x += 70;
	}

	int lostLives = 5 - lives;
	currentPosition = Vector2f(410, 100);
	for (int i = 1; i <= lostLives; i++)
	{
		emptySprite.setPosition(currentPosition);
		window.draw(emptySprite);
		currentPosition.x -= 70;
	}
}

int main()
{
	//Window
	sf::RenderWindow window(sf::VideoMode(600, 600), "My Window");

	//Inside Body
	innerCircle1.setPosition(200, 275);
	innerCircle2.setPosition(167, 305);
	innerCircle3.setPosition(330, 337);

	//Body
	ellipse.setPointCount(quality);
	for (unsigned short i = 0; i < quality; ++i) {
		float rad = (360 / quality * i) / (360 / PI / 2);
		float x = cos(rad) * radius_x;
		float y = sin(rad) * radius_y;

		ellipse.setPoint(i, sf::Vector2f(x, y));
	};
	ellipse.setPosition(300, 360);
	ellipse.setOutlineColor(Color::Black);
	ellipse.setOutlineThickness(1);

	//Left Eye
	lineL.setPosition(sf::Vector2f(390, 375));
	lineL.rotate(130);
	lineLSmol.setPosition(sf::Vector2f(345, 405));
	lineLSmol.rotate(130);

	//Right Eye
	lineR.setPosition(sf::Vector2f(200, 385));
	lineR.rotate(40);
	lineRSmol.setPosition(sf::Vector2f(247, 403));
	lineRSmol.rotate(40);

	//Red Heart
	Texture heartTexture;
	Sprite heartSprite;
	String filenameHeart;
	filenameHeart = "heart.png";
	heartTexture.loadFromFile(filenameHeart);
	heartSprite.setTexture(heartTexture);
	heartSprite.setPosition(100, 100);
	heartSprite.setScale(Vector2f(3, 3));

	//Empty Heart
	Texture emptyTexture;
	Sprite emptySprite;
	String filenameEmpty;
	filenameEmpty = "border.png";
	emptyTexture.loadFromFile(filenameEmpty);
	emptySprite.setTexture(emptyTexture);
	emptySprite.setPosition(100, 100);
	emptySprite.setScale(Vector2f(3, 3));

	//Colors
	ellipse.setFillColor(sf::Color(200, 230, 240));
	innerCircle1.setFillColor(sf::Color(0, 185, 245));
	innerCircle2.setFillColor(sf::Color(0, 185, 245));
	innerCircle3.setFillColor(sf::Color(0, 185, 245));
	lineL.setFillColor(sf::Color(0, 0, 0));
	lineLSmol.setFillColor(sf::Color(0, 0, 0));
	lineR.setFillColor(sf::Color(0, 0, 0));
	lineRSmol.setFillColor(sf::Color(0, 0, 0));

	//Starting Lives
	lives = 5;

	//Font
	Font font;
	font.loadFromFile("AverageSans-Regular.ttf");
	//Text
	Text text;
	text.setFont(font);
	text.setString("A: Attack\nH: Heal");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Black);
	text.setPosition(5, 5);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			window.clear(sf::Color::White);

			//Draw to Screen (In Order)
			window.draw(ellipse);
			window.draw(innerCircle1);
			window.draw(innerCircle2);
			window.draw(innerCircle3);

			window.draw(lineL);
			window.draw(lineLSmol);
			window.draw(lineR);
			window.draw(lineRSmol);

			//Adjust/Draw Hearts
			drawHearts(heartSprite,emptySprite,window);

			//Attack Logic
			if (lives > 0) {
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					lives--;
				}
			} 
			if (lives < 5) {
				if (Keyboard::isKeyPressed(Keyboard::H)) {
					lives++;
				}
			}
			
			//text
			window.draw(text);

			window.display();
		}
	}


	return 0;
}
