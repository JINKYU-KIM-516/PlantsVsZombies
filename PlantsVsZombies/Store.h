#pragma once
#include <vector>
#include "PictureBox.h"
class Store
{
protected:
	vector<PictureBox*> m_plantImages;

	void AddImage(PictureBox* p_pictureBox);
	void PaintImage(int p_index, const wstring& p_imagePath);
public:
	Store();
	void Init();
	void Update();

	const vector<PictureBox*>& GetImages() const;
};