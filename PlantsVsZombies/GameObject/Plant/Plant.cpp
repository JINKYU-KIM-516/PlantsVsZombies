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
    Init(100);
}

Plant::~Plant()
{

}

void Plant::Init(float p_hp)
{
    m_hp = p_hp;
    m_isAlive = true;
}

void Plant::Update()
{
    CheckAlive();
}

void Plant::TakeDamage(float p_damage)
{
    m_hp -= p_damage;
}

bool Plant::IsAlive()
{
    return m_isAlive;
}