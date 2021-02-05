#include <iostream>
#include <cmath>
using namespace std;
class Point {
	int x;
	int y;
public:
	Point():x(0), y(0){}
	Point(int _x, int _y) { this->x = _x; this->y = _y; }
	~Point(){} // �Ҹ��� �ʿ��Ѱ�?
	int getX() { return x; }
	int getY() { return y; }
	void setPoint(int _x, int _y) { this->x = _x; this->y = _y; }
	Point operator-(Point p) {
		Point res(this->x - p.x, this->y - p.y);
		return res;
	}
	Point operator*(Point p) {
		Point res(this->x*p.x, this->y*p.y);
		return res;
	}
};
int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cout << "ù��° ��ǥ(x1, y1)�� �Է��ϼ��� : "; cin >> x1 >> y1;
	cout << "�ι�° ��ǥ(x2, y2)�� �Է��ϼ��� : "; cin >> x2 >> y2;
	
	Point* pP1, *pP2, *pP3;
	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point(); //x,y�� 0���� �ʱ�ȭ

	//�Ʒ��� ������ε� x, y�� ������ �����ؾ� �� 
	//pP1 = new Point(); pP1->setPoint(x1, y1);
	//pP2 = new Point(); pP2->setPoint(x2, y2);
	
	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2); //pP3�� Ȱ���Ͽ� �Ÿ����� ����
	double distance = sqrt(pP3->getX()+pP3->getY());
	cout << "�� ��ǥ ������ ���̴� " << distance << "�Դϴ�." << endl;
	return 0;
}