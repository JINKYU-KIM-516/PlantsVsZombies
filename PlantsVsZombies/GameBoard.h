#pragma once
#include <vector>
#include "Tile.h"

class MainGame;

class GameBoard
{
protected:
	MainGame* m_mainGame;

	vector<PictureBox*> m_tiles;
	wstring m_imagePath;

	void CreateTiles();
public:
	GameBoard();
	~GameBoard();
	void Init();
	void Link(MainGame* p_mainGame);
	void Update();

	Point GetMouseOverTilePos();
	const vector<PictureBox*>& GetTiles() const;
};