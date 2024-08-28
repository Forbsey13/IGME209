#include "TankMap.h"
#include <fstream>

TankMap* TankMap::s_instance = nullptr;

TankMap::TankMap(string path)
{
    s_instance = this;
    InitTerrain();
    InitSprite("Images/");
    LoadMap(path);
}

void TankMap::InitTerrain()
{
    m_terrains[0].name = "dirt1";
    m_terrains[0].tank_passable = true;
    m_terrains[0].bullet_passable = true;

    m_terrains[1].name = "stone1";
    m_terrains[1].tank_passable = false;
    m_terrains[1].bullet_passable = false;

    m_terrains[2].name = "water";
    m_terrains[2].tank_passable = false;
    m_terrains[2].bullet_passable = true;

    m_terrains[3].name = "dirt2";
    m_terrains[3].tank_passable = true;
    m_terrains[3].bullet_passable = true;

    m_terrains[4].name = "dirt3";
    m_terrains[4].tank_passable = true;
    m_terrains[4].bullet_passable = true;

    m_terrains[5].name = "grass";
    m_terrains[5].tank_passable = true;
    m_terrains[5].bullet_passable = true;

    m_terrains[6].name = "stone2";
    m_terrains[6].tank_passable = false;
    m_terrains[6].bullet_passable = false;

    m_terrains[7].name = "wood";
    m_terrains[7].tank_passable = false;
    m_terrains[7].bullet_passable = false;

    m_terrains[8].name = "woodbroken";
    m_terrains[8].tank_passable = false;
    m_terrains[8].bullet_passable = false;
}

void TankMap::InitSprite(string path_to_folder)
{
    for (int i = 0; i < TERRAIN_TYPE_NUMBER; i++) {
        Texture* texture = new Texture();
        texture->loadFromFile(path_to_folder + m_terrains[i].name + ".png");
        m_terrains[i].sprite.setTexture(*texture);
        m_terrains[i].sprite.setScale((float)m_cell_size / texture->getSize().x, (float)m_cell_size / texture->getSize().y);
    }
}

void TankMap::LoadMap(string path)
{
    ifstream inf;
    inf.open(path); // open the file

    // read the map data from file
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            inf >> m_map[i][j];
        }
    }

    inf.close();    // close the file
}

bool TankMap::CheckPositionTankPassable(Vector2f position)
{
    int j = position.x / m_cell_size;
    int i = position.y / m_cell_size;

    if (i < 0 || j < 0 || i >= MAP_SIZE || j >= MAP_SIZE)
        return false;

    return m_terrains[m_map[i][j]].tank_passable;
}

bool TankMap::CheckBulletPassable(Vector2f position)
{
    int j = position.x / m_cell_size;
    int i = position.y / m_cell_size;

    if (i < 0 || j < 0 || i >= MAP_SIZE || j >= MAP_SIZE)
        return false;

    return m_terrains[m_map[i][j]].bullet_passable;
}

bool TankMap::CheckTankPassable(Vector2f position, Vector2f size)
{
    if (CheckPositionTankPassable(position + 0.5f * size) == false)
        return false;
    else if (CheckPositionTankPassable(position - 0.5f * size) == false)
        return false;
    else if (CheckPositionTankPassable(position + Vector2f(-0.5f * size.x, 0.5f * size.y)) == false)
        return false;
    else if (CheckPositionTankPassable(position + Vector2f(0.5f * size.x, -0.5f * size.y)) == false)
        return false;
    return true;
}

void TankMap::Render(RenderWindow& window)
{
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            int type = m_map[i][j];
            m_terrains[type].sprite.setPosition(j * m_cell_size, i * m_cell_size);

            window.draw(m_terrains[type].sprite);
        }
    }
}
