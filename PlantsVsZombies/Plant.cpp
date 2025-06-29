#include "Plant.h"

Plant::Plant(Point p_pos, Size p_size, const wstring& p_imagePath)
    :PictureBox(p_pos, p_size, p_imagePath)

{
    m_hp = 100;
}

Plant::~Plant()
{

}

void Plant::Update()
{

}