#include "Tile.h"

Tile::Tile(Point p_pos, wstring p_imagePath)
	:PictureBox(p_pos, TILE_SIZE, p_imagePath)
{
	m_plant = nullptr;
}

bool Tile::IsPlantExist()
{
	return m_plantExist;
}

void Tile::SetPlantExist(bool p_b)
{
	m_plantExist = p_b;
}
