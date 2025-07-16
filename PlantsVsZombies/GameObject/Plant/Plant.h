#pragma once
#include "../../CoreFunction/PictureBox/PictureBox.h"

class Tile;

class Plant : public PictureBox
{
protected:
	Tile* m_linkedTile;

	int m_hp;
	bool m_isAlive;

	void CheckAlive();
public:
	Plant(Point p_pos, Size p_size, const wstring p_imagePath);
	virtual ~Plant();
	virtual void Init(int p_hp);
	void LinkTile(Tile* p_tile);
	virtual void Update();

	void TakeDamage(int p_damage);
	bool IsAlive();
};