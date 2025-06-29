#include "GameBoard.h"

GameBoard::GameBoard()
{
	for (int y = 0; y < GAMEBOAORD_HEIGHT; y++)
	{
		for (int x = 0; x < GAMEBOAORD_WIDTH; x++)
		{
			Tile* tile = new Tile(Point(x * TILE_WIDTH, y * TILE_HEIGHT), IMAGEPATH_GAMEBOARD_GRASS);
			m_tiles.push_back(tile);
		}
	}
}

const vector<PictureBox*>& GameBoard::GetTiles() const
{
	return m_tiles;
}
