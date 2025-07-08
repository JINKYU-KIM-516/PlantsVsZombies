#include "Player.h"
#include "MainGame.h"

//protected
void Player::SpawnPlant(Point p_pos)
{
	if (m_state == SELECTING)
	{
		switch (m_selectedCode)
		{
		case CODE_SUNFLOWER:
			m_mainGame->GetPlantManager()->SpawnSunflower(m_currentTilePos);
			m_sunlight -= COST_SUNFLOWER;
			break;
		case CODE_PEA:
			m_mainGame->GetPlantManager()->SpawnPea(m_currentTilePos);
			m_sunlight -= COST_PEA;
			break;
		default:
			break;
		}
	}
}

void Player::ClickTile()
{
	if (m_state != SELECTING)
		return;
	Tile* currentTile = m_mainGame->GetGameBoard()->GetMouseOverTile();
	if (!currentTile || currentTile->IsPlantExist())
		return;
	SetCurrentTilePos(currentTile->GetPos());
	currentTile->SetPlantExist(true);
	SpawnPlant(m_currentTilePos);
	ResetState();
}

void Player::PreviewPlant()
{
	Tile* currentTile = m_mainGame->GetGameBoard()->GetMouseOverTile();
	CurrentSelectedPlant();
	if (m_state == SELECTING && currentTile && !currentTile->IsPlantExist() && m_currentSelectedPlant)
	{
		SetCurrentTilePos(currentTile->GetPos());
		m_currentSelectedPlant->SetPos(m_currentTilePos);
	}
	else
	{
		if (m_currentSelectedPlant)
			delete m_currentSelectedPlant;
	}
}

void Player::CurrentSelectedPlant()
{
	Point point = DEFAULT_POSITION;
	Size size = PLANT_SIZE;
	switch (m_selectedCode)
	{
	case CODE_SUNFLOWER:
		m_currentSelectedPlant = new PictureBox(DEFAULT_POSITION, PLANT_SIZE, IMAGEPATH_SUNFLOWER);
		break;
	case CODE_PEA:
		m_currentSelectedPlant = new PictureBox(DEFAULT_POSITION, PLANT_SIZE, IMAGEPATH_PEA);
		break;
	default:
		break;
	}
}

//public
Player::Player()
{
	Init();
}

void Player::Init()
{
	m_mainGame = nullptr;
	m_sunlight = 0;
	m_state = NORMAL;
	m_selectedCode = -1;
	m_currentSelectedPlant = nullptr;
}

void Player::Link(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
}

void Player::Update()
{
	PreviewPlant();
}

void Player::ClickHandle()
{
	ClickTile();
}

void Player::Draw(HDC p_hdc)
{
	if(m_currentSelectedPlant)
		m_currentSelectedPlant->Draw(p_hdc);
}

int Player::GetSunlight()
{
	return m_sunlight;
}

int Player::GetState()
{
	return m_state;
}

int Player::GetSelectedCode()
{
	return m_selectedCode;
}

void Player::SetSunlight(int p_sunlight)
{
	m_sunlight = p_sunlight;
}

void Player::SetState(int p_state)
{
	m_state = p_state;
}

void Player::SetSelectedCode(int p_code)
{
	m_selectedCode = p_code;
}

void Player::SetCurrentTilePos(Point p_pos)
{
	m_currentTilePos = p_pos;
}

void Player::ResetState()
{
	m_state = NORMAL;
	m_selectedCode = -1;
	if (m_currentSelectedPlant)
	{
		delete m_currentSelectedPlant;
		m_currentSelectedPlant = nullptr;
	}
}