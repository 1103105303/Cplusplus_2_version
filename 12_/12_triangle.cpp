#include<iostream>
#include"triangle.h"
using namespace std;
int main() {
	int x1 = 2, x2 = 3, x3 = 4;
	int y1 = 1, y2 = 3, y3 = 2;
	int Mx = 1, My = 1;
	int bsc_x = 3, bsc_y = 2;
	float angle = 90; //����
	float rate = 2;

	Move_Mirror Mover(x1, y1, x2, y2, x3, y3, Mx, My);
	Move_Mirror Mirror(x1, y1, x2, y2, x3, y3, Mx, My);

	Zoom Z1(x1, y1, x2, y2, x3, y3, rate);
	Rotate R(x1, y1, x2, y2, x3, y3, angle);
	
	cout << "���� ( " << Mx << ", " << My << " )" << endl;
	Mover.printtri();
	Mover.MovePoint();
	cout << "�Y�� "<<rate<<" ��" << endl;
	Z1.printtri();
	Z1.ZoomPoint();
	cout << "����A����I ( " << x1 << ", " << y1 << " )�A���׬� : " << angle << endl;
	R.printtri();
	R.RotatePoint();
	cout << "X�b���譱�A��g"<<  endl;
	Mirror.printtri();
	Mirror.Mirror();
	system("pause");
	return 0;
}