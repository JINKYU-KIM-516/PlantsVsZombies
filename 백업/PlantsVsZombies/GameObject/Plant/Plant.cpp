#include "Plant.h"
#include "../Tile/Tile.h"

//protected
void Plant::CheckAlive()
{
    if (m_hp <= 0)
    {
        m_isAlive = false;
        m_linkedTile->PlantDeleted();
    }
}

//public
Plant::Plant(Point p_pos, Size p_size, const wstring p_imagePath)
    :PictureBox(p_pos, p_size, p_imagePath)
{
    m_linkedTile = nullptr;
    Init(100);
}

Plant::~Plant()
{

}

void Plant::Init(int p_hp)
{
    m_hp = p_hp;
    m_isAlive = true;
}

void Plant::LinkTile(Tile* p_tile)
{
    m_linkedTile = p_tile;
    m_linkedTile->SetPlantExist(true);
}

void Plant::Update()
{
    CheckAlive();
}

void Plant::TakeDamage(int p_damage)
{
    m_hp -= p_damage;
}

bool Plant::IsAlive()
{
    return m_isAlive;
}