#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
class StorePlantImage : public PictureBox
{
protected:
	int m_code;
	int m_cost;

	wstring m_grayscaleImagePath;

	bool m_canCost;

	void CheckCost(int p_sunlight);
public:
	StorePlantImage(Point p_pos, const wstring p_basicIP, int p_code, int p_cost);
	void Init(const wstring p_basicIP, int p_code, int p_cost);
	void Update(int p_sunlight);

	int GetCode() const;
	int GetCost() const;
	bool CanCost() const;
};