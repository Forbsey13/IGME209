#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

float rotation = 0.0f;

void Draw(sf::RenderWindow& window) {
    sf::Texture texture;
    if (!texture.loadFromFile("Images/tankBase.png")) {// load texture from file 

    }
    sf::Sprite sprite;
    sprite.setTexture(texture);// assign texture to sprite
    window.draw(sprite);// draw the sprite

    // define a circle
    sf::CircleShape shape(50.f); // radius = 50
    shape.setFillColor(sf::Color(10, 150, 10));
    // shape.setTexture(&texture); // texture is a sf::Texture
    shape.setPosition(600.f, 600.f); // set the position of the shape to x = 600, y = 600
    window.draw(shape);

    // define a triangle
    sf::CircleShape triangle(80.f, 3); // radius = 80, point count = 3
    triangle.setFillColor(sf::Color(150, 10, 10));
    triangle.setPosition(800.f, 400.f); // set the position of the shape to x = 800, y = 400
    triangle.move(50.f, 50.f); // move the shape relatively to its current position
    window.draw(triangle);

    // define a rectangle
    sf::RectangleShape rectangle(sf::Vector2f(80.0f, 80.0f));
    rectangle.setFillColor(sf::Color(10, 10, 150));
    rectangle.setPosition(300.f, 500.f);
    rectangle.setRotation(45.f); // set the rotation of the shape
    rectangle.rotate(30.f); // rotate the shape relatively to its current orientation
    window.draw(rectangle);

    // change the origin of the sprite and draw
    sprite.move(100.f, 100.f);
    sprite.scale(4.f, 4.f);
    sprite.setOrigin(16.f, 16.f); // The image is 32*32 pixels. Set the origin to the center.
    sprite.rotate(rotation);
    rotation += 0.1f;
    window.draw(sprite);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Drawing");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255)); // clear the window with color(255,255,255)
        Draw(window);
        window.display(); // display the window
    }

    return 0;
}