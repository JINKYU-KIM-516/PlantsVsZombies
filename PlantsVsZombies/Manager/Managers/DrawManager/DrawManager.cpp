#include "DrawManager.h"

DrawManager::~DrawManager()
{
    for (auto& pair : m_imageMap) {
        delete pair.second;
    }
    m_imageMap.clear();
}

PictureBox* DrawManager::Load(const wstring& path)
{
    auto it = m_imageMap.find(path);
    if (it != m_imageMap.end()) return it->second;

    PictureBox* picture = new PictureBox(Point(0, 0), Size(0,0), path);

    // 실패한 경우 m_hBmp는 nullptr일 것
    if (picture->GetRect().right == picture->GetRect().left ||
        picture->GetRect().bottom == picture->GetRect().top) {
        delete picture;
        return nullptr;
    }

    m_imageMap[path] = picture;
    return picture;
}
