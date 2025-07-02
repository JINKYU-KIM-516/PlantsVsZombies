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
public:
	GameBoard();
	~GameBoard();
	void Init(MainGame* p_mainGame);
	void Update();

	Point GetMouseOverTilePos();
	const vector<PictureBox*>& GetTiles() const;
};