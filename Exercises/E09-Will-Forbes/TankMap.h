#pragma once
#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

#define TERRAIN_TYPE_NUMBER 9
#define MAP_SIZE 20

struct Terrain {
public:
	string name;
	bool tank_passable;
	bool bullet_passable;
	Sprite sprite;
};

class TankMap
{
public:
	static TankMap* s_instance;
private:
	int m_map[MAP_SIZE][MAP_SIZE];			// map data
	int m_cell_size = 48;

	// the name of different types of terrain, used to load texture from file
	Terrain m_terrains[TERRAIN_TYPE_NUMBER]; // all types of terrains in our game

public:
	TankMap(string path);

	void Render(RenderWindow& window);

	bool CheckBulletPassable(Vector2f position);
	bool CheckTankPassable(Vector2f position, Vector2f size);

private:
	void InitTerrain();
	void InitSprite(string path_to_folder);
	void LoadMap(string path);

	bool CheckPositionTankPassable(Vector2f position);
};
