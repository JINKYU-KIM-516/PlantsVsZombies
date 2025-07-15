#include "Player.h"
#include "../../../Main/MainGame.h"


//protected
void Player::SpawnPlant(Point p_pos)
{
	if (m_state == PLAYER_STATE_SELECTING)
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
		case CODE_ICEPEA:
			m_mainGame->GetPlantManager()->SpawnIcePea(m_currentTilePos);
			m_sunlight -= COST_ICEPEA;
			break;
		default:
			break;
		}
	}
}

void Player::SpawnPlant(Point p_pos, Tile* p_tile)
{
	if (m_state == PLAYER_STATE_SELECTING)
	{
		switch (m_selectedCode)
		{
		case CODE_SUNFLOWER:
			m_mainGame->GetPlantManager()->SpawnSunflower(m_currentTilePos, p_tile);
			m_sunlight -= COST_SUNFLOWER;
			break;
		case CODE_PEA:
			m_mainGame->GetPlantManager()->SpawnPea(m_currentTilePos, p_tile);
			m_sunlight -= COST_PEA;
			break;
		case CODE_ICEPEA:
			m_mainGame->GetPlantManager()->SpawnIcePea(m_currentTilePos, p_tile);
			m_sunlight -= COST_ICEPEA;
			break;
		default:
			break;
		}
	}
}

void Player::ClickTile()
{
	if (m_state != PLAYER_STATE_SELECTING)
		return;
	Tile* currentTile = m_mainGame->GetGameBoard()->GetMouseOverTile();
	if (!currentTile || currentTile->IsPlantExist())
		return;
	SetCurrentTilePos(currentTile->GetPos());
	SpawnPlant(m_currentTilePos, currentTile);
	ResetState();
}

void Player::PreviewPlant()
{
	if (!m_currentSelectedPlant)
		return;
	Tile* currentTile = m_mainGame->GetGameBoard()->GetMouseOverTile();

	if (m_state == PLAYER_STATE_SELECTING && currentTile && !currentTile->IsPlantExist())
	{
		SetCurrentTilePos(currentTile->GetPos());
		m_currentSelectedPlant->SetPos(m_currentTilePos);
	}
	else
	{
		m_currentSelectedPlant->SetPos(INVISIBLE_POS);
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
	m_state = PLAYER_STATE_NORMAL;
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

void Player::SelectPlant(int p_code)
{
	m_selectedCode = p_code;
	m_state = PLAYER_STATE_SELECTING;
	Point point = DEFAULT_POSITION;
	Size size = PLANT_SIZE;
	switch (m_selectedCode)
	{
	case CODE_SUNFLOWER:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, IMAGEPATH_SUNFLOWER);
		break;
	case CODE_PEA:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, IMAGEPATH_PEA);
		break;
	case CODE_ICEPEA:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, IMAGEPATH_ICEPEA);
		break;
	default:
		break;
	}
}

void Player::ResetState()
{
	m_state = PLAYER_STATE_NORMAL;
	m_selectedCode = -1;
	if (m_currentSelectedPlant)
	{
		delete m_currentSelectedPlant;
		m_currentSelectedPlant = nullptr;
	}
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

void Player::SetState(PlayerState p_state)
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