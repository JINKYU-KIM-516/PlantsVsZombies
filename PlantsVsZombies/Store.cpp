#include "Store.h"

//protected
void Store::AddImage(StorePlantImage* p_plantImage)
{
	m_plantImages.push_back(p_plantImage);
}

void Store::PaintSunflowerImage()
{
	StorePlantImage* sunflowerImage = new StorePlantImage(IMAGEPATH_SUNFLOWER);
	sunflowerImage->Init(GetCurrentStoreImagePosition(m_index), CODE_SUNFLOWER, 50);
	AddImage(sunflowerImage);
}

void Store::PaintPeaImage()
{
	StorePlantImage* peaImage = new StorePlantImage(IMAGEPATH_PEA);
	peaImage->Init(GetCurrentStoreImagePosition(m_index), CODE_PEA, 50);
	AddImage(peaImage);
}

Point Store::GetCurrentStoreImagePosition(int p_index)
{
	int x = GAMEBOARD_START_X + (p_index * PLANT_WIDTH);
	int y = GAMEBOARD_START_Y - PLANT_HEIGHT;
	return Point(x, y);
}

//public
Store::Store()
{
	m_index = 0;
}

void Store::Init()
{
	PaintSunflowerImage();
	m_index++;
	PaintPeaImage();
}

void Store::Update()
{

}

const vector<StorePlantImage*>& Store::GetImages() const
{
	return m_plantImages;
}
