#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape hairSquare(sf::Vector2f(100, 20));
sf::RectangleShape bangLeftSquare(sf::Vector2f(10, 10));
sf::RectangleShape bangRightSquare(sf::Vector2f(10, 10));
sf::RectangleShape skinSquare(sf::Vector2f(100, 60));
sf::RectangleShape leftEyeWhite(sf::Vector2f(10, 10));
sf::RectangleShape leftEye(sf::Vector2f(10, 10));
sf::RectangleShape rightEyeWhite(sf::Vector2f(10, 10));
sf::RectangleShape rightEye(sf::Vector2f(10, 10));
sf::RectangleShape shirtSquareTop(sf::Vector2f(180, 40));
sf::RectangleShape shirtSquareBottom(sf::Vector2f(100, 60));
sf::RectangleShape leftArmSquare(sf::Vector2f(40, 80));
sf::RectangleShape rightArmSquare(sf::Vector2f(40, 80));
sf::RectangleShape pantSquare(sf::Vector2f(100, 140));
sf::RectangleShape feetSquare(sf::Vector2f(100, 20));


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");


    hairSquare.setPosition(40, 40);
    skinSquare.setPosition(40, 60);
    bangLeftSquare.setPosition(40, 60);
    bangRightSquare.setPosition(130, 60);
    shirtSquareTop.setPosition(0, 120);
    shirtSquareBottom.setPosition(40, 160);
    rightArmSquare.setPosition(0, 160);
    leftArmSquare.setPosition(140, 160);
    pantSquare.setPosition(40,220);
    feetSquare.setPosition(40, 360);
    leftEyeWhite.setPosition(60, 80);
    leftEye.setPosition(70, 80);
    rightEyeWhite.setPosition(110, 80);
    rightEye.setPosition(100, 80);

    hairSquare.setFillColor(sf::Color(70, 40, 20));
    bangLeftSquare.setFillColor(sf::Color(70, 40, 20));
    bangRightSquare.setFillColor(sf::Color(70, 40, 20));
    skinSquare.setFillColor(sf::Color(235, 180, 140));
    shirtSquareTop.setFillColor(sf::Color(95, 215, 220));
    shirtSquareBottom.setFillColor(sf::Color(95, 215, 220));
    leftArmSquare.setFillColor(sf::Color(235, 180, 140));
    rightArmSquare.setFillColor(sf::Color(235, 180, 140));
    pantSquare.setFillColor(sf::Color(20, 65, 185));
    feetSquare.setFillColor(sf::Color(0, 0, 0));
    leftEyeWhite.setFillColor(sf::Color(255, 255, 255));
    leftEye.setFillColor(sf::Color(25, 60, 160));
    rightEyeWhite.setFillColor(sf::Color(255, 255, 255));
    rightEye.setFillColor(sf::Color(25, 60, 160));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear(sf::Color::White);

            window.draw(hairSquare);
            window.draw(skinSquare);
            window.draw(bangLeftSquare);
            window.draw(bangRightSquare);
            window.draw(shirtSquareTop);
            window.draw(shirtSquareBottom);
            window.draw(leftArmSquare);
            window.draw(rightArmSquare);
            window.draw(pantSquare);
            window.draw(feetSquare);
            window.draw(leftEyeWhite);
            window.draw(leftEye);
            window.draw(rightEyeWhite);
            window.draw(rightEye);

            window.display();
        }
    }

    return 0;
}