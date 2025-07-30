#pragma once
#include <vector>
#include "../../BaseManager/BaseManager.h"
#include "../../../CoreFunction/Singleton/SingletonT.h"
#include "../../../GameObject/StorePlantImage/StorePlantImage.h"
#include "../../../GameObject/StoreShovelImage/StoreShovelImage.h"

class MainGame;

class Store : public BaseManager, public SingletonT<Store>
{
protected:
	int m_index;
	vector<StorePlantImage*> m_plantImages;
	StoreShovelImage* m_shovelImage;

	void AddImage(StorePlantImage* p_plantImage);
	void PaintImage_Sunflower();
	void PaintImage_Pea();
	void PaintImage_IcePea();
	void PaintImage_Nut();
	void PaintImage_Shovel();

	Point GetCurrentStoreImagePosition(int p_index);
	void ClickStorePlantImage();
	void ClickStoreShovelImage();
public:
	Store();
	~Store();
	void Init() override;
	void Update() override;
	void ClickHandle() override;
	void Draw(HDC p_hdc) override;

	const vector<StorePlantImage*>& GetImages() const;
};

//�Լ��� �̸�, �̹��� ���, ��� �Է��ϸ� �˾Ƽ� ������ �߰��ǰ� �ϰ����