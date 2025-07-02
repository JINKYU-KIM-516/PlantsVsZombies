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
	peaImage->Init(GetCurrentStoreImagePosition(m_index), CODE_SUNFLOWER, COST_PEA);
	AddImage(peaImage);
}

Point Store::GetCurrentStoreImagePosition(int p_index)
{
	int x = GAMEBOARD_START_X + (p_index * PLANT_WIDTH);
	int y = GAMEBOARD_START_Y - PLANT_HEIGHT;
	return Point(x, y);
}

void Store::CheckImageClicked()
{
	if (m_mainGame->IsClickOccured())
	{
		for (auto* image : m_plantImages)
		{
			if (image->Contains(m_mainGame->GetMousePosition()))
			{
				m_mainGame->GetPlayer()->SetSelectedCode(image->GetCode());
				m_mainGame->GetPlayer()->SetState(SELECTING);
			}
		}
	}
}

//public
Store::Store()
{
	m_mainGame = nullptr;
	m_index = -1;
}

Store::~Store()
{
	for (auto* image : m_plantImages)
		delete image;
}

void Store::Init(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
	PaintSunflowerImage();
	PaintPeaImage();
}

void Store::Update()
{
	CheckImageClicked();
}

const vector<StorePlantImage*>& Store::GetImages() const
{
	return m_plantImages;
}
