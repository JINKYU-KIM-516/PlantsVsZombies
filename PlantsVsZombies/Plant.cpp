#include "Plant.h"

//protected
void Plant::CheckAlive()
{
    if (m_hp <= 0)
        m_isAlive = false;
}

//public
Plant::Plant(Point p_pos, Size p_size, const wstring& p_imagePath)
    :PictureBox(p_pos, p_size, p_imagePath)
{
    m_code = -1;
    m_hp = 100;
    m_isAlive = true;
}

Plant::~Plant()
{

}

void Plant::Init(Point p_pos)
{
    m_positon = p_pos;
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