#include "Store.h"
#include "MainGame.h"

//protected
void Store::AddImage(StorePlantImage* p_plantImage)
{
	m_plantImages.push_back(p_plantImage);
}

void Store::PaintSunflowerImage()
{
	m_index++;
	StorePlantImage* sunflowerImage = new StorePlantImage(IMAGEPATH_SUNFLOWER);
	sunflowerImage->Init(GetCurrentStoreImagePosition(m_index), CODE_SUNFLOWER, COST_SUNFLOWER);
	AddImage(sunflowerImage);
}

void Store::PaintPeaImage()
{
	m_index++;
	StorePlantImage* peaImage = new StorePlantImage(IMAGEPATH_PEA);
	peaImage->Init(GetCurrentStoreImagePosition(m_index), CODE_PEA, COST_PEA);
	AddImage(peaImage);
}

Point Store::GetCurrentStoreImagePosition(int p_index)
{
	int x = GAMEBOARD_START_X + (p_index * PLANT_WIDTH);
	int y = GAMEBOARD_START_Y - PLANT_HEIGHT;
	return Point(x, y);
}

void Store::ClickStorePlantImage()
{
	for (auto* image : m_plantImages)
	{
		if (image->Contains(m_mainGame->GetMousePosition()))
		{
			m_mainGame->GetPlayer()->SetSelectedCode(image->GetCode());
			m_mainGame->GetPlayer()->SetState(SELECTING);
			return;
		}
	}
}

//public
Store::Store()
{
	Init();
	PaintSunflowerImage();
	PaintPeaImage();
}

Store::~Store()
{
	for (auto* image : m_plantImages)
		delete image;
}

void Store::Init()
{
	m_mainGame = nullptr;
	m_index = -1;
}

void Store::Link(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
}

void Store::Update()
{

}

void Store::ClickHandle()
{
	ClickStorePlantImage();
}

const vector<StorePlantImage*>& Store::GetImages() const
{
	return m_plantImages;
}
