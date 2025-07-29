#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../GameObject/StorePlantImage/StorePlantImage.h"

class MainGame;

class Store : public BaseManager, public SingletonT<Store>
{
protected:
	MainGame* m_mainGame;

	int m_index;
	vector<StorePlantImage*> m_plantImages;

	void AddImage(StorePlantImage* p_plantImage);
	void PaintImage_Sunflower();
	void PaintImage_Pea();
	void PaintImage_IcePea();
	void PaintImage_Nut();

	Point GetCurrentStoreImagePosition(int p_index);
	void ClickStorePlantImage();
public:
	Store();
	~Store();
	void Init() override;
	void Link(MainGame* p_mainGame);
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	const vector<StorePlantImage*>& GetImages() const;
};

//함수에 이름, 이미지 경로, 비용 입력하면 알아서 상점에 추가되게 하고싶음