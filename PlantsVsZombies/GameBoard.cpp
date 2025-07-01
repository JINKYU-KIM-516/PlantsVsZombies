#include "GameBoard.h"

GameBoard::GameBoard()
{
	for (int y = 0; y < GAMEBOARD_HEIGHT; y++)
	{
		for (int x = 0; x < GAMEBOARD_WIDTH; x++)
		{
			Tile* tile = new Tile(Point(GAMEBOARD_START_X + x * TILE_WIDTH, GAMEBOARD_START_Y + y * TILE_HEIGHT), IMAGEPATH_GAMEBOARD_GRASS);
			m_tiles.push_back(tile);
		}
	}
}

GameBoard::~GameBoard()
{
	for (auto* tile : m_tiles)
		delete tile;
}

const vector<PictureBox*>& GameBoard::GetTiles() const
{
	return m_tiles;
}
