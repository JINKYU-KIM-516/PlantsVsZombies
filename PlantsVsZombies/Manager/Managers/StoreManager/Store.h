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

//�Լ��� �̸�, �̹��� ���, ��� �Է��ϸ� �˾Ƽ� ������ �߰��ǰ� �ϰ����