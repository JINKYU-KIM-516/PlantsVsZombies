#include "StorePlantImage.h"

//protected
void StorePlantImage::CheckCost(int p_sunlight)
{
	if (m_cost <= p_sunlight)
	{
		SetImage(m_basicImagePath);
		m_canCost = true;
	}		
	else
	{
		SetImage(m_grayscaleImagePath);
		m_canCost = false;
	}
}

//public
StorePlantImage::StorePlantImage(Point p_pos, const wstring p_basicIP, int p_code, int p_cost)
	: PictureBox(p_pos, PLANT_SIZE, p_basicIP)
{
	Init(p_basicIP, p_code, p_cost);
}

void StorePlantImage::Init(const wstring p_basicIP, int p_code, int p_cost)
{
	m_basicImagePath = p_basicIP;
	wstring tempStr = m_basicImagePath;
	tempStr.replace(tempStr.length() - 4, 4, L"_Grayscale.bmp");
	m_grayscaleImagePath = tempStr;
	m_code = p_code;
	m_cost = p_cost;
	m_canCost = false;
}

void StorePlantImage::Update(int p_sunlight)
{
	CheckCost(p_sunlight);
}

int StorePlantImage::GetCode() const
{
	return m_code;
}

int StorePlantImage::GetCost() const
{
	return m_cost;
}

bool StorePlantImage::CanCost() const
{
	return m_canCost;
}
