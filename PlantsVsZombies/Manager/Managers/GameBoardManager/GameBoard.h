#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../GameObject/Tile/Tile.h"

class MainGame;

class GameBoard : public BaseManager, public SingletonT<GameBoard>
{
protected:
	vector<Tile*> m_tiles;
	wstring m_imagePath;

	void CreateTiles();
public:
	GameBoard();
	~GameBoard();
	void Init() override;
	void Draw(HDC p_hdc) override;

	Point GetMouseOverTilePos();
	Tile* GetMouseOverTile();
	const vector<Tile*>& GetTiles() const;
};