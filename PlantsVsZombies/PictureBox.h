#pragma once
#include <windows.h>
#pragma comment(lib, "msimg32.lib")
#include <string>
#include "Point.h"
#include "Size.h"

class PictureBox
{
protected:
	Point m_location;
	Size m_size;

	HBITMAP m_hBmp;
	wstring m_imagePath;
public:
	PictureBox(Point p_pos, Size p_size, const wstring& p_imagePath);
	~PictureBox();

	RECT GetRect() const;

	void Draw_Stretch(HDC hdc);
	void Draw(HDC hdc);
};