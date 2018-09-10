#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
using namespace std;
class Triangle
{
public:
	Triangle(int, int, int, int, int, int);
	void SetPoint1(int, int);
	void SetPoint2(int, int);
	void SetPoint3(int, int);
	void printtri();
	double GetPI();
protected:
	const double pi = 3.141592654;
	float x1, y1;
	float x2, y2;
	float x3, y3;
};

class Move_Mirror : public Triangle
{
public:
	Move_Mirror(float, float, float, float, float, float, float, float);
	void Setbaiscpoint(float, float);
	void Mirror();
	void MovePoint();
	float Getx();
	float Gety();
private:
	float x;
	float y;
};

class Rotate : public Triangle
{
public:
	Rotate(float, float, float, float, float, float, float);
	void Setangle(float);
	void RotatePoint();
	void Save(float, float, float, float);
private:
	float angle;
	float x;
	float y;
};

class Zoom : public Triangle
{
public:
	Zoom(float, float, float, float, float, float, float);
	void mid_point();
	void ZoomPoint();
private:
	float rate;
	float average_x;
	float average_y;
};

#endif // !TRIANGLE_H

