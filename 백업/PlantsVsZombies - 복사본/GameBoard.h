#pragma once
#include <vector>
#include "Tile.h"

class MainGame;

class GameBoard
{
protected:
	MainGame* m_mainGame;

	vector<Tile*> m_tiles;
	wstring m_imagePath;

	void CreateTiles();
public:
	GameBoard();
	~GameBoard();
	void Init();
	void Link(MainGame* p_mainGame);
	void Update();

	Point GetMouseOverTilePos();
	Tile* GetMouseOverTile();
	const vector<Tile*>& GetTiles() const;
};