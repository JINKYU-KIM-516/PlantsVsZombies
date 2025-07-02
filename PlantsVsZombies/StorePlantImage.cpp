#include "StorePlantImage.h"

StorePlantImage::StorePlantImage(const wstring& p_imagePath)
	:PictureBox(DEFAULT_POSITION, PLANT_SIZE, p_imagePath)
{
	m_code = -1;
	m_cost = 0;
}

void StorePlantImage::Init(Point p_pos, int p_code, int p_cost)
{
	m_positon = p_pos;
	m_code = p_code;
	m_cost = p_cost;
}

int StorePlantImage::GetCode() const
{
	return m_code;
}

int StorePlantImage::GetCost() const
{
	return m_cost;
}
