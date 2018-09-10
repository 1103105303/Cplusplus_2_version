#include<iostream>
#include <iomanip>
#include<math.h>
#include"triangle.h"
using namespace std;

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	SetPoint1(x1, y1);
	SetPoint2(x2, y2);
	SetPoint3(x3, y3);
}
void Triangle::SetPoint1(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
}
void Triangle::SetPoint2(int x, int y)
{
	this->x2 = x;
	this->y2 = y;
}
void Triangle::SetPoint3(int x, int y)
{
	this->x3 = x;
	this->y3 = y;
}
void Triangle::printtri()
{
	cout<<fixed << setprecision(1) << " Point1 : ( " << x1 << ", " << y1 << " )" << " Point2 : ( " << x2 << ", " << y2 << " )"
		<< " Point3 : ( " << x3 << ", " << y3 << " )" << endl;
}
double Triangle::GetPI()
{
	return this->pi;
}
//--------------------------------------------------
Move_Mirror::Move_Mirror(float x1, float y1, float x2, float y2, float x3, float y3, float bx, float by) :
	Triangle(x1, y1, x2, y2, x3, y3), x(bx), y(by)
{
	Setbaiscpoint(bx, by);
}
void Move_Mirror::Setbaiscpoint(float bx, float by)
{
	x = bx;
	y = by;
}
void Move_Mirror::MovePoint()
{
	this->x1 += Getx();
	this->x2 += Getx();
	this->x3 += Getx();
	this->y1 += Gety();
	this->y2 += Gety();
	this->y3 += Gety();
	this->printtri();
}
float Move_Mirror::Getx()
{
	return this->x;
}
float Move_Mirror::Gety()
{
	return this->y;
}
void Move_Mirror::Mirror()
{
	this->x1 *= -1;
	this->x2 *= -1;
	this->x3 *= -1;
	this->y1 *= -1;
	this->y2 *= -1;
	this->y3 *= -1;
	this->printtri();
}

//---------------------------------------------
Zoom::Zoom(float x1, float y1, float x2, float y2, float x3, float y3, float Frate) :
	Triangle(x1,y1,x2,y2,x3,y3),rate(Frate)
{
	mid_point();
}
void Zoom::mid_point() 
{
	this->average_x = (x1 + x2 + x3) / 3;
	this->average_y = (y1 + y2 + y3) / 3;
}
void Zoom::ZoomPoint() 
{
	this->x1 = average_x + (this->x1 - average_x) * rate;
	this->x2 = average_x + (this->x2 - average_x) * rate;
	this->x3 = average_x + (this->x3 - average_x) * rate;
	this->y1 = average_y + (this->y1 - average_y) * rate;
	this->y2 = average_y + (this->y2 - average_y) * rate;
	this->y3 = average_y + (this->y3 - average_y) * rate;
	this->printtri();
}
//--------------------------------------------
Rotate::Rotate(float x1, float y1, float x2, float y2, float x3, float y3, float ale):
	Triangle(x1, y1, x2, y2, x3, y3),angle(ale)
{
	Setangle(ale); // 弧度轉徑度
}
void Rotate::Save(float tempx2,float tempy2,float tempx3,float tempy3) 
{
	tempx2 < 0 ? tempx2>-0.1 ? this->x2 = 0 : this->x2 = tempx2 : this->x2 = tempx2;
	tempy2 < 0 ? this->y2 = 0 : this->y2 = tempy2;
	tempx3 < 0 ? this->x3 = 0 : this->x3 = tempx3;
	tempy3 < 0 ? this->y3 = 0 : this->y3 = tempy3;
}
void Rotate::Setangle(float ale) 
{
	this->angle = ale * this->GetPI() / 180;
}
void Rotate::RotatePoint()
{
	float Mcos, Msin;
	float tempx2, tempy2, tempx3, tempy3;
	//回歸
	this->x2 -= this->x1;
	this->x3 -= this->x1;
	this->y2 -= this->y1;
	this->y3 -= this->y1;
	Mcos = cos(angle);
	Msin = sin(angle);
	//x' = cos(θ) * x - sin(θ) * y 
	//y' = sin(θ) * x + cos(θ) * y
	tempx2 = Mcos * this->x2 - Msin * this->y2 + this->x1;
	tempy2 = Msin * this->x2 + Mcos * this->y2 + this->y1;
	tempx3 = Mcos * this->x3 - Msin * this->y3 + this->x1;
	tempy3 = Msin * this->x3 + Mcos * this->y3 + this->y1;
	Save(tempx2, tempy2, tempx3, tempy3);
	this->printtri();
}
