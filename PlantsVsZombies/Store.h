#pragma once
#include <vector>
#include "PictureBox.h"
#include "StorePlantImage.h"

class MainGame;

class Store
{
protected:
	MainGame* m_mainGame;

	int m_index;
	vector<StorePlantImage*> m_plantImages;

	void AddImage(StorePlantImage* p_plantImage);
	void PaintSunflowerImage();
	void PaintPeaImage();

	Point GetCurrentStoreImagePosition(int p_index);
	void CheckImageClicked();
public:
	Store();
	~Store();
	void Init(MainGame* p_mainGame);
	void Update();

	const vector<StorePlantImage*>& GetImages() const;
};