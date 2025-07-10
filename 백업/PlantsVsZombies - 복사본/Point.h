#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int m_x;
	int m_y;
public:
	Point();
	Point(int p_x, int p_y);
	~Point();

	bool operator==(const Point& ref) const;
	bool operator!=(const Point& ref) const;
	Point operator+=(const Point& ref);
	Point operator+(const Point& ref);
	Point operator-=(const Point& ref);
	Point operator-(const Point& ref);

	int GetX() const;
	int GetY() const;

	void SetX(int p_x);
	void SetY(int p_y);

	void printPoint();
};