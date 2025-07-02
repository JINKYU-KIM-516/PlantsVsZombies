#include "PictureBox.h"

PictureBox::PictureBox(Point p_pos, Size p_size, const wstring& p_imagePath)
{
    m_size = p_size;
    m_positon = p_pos;
    m_imagePath = p_imagePath;

    m_hBmp = (HBITMAP)LoadImage(NULL, m_imagePath.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

PictureBox::~PictureBox()
{
    if (m_hBmp)
    {
        DeleteObject(m_hBmp);
        m_hBmp = nullptr;
    }
}

Point PictureBox::GetPosition() const
{
    return m_positon;
}

Size PictureBox::GetSize() const
{
    return m_size;
}

RECT PictureBox::GetRect() const
{
    RECT rc;
    rc.left = m_positon.GetX();
    rc.top = m_positon.GetY();
    rc.right = rc.left + m_size.GetWidth();
    rc.bottom = rc.top + m_size.GetHeight();
    return rc;
}

bool PictureBox::IsCollided(const PictureBox* p_pictureBox)
{
    RECT src = this->GetRect();
    RECT dest = p_pictureBox->GetRect();
    RECT result;
    return IntersectRect(&result, &src, &dest);
}

bool PictureBox::Contains(int p_x, int p_y) const
{
    RECT rc = GetRect();
    return (p_x >= rc.left && p_x <= rc.right &&
        p_y >= rc.top && p_y <= rc.bottom);
}


void PictureBox::Draw_Stretch(HDC hdc)
{
    if (!m_hBmp) {
        MessageBox(NULL, L"비트맵 로드 실패", L"오류", MB_OK);
        return;
    }

    BITMAP bmp;
    GetObject(m_hBmp, sizeof(BITMAP), &bmp);

    HDC hdcMem = CreateCompatibleDC(hdc);
    HGDIOBJ oldBmp = SelectObject(hdcMem, m_hBmp);

    StretchBlt(hdc,
        m_positon.GetX(), m_positon.GetY(),
        m_size.GetWidth(), m_size.GetHeight(),
        hdcMem, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

    SelectObject(hdcMem, oldBmp);
    DeleteDC(hdcMem);
}

void PictureBox::Draw(HDC hdc)
{
    if (!m_hBmp) {
        MessageBox(NULL, L"비트맵 로드 실패", L"오류", MB_OK);
        return;
    }

    BITMAP bmp;
    GetObject(m_hBmp, sizeof(BITMAP), &bmp);

    HDC hdcMem = CreateCompatibleDC(hdc);
    HGDIOBJ oldBmp = SelectObject(hdcMem, m_hBmp);

    TransparentBlt(hdc,
        m_positon.GetX(), m_positon.GetY(),
        m_size.GetWidth(), m_size.GetHeight(),
        hdcMem, 0, 0, bmp.bmWidth, bmp.bmHeight,
        TRANSPARENT_COLOR);

    SelectObject(hdcMem, oldBmp);
    DeleteDC(hdcMem);
}