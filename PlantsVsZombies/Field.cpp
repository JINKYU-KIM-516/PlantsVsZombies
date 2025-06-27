#include "Field.h"

Field::Field()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			Tile* tile = new Tile(Point(x * TILE_SIZE, y * TILE_SIZE), IMAGEPATH_FIELD_GRASS);
			m_tiles.push_back(tile);
		}
	}
}

vector<PictureBox*> Field::GetTiles()
{
	return m_tiles;
}
