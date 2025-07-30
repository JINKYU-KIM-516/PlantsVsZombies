#include "GameBoard.h"
#include "../../../Main/MainGame.h"

void GameBoard::CreateTiles()
{
	for (int y = 0; y < GAMEBOARD_HEIGHT; y++)
	{
		for (int x = 0; x < GAMEBOARD_WIDTH; x++)
		{
			Tile* tile = new Tile(Point(GAMEBOARD_START_X + x * TILE_WIDTH, GAMEBOARD_START_Y + y * TILE_HEIGHT), TILE_GROUND_BRIGHTER_IMAGEPATH);
			m_tiles.push_back(tile);
		}
	}
}

GameBoard::GameBoard()
{
	Init();
	CreateTiles();
}

GameBoard::~GameBoard()
{
	for (auto* tile : m_tiles)
		delete tile;
}

void GameBoard::Init()
{

}


void GameBoard::Draw(HDC p_hdc)
{
	for (auto* tile : m_tiles)
	{
		tile->Draw(p_hdc);
	}
}

Point GameBoard::GetMouseOverTilePos()
{
	for (auto* tile : m_tiles)
	{
		if (tile->Contains(MainGame::GetI()->GetMousePosition()))
		{
			return tile->GetPos();
		}
	}
	return Point(-1, -1);
}

Tile* GameBoard::GetMouseOverTile()
{
	for (auto* tile : m_tiles)
	{
		if (tile->Contains(MainGame::GetI()->GetMousePosition()))
		{
			return tile;
		}
	}
	return nullptr;
}

const vector<Tile*>& GameBoard::GetTiles() const
{
	return m_tiles;
}
