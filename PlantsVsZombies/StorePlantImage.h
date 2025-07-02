#pragma once
#include "PictureBox.h"
class StorePlantImage : public PictureBox
{
protected:
	int m_code;
	int m_cost;
public:
	StorePlantImage(const wstring& p_imagePath);
	void Init(Point p_pos, int p_code, int p_cost);

	int GetCode() const;
	int GetCost() const;
};