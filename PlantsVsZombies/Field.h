#pragma once
#include <vector>
#include "Tile.h"

class Field
{
protected:
	vector<PictureBox*> m_tiles;
	wstring m_imagePath;
public:
	Field();

	vector<PictureBox*> GetTiles();
};

