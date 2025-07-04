#include "GameBoard.h"
#include "MainGame.h"

void GameBoard::CreateTiles()
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
	m_mainGame = nullptr;
}

void GameBoard::Link(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
}

void GameBoard::Update()
{

}

Point GameBoard::GetMouseOverTilePos()
{
	for (auto* tile : m_tiles)
	{
		if (tile->Contains(m_mainGame->GetMousePosition()))
		{
			return tile->GetPosition();
		}
	}
	return Point(-1, -1);
}

Tile* GameBoard::GetMouseOverTile()
{
	for (auto* tile : m_tiles)
	{
		if (tile->Contains(m_mainGame->GetMousePosition()))
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
