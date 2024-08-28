#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

sf::CircleShape sun(100.f); // Sun with a radius of 100
sf::CircleShape moon(100.f); // Moon with a radius of 50

// deltaTime
Time g_preTime;
Clock g_deltaClock;

void Init(sf::RenderWindow& window) {
	sun.setFillColor(sf::Color::Yellow);
	sun.setOrigin(100.0f, 100.0f);
	sun.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f); // Position the sun in the middle

	moon.setFillColor(sf::Color(64, 64, 64)); // A shade of dark gray
	moon.setOrigin(100.0f, 100.0f);
	moon.setPosition(-50.f, window.getSize().y / 2.0f); // Start position of the moon

	// let the clock start to clocking the time 
	g_deltaClock.restart();
	g_preTime = g_deltaClock.getElapsedTime(); // set the default value of previous time
}

void Update(sf::RenderWindow& window) {
	Time currentTime = g_deltaClock.getElapsedTime();   // get the current time
	Time deltaTime = currentTime - g_preTime;           // calculate the delta time
	float deltaSeconds = deltaTime.asSeconds();         // time to seconds
	g_preTime = currentTime;                            // the current time become the preTime for next frame

	// Write your code below to move the moon
	// Move the moon across the window to simulate the eclipse
	// Reset moon position after it moves out of view
	float velocity = 125 * deltaSeconds;
	moon.move(velocity, 0);

	Vector2f moonCurrent = moon.getPosition();
	if (moonCurrent.x >= 850) {
		moon.setPosition(Vector2f(-50.f, window.getSize().y / 2.0f));
	}
	// Write your code above
}

void Render(sf::RenderWindow& window) {
	// Write your code below to set the background color
	Color color = Color(255, 255, 255);
	Vector2f moonCurrent = moon.getPosition();

	if (moonCurrent.x >= 215 && moonCurrent.x < 250 ||
		moonCurrent.x >= 550 && moonCurrent.x < 585)
	{
		color = Color(160, 160, 160);
	}
	else if (moonCurrent.x >= 250 && moonCurrent.x < 310 ||
		moonCurrent.x >= 490 && moonCurrent.x < 550)
	{
		color = Color(120, 120, 120);
	}
	else if (moonCurrent.x >= 310 && moonCurrent.x < 355 ||
		moonCurrent.x >= 445 && moonCurrent.x < 490)
	{
		color = Color(80, 80, 80);
	}
	else if (moonCurrent.x >= 355 && moonCurrent.x < 385 ||
		moonCurrent.x >= 415 && moonCurrent.x < 445) 
	{
		color = Color(40, 40, 40);
	}
	else if (moonCurrent.x >= 385 && moonCurrent.x < 415)
	{
		color = Color(0, 0, 0);
	}
	else {
		color = Color(255, 255, 255);
	}

	/*
	Time currentTime = g_deltaClock.getElapsedTime();   // get the current time
	Time deltaTime = currentTime - g_preTime;           // calculate the delta time
	float deltaSeconds = deltaTime.asSeconds();         // time to seconds
	g_preTime = currentTime;

	Color color;
	Vector2f moonCurrent = moon.getPosition();
	//float lightChange = 1 * deltaSeconds;

	if (moonCurrent.x > 200 && moonCurrent.x < 400)
	{
		color.r = 255 - lightChange;
		color.g = 255 - lightChange;
		color.b = 255 - lightChange;

		if (lightChange > 0) {
			lightChange = lightChange - 1;
		}
	}
	else if (moonCurrent.x >= 400 && moonCurrent.x < 600)
	{
		color.r = lightChange;
		color.g = lightChange;
		color.b = lightChange;

		if (lightChange < 255) {
			lightChange = lightChange + 1;
		}
	}
	else
	{
		color = Color(255, 255, 255);
	}
	*/

	window.clear(color);
	// Write your code above

	window.draw(sun);
	window.draw(moon);
	window.display();
}

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Solar Eclipse Simulation");

	Init(window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Update(window);
		Render(window);
	}

	return 0;
}
