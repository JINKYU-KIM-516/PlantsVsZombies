#pragma once
#include <vector>
#include "PictureBox.h"
#include "StorePlantImage.h"
class Store
{
protected:
	int m_index;
	vector<StorePlantImage*> m_plantImages;

	void AddImage(StorePlantImage* p_plantImage);
	void PaintSunflowerImage();
	void PaintPeaImage();

	Point GetCurrentStoreImagePosition(int p_index);
public:
	Store();
	void Init();
	void Update();

	const vector<StorePlantImage*>& GetImages() const;
};