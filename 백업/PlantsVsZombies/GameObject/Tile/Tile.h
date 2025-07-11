#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"
#include "../Plant/Plant.h"

class Tile : public PictureBox
{
protected:
	Plant* m_plant;
	bool m_plantExist;
public:
	Tile(Point p_pos, wstring p_imagePath);

	bool IsPlantExist();
	void LinkPlant(Plant* p_plant);
	void PlantDeleted();
	void SetPlantExist(bool p_b);
};