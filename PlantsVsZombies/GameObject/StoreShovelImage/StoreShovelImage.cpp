#include "StoreShovelImage.h"

StoreShovelImage::StoreShovelImage()
	:PictureBox(DEFAULT_POSITION, PLANT_SIZE, SHOVEL_IMAGEPATH)
{
	Init(DEFAULT_POSITION);
}

void StoreShovelImage::Init(Point p_pos)
{
	m_position = p_pos;
}
