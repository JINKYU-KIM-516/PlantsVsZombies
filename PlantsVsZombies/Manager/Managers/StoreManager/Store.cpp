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
		SUNFLOWER_IMAGEPATH,
		SUNFLOWER_CODE, SUNFLOWER_COST);
	AddImage(sunflowerImage);
}

void Store::PaintImage_Pea()
{
	m_index++;
	StorePlantImage* peaImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		PEA_IMAGEPATH,
		PEA_CODE, PEA_COST);
	AddImage(peaImage);
}

void Store::PaintImage_IcePea()
{
	m_index++;
	StorePlantImage* icePeaImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		ICEPEA_IMAGEPATH,
		ICEPEA_CODE, ICEPEA_COST);
	AddImage(icePeaImage);
}

void Store::PaintImage_Nut()
{
	m_index++;
	StorePlantImage* nutImage = new StorePlantImage(
		GetCurrentStoreImagePosition(m_index),
		NUT_IMAGEPATH,
		NUT_CODE, NUT_COST);
	AddImage(nutImage);
}

void Store::PaintImage_Shovel()
{
	m_index++;
	m_shovelImage = new StoreShovelImage();
	m_shovelImage->Init(GetCurrentStoreImagePosition(m_index));
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
		if (image->Contains(MainGame::GetI()->GetMousePosition()))
		{
			if (!image->CanCost())
				return;
			if (Player::GetI()->GetSelectedCode() == image->GetCode())
			{
				Player::GetI()->ResetState();
				return;
			}
			Player::GetI()->SelectPlant(image->GetCode());
			return;
		}
	}
}

void Store::ClickStoreShovelImage()
{
	if (m_shovelImage->Contains(MainGame::GetI()->GetMousePosition()))
	{
		if (Player::GetI()->GetState() == PlayerState::DELETING)
		{
			Player::GetI()->ResetState();
			return;
		}
		Player::GetI()->SelectShovel();
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
	m_index = -1;

	PaintImage_Sunflower();
	PaintImage_Pea();
	PaintImage_IcePea();
	PaintImage_Nut();

	PaintImage_Shovel();
}

void Store::Update()
{
	for (auto* image : m_plantImages)
		image->Update(Player::GetI()->GetSunlight());
}

void Store::ClickHandle()
{
	ClickStorePlantImage();
	ClickStoreShovelImage();
}

void Store::Draw(HDC p_hdc)
{
	for (auto* image : m_plantImages)
		image->Draw(p_hdc);
	if(m_shovelImage)
		m_shovelImage->Draw(p_hdc);
}

const vector<StorePlantImage*>& Store::GetImages() const
{
	return m_plantImages;
}
