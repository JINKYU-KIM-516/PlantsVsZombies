#include "Tile.h"

Tile::Tile(Point p_pos, wstring p_imagePath)
	:PictureBox(p_pos, Size(TILE_SIZE, TILE_SIZE), p_imagePath)
{

}
