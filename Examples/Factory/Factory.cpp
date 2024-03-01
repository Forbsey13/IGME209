#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

class Enemy {
protected:
protected:
    sf::Texture texture;
    sf::Sprite sprite;

    bool loadTexture(const std::string& filePath) {
        if (!texture.loadFromFile(filePath)) {
            std::cerr << "Error loading texture from: " << filePath << std::endl;
            return false;
        }
        sprite.setTexture(texture);
        sprite.setOrigin(0, texture.getSize().y);
        return true;
    }
public:
    virtual void draw(sf::RenderWindow& window, float x, float y) {
        sprite.setPosition(x, y);
        window.draw(sprite);
    }
    virtual void attack() = 0;
};

class Orc : public Enemy {
public:
    Orc() {
        loadTexture("Images/orc.png"); // Load chicken-specific texture
    }

    void attack() override {
        std::cout << "Orc attacks!" << std::endl;
    }
};

class Troll : public Enemy {
public:
    Troll() {
        loadTexture("Images/troll.png"); // Load chicken-specific texture
    }
    void attack() override {
        std::cout << "Troll attacks!" << std::endl;
    }
};

class EnemySpawner {
public:
    virtual Enemy* spawnEnemy() = 0; // Factory Method
};

class OrcSpawner : public EnemySpawner {
public:
    Enemy* spawnEnemy() override {
        return new Orc();
    }
};

class TrollSpawner : public EnemySpawner {
public:
    Enemy* spawnEnemy() override {
        return new Troll();
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Factory Method");

    EnemySpawner* spawner1 = new OrcSpawner();
    EnemySpawner* spawner2 = new TrollSpawner();

    std::vector<Enemy*> enemies;
    for (int i = 0; i < 2; i++)
        enemies.push_back(spawner1->spawnEnemy());
    enemies.push_back(spawner2->spawnEnemy());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(255, 255, 255));

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->draw(window, i * 150 + 100, 400);
        }

        window.display();
    }

    return 0;
}