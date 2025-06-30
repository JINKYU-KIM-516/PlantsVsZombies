#pragma once
#include <vector>
#include "Tile.h"

class GameBoard
{
protected:
	vector<PictureBox*> m_tiles;
	wstring m_imagePath;
public:
	GameBoard();

	const vector<PictureBox*>& GetTiles() const;
};