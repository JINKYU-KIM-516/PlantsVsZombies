#pragma once
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../GameObject/LawnMower/LawnMower.h"
#include <vector>

class LawnMowerManager : public BaseManager, public SingletonT<LawnMowerManager>
{
protected:
    vector<LawnMower*> m_lawnMowers;
    
    void CreateLawnMower();
    void CheckMowersInScreen();
public:
    LawnMowerManager();
    ~LawnMowerManager();
    void Update() override;
    void Init() override;
    void Draw(HDC p_hdc) override;

    void SpawnLawnMower(Point p_pos);

    void AddLawnMower(LawnMower* p_mower);
    void DeleteLawnMower(LawnMower* p_mower);
    const vector<LawnMower*>& GetLawnMowers() const;
};