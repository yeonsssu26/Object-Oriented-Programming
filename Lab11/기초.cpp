#include <iostream>
using namespace std;
class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) { numCreatedObjects++; }
	Point(int _x, int _y) { // int _x �� int _y�� �Է����� �޴� ������
		this->x = _x; this->y = _y; 
		numCreatedObjects++;
	}
	~Point() { cout << "Destructed..." << endl;	}
	void setXY(int _x, int _y) { this->x = _x; this->y = _y; } //this-> ����� �ʱ�ȭ
	int getX() const { return x; }
	int getY() const { return y; }
	Point operator+(Point& pt2) { // ����
		Point res(this->x + pt2.x, this->y + pt2.y);
		return res;
	}
	Point& operator=(Point& pt) {
		Point res(this->x = pt.x, this->y = pt.y);
		return res;
	}
	static int getNumCreatedObject() { return numCreatedObjects; }
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, Point& pt);
	friend class SpyPoint;
};
//static �ɹ� ���� �ʱ�ȭ (numCreatedObjects)
int Point::numCreatedObjects = 0;

//��ü call by reference��: const�� �Լ� �Է½� const method�� �Լ����� ��밡��
// const: ��ü ������ member data�� ���(������ �ʴ´�)
void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}

/*Point operator+(Point& pt1, Point& pt2){ // �ܺ�
 Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
 return result;
}*/

ostream& operator<<(ostream& cout, Point& pt) { // �ܺ�
	cout << pt.getX() << ", " << pt.getY();
	return cout;
}

class SpyPoint {
public:
	void hack_all_info(const Point& p) {
		cout << "Hacked by SpyPoint" << endl; 
		cout << "x : " << p.x << endl;
		cout << "y : " << p.y << endl;
		cout << "numCreateObj : " << p.numCreatedObjects << endl << endl;
	}
};

int main() {
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);
	cout << endl;

	// ������
	Point* pPt1 = &pt1;	// pPt1�� ���� ���� getX, getY�� ȣ���Ͽ� ���
	cout << "pt1 : "; cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : "; cout << pPt1->getX() << ", " << pPt1->getY() << endl; cout << endl;

	//�������� Point* pPt2�Ҵ��Ͽ� 10,20���� �� ->����Ͽ� ���(pt1 ��� ����)
	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : "; cout << pPt2->getX() << ", " << pPt2->getY() << endl; cout << endl;

	//pPt1, pPt2�� �޸� ����
	pPt1->~Point(); // pPt1 : �����Ҵ�
	delete pPt2; // pPt2 : �����Ҵ�

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;

	// ������ �����ε� //pt4 = pt2, pt3�� ���ϱ�
	Point pt2(10,20), pt3(30,40), pt4 = pt2 + pt3;
	cout << "pt2 : ";
	cout << pt2 << endl;
	cout << "pt3 : ";
	cout << pt3 << endl;
	cout << "pt4 : ";
	cout << pt4 << endl;

	cout << "pt1 numcreatedobject : ";
	cout << pt1.getNumCreatedObject() << endl << endl;

	// object array
	Point* ptary = new Point[5];
	cout << "pt2 numcreatedobject : ";
	cout << pt2.getNumCreatedObject() << endl;
	cout << endl;
	delete[] ptary; // ptary �޸� ����
	cout << endl;

	 // friend class
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);
	return 0;
}