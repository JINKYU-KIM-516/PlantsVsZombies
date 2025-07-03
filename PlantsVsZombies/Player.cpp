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
			break;
		case CODE_PEA:
			m_mainGame->GetPlantManager()->SpawnPea(m_currentTilePos);
			break;
		default:
			break;
		}
	}
}

void Player::ResetState()
{
	m_state = NORMAL;
	m_selectedCode = -1;
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
}

void Player::Link(MainGame* p_mainGame)
{
	m_mainGame = p_mainGame;
}

void Player::Update()
{

}

void Player::ClickHandle()
{
	SetCurrentTilePos(m_mainGame->GetGameBoard()->GetMouseOverTilePos());
}

int Player::GetSunlight()
{
	return m_sunlight;
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
