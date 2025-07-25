#include "Nut.h"

//protected
void Nut::CheckHp()
{
    if (100 < m_hp && m_hp <= 200)
        SetImage(NUT_DAMAGED_IMAGEPATH);
    else if (m_hp <= 100)
        SetImage(NUT_EMERGENCY_IMAGEPATH);
}

//public
Nut::Nut()
    :Plant(DEFAULT_POSITION, PLANT_SIZE, NUT_IMAGEPATH)
{
    m_hp = 300;
}

void Nut::Init(Point p_pos)
{
    m_position = p_pos;
}

void Nut::Update()
{
    CheckHp();
    CheckAlive();
}