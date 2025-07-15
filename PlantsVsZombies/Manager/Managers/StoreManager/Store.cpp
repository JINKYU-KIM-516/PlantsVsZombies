#include "Store.h"
#include "../../../Main/MainGame.h"

//protected
void Store::AddImage(StorePlantImage* p_plantImage)
{
	m_plantImages.push_back(p_plantImage);
}

void Store::PaintImage_Sunflower()
{
	m_index++;
	StorePlantImage* sunflowerImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		IMAGEPATH_SUNFLOWER, IMAGEPATH_SUNFLOWER_GRAYSCALE,
		SUNFLOWER_CODE, SUNFLOWER_COST);
	AddImage(sunflowerImage);
}

void Store::PaintImage_Pea()
{
	m_index++;
	StorePlantImage* peaImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		IMAGEPATH_PEA, IMAGEPATH_PEA_GRAYSCALE,
		PEA_CODE, PEA_COST);
	AddImage(peaImage);
}

void Store::PaintImage_IcePea()
{
	m_index++;
	StorePlantImage* icePeaImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		IMAGEPATH_ICEPEA, IMAGEPATH_ICEPEA_GRAYSCALE,
		ICEPEA_CODE, ICEPEA_COST);
	AddImage(icePeaImage);
}

void Store::PaintImage_Nut()
{
	m_index++;
	StorePlantImage* nutImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		IMAGEPATH_NUT, IMAGEPATH_NUT_GRAYSCALE,
		NUT_CODE, NUT_COST);
	AddImage(nutImage);
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
			if (!image->CanCost())
				return;
			if (m_mainGame->GetPlayer()->GetSelectedCode() == image->GetCode())
			{
				m_mainGame->GetPlayer()->ResetState();
				return;
			}
			m_mainGame->GetPlayer()->SelectPlant(image->GetCode());
			return;
		}
	}
}

//public
Store::Store()
{
	Init();
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

	PaintImage_Sunflower();
	PaintImage_Pea();
	PaintImage_IcePea();
	PaintImage_Nut();
}

void Store::Link(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
}

void Store::Update()
{
	for (auto* image : m_plantImages)
		image->Update(m_mainGame->GetPlayer()->GetSunlight());
}

void Store::ClickHandle()
{
	ClickStorePlantImage();
}

void Store::Draw(HDC p_hdc)
{
	for (auto* image : m_plantImages)
		image->Draw(p_hdc);
}

const vector<StorePlantImage*>& Store::GetImages() const
{
	return m_plantImages;
}
