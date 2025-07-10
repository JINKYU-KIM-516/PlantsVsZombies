#pragma once
#include <vector>
#include "BaseManager.h"
#include "StorePlantImage.h"

class MainGame;

class Store : public BaseManager
{
protected:
	MainGame* m_mainGame;

	int m_index;
	vector<StorePlantImage*> m_plantImages;

	void AddImage(StorePlantImage* p_plantImage);
	void PaintSunflowerImage();
	void PaintPeaImage();

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