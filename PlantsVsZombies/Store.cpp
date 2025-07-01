#include "Store.h"

//protected
void Store::AddImage(PictureBox* p_pictureBox)
{
	m_plantImages.push_back(p_pictureBox);
}

void Store::PaintImage(int p_index, const wstring& p_imagePath)
{
	int x = GAMEBOARD_START_X + (p_index * PLANT_WIDTH);
	int y = GAMEBOARD_START_Y - PLANT_HEIGHT;
	PictureBox* box = new PictureBox(Point(x,y), PLANT_SIZE, p_imagePath);
	AddImage(box);
}

//public
Store::Store()
{
}

void Store::Init()
{
	PaintImage(0, IMAGEPATH_SUNFLOWER);
	PaintImage(1, IMAGEPATH_PEA);
}

void Store::Update()
{

}

const vector<PictureBox*>& Store::GetImages() const
{
	return m_plantImages;
}
