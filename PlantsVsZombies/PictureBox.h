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

	HBITMAP m_hBmp;
	wstring m_imagePath;
public:
	PictureBox(Point p_pos, Size p_size, const wstring& p_imagePath);
	~PictureBox();

	Point GetPosition() const;
	Size GetSize() const;

	RECT GetRect() const;
	bool IsCollided(const PictureBox *p_pictureBox);
	bool Contains(Point p_pos) const;

	void Draw_Stretch(HDC hdc);
	void Draw(HDC hdc);
};