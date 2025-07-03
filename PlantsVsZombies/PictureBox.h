#pragma once
#include <windows.h>
#pragma comment(lib, "msimg32.lib")
#include <string>
#include "Point.h"
#include "Size.h"
#include "Constants.h"

class PictureBox
{
protected:
	Point m_positon;
	Size m_size;
	int m_z;

	HBITMAP m_hBmp;
	wstring m_imagePath;
public:
	PictureBox(Point p_pos, Size p_size, const wstring& p_imagePath);
	~PictureBox();

	void Draw(HDC hdc);

	Point GetPosition() const;
	Size GetSize() const;
	int GetZ() const;

	RECT GetRect() const;
	bool IsCollided(const PictureBox *p_pictureBox);
	bool Contains(Point p_pos) const;

	void SetZ(int p_z);
};