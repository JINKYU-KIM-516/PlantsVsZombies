# PlantsVsZombies
식물 대 좀비 프로젝트

#include <windows.h>
// C 런타임 헤더 파일입니다.

//------ 추가 헤더 파일은 여기에서 참조합니다.
#include <objidl.h>
#include <gdiplus.h>  // gdiplus  앞에 objidl.h 있어야지됨
// 파일형태로 lib 가지고 오는 방법
#pragma comment (lib,"Gdiplus.lib")
//------
include 순서 중요!!!!

#include <objidl.h> gdi plus 쓰려면 필요, windos




Nut* pnut =  Factory::Instance()->CreatObject(Nut); 팩토리 패턴
생성은 전부 팩토리에서 함 생성 매니저 같은거임


## 컴포넌트 아이디어
지금 개체들이 PictureBox를 상속 받고 있는데,
HitBox처럼 멤버로 가지고 있게하는게 컴포넌트임


v 현재는 이렇게 하고 있는데 v
class Object : public PictureBox //PictureBox에 HitBox가 들어있음
{
protected:
	void Move();
	void Attack();
public:
	Object();
	void Init(Point p_pos);
	void Update(Point p_pos);
};

v 이게 컴포넌트 v
class Object
{
protected:
 PictureBox* m_pictureBox;
 HitBox* m_hitBox;
 Move* m_move;
 Attack* m_attack;
public:
	Object();
	void Init(Point p_pos);
	void Update(Point p_pos);
};