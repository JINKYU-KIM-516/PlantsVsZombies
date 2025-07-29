#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../Plant/Plant.h"

class Tile : public PictureBox
{
protected:
	bool m_plantExist;
public:
	Tile(Point p_pos, wstring p_imagePath);

	bool IsPlantExist();
	void PlantDeleted();
	void SetPlantExist(bool p_b);
};