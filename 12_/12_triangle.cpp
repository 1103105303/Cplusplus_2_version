#include<iostream>
#include"triangle.h"
using namespace std;
int main() {
	int x1 = 2, x2 = 3, x3 = 4;
	int y1 = 1, y2 = 3, y3 = 2;
	int Mx = 1, My = 1;
	int bsc_x = 3, bsc_y = 2;
	float angle = 90; //角度
	float rate = 2;

	Move_Mirror Mover(x1, y1, x2, y2, x3, y3, Mx, My);
	Move_Mirror Mirror(x1, y1, x2, y2, x3, y3, Mx, My);

	Zoom Z1(x1, y1, x2, y2, x3, y3, rate);
	Rotate R(x1, y1, x2, y2, x3, y3, angle);
	
	cout << "移動 ( " << Mx << ", " << My << " )" << endl;
	Mover.printtri();
	Mover.MovePoint();
	cout << "縮放 "<<rate<<" 倍" << endl;
	Z1.printtri();
	Z1.ZoomPoint();
	cout << "旋轉，圓心點 ( " << x1 << ", " << y1 << " )，角度為 : " << angle << endl;
	R.printtri();
	R.RotatePoint();
	cout << "X軸為鏡面，鏡射"<<  endl;
	Mirror.printtri();
	Mirror.Mirror();
	system("pause");
	return 0;
}