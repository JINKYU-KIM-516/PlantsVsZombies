#include "Nut.h"

//protected
void Nut::CheckHp()
{
    if (100 < m_hp && m_hp <= 200)
        SetImage(IMAGEPATH_NUT_DAMAGED);
    else if (m_hp <= 100)
        SetImage(IMAGEPATH_NUT_EMERGENCY);
}

//public
Nut::Nut()
    :Plant(DEFAULT_POSITION, PLANT_SIZE, IMAGEPATH_NUT)
{
    m_hp = 300;
}

void Nut::Init(Point p_pos)
{
    m_positon = p_pos;
}

void Nut::Update()
{
    CheckHp();
    CheckAlive();
}