#include "Player.h"
#include "../../../Main/MainGame.h"
#include "../PlantManager/PlantManager.h"

//protected
void Player::SpawnPlant(Point p_pos, Tile* p_tile)
{
	if (m_state == PlayerState::SELECTING)
	{
		switch (m_selectedCode)
		{
		case SUNFLOWER_CODE:
			PlantManager::GetI()->SpawnSunflower(m_currentTilePos, p_tile);
			m_sunlight -= SUNFLOWER_COST;
			break;
		case PEA_CODE:
			PlantManager::GetI()->SpawnPea(m_currentTilePos, p_tile);
			m_sunlight -= PEA_COST;
			break;
		case ICEPEA_CODE:
			PlantManager::GetI()->SpawnIcePea(m_currentTilePos, p_tile);
			m_sunlight -= ICEPEA_COST;
			break;
		case NUT_CODE:
			PlantManager::GetI()->SpawnNut(m_currentTilePos, p_tile);
			m_sunlight -= NUT_COST;
			break;
		default:
			break;
		}
	}
}

void Player::ClickTile()
{
	if (m_state != PlayerState::SELECTING)
		return;
	Tile* currentTile = GameBoard::GetI()->GetMouseOverTile();
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
	Tile* currentTile = GameBoard::GetI()->GetMouseOverTile();

	if (m_state == PlayerState::SELECTING && currentTile && !currentTile->IsPlantExist())
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
	m_sunlight = 10000;
	m_state = PlayerState::NORMAL;
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
	m_state = PlayerState::SELECTING;
	Point point = DEFAULT_POSITION;
	Size size = PLANT_SIZE;
	switch (m_selectedCode)
	{
	case SUNFLOWER_CODE:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, SUNFLOWER_IMAGEPATH);
		break;
	case PEA_CODE:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, PEA_IMAGEPATH);
		break;
	case ICEPEA_CODE:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, ICEPEA_IMAGEPATH);
		break;
	case NUT_CODE:
		m_currentSelectedPlant = new PictureBox(INVISIBLE_POS, PLANT_SIZE, NUT_IMAGEPATH);
		break;
	default:
		break;
	}
}

void Player::ResetState()
{
	m_state = PlayerState::NORMAL;
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

PlayerState Player::GetState()
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