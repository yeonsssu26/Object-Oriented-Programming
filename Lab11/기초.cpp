#include <iostream>
using namespace std;
class Point {
private:
	int x;
	int y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) { numCreatedObjects++; }
	Point(int _x, int _y) { // int _x 와 int _y를 입력으로 받는 생성자
		this->x = _x; this->y = _y; 
		numCreatedObjects++;
	}
	~Point() { cout << "Destructed..." << endl;	}
	void setXY(int _x, int _y) { this->x = _x; this->y = _y; } //this-> 사용한 초기화
	int getX() const { return x; }
	int getY() const { return y; }
	Point operator+(Point& pt2) { // 내부
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
//static 맴버 변수 초기화 (numCreatedObjects)
int Point::numCreatedObjects = 0;

//객체 call by reference시: const로 함수 입력시 const method만 함수에서 사용가능
// const: 객체 내부의 member data가 상수(변하지 않는다)
void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}

/*Point operator+(Point& pt1, Point& pt2){ // 외부
 Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
 return result;
}*/

ostream& operator<<(ostream& cout, Point& pt) { // 외부
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

	// 포인터
	Point* pPt1 = &pt1;	// pPt1의 값을 통해 getX, getY를 호출하여 출력
	cout << "pt1 : "; cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : "; cout << pPt1->getX() << ", " << pPt1->getY() << endl; cout << endl;

	//동적으로 Point* pPt2할당하여 10,20넣은 뒤 ->사용하여 출력(pt1 출력 참고)
	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : "; cout << pPt2->getX() << ", " << pPt2->getY() << endl; cout << endl;

	//pPt1, pPt2의 메모리 해제
	pPt1->~Point(); // pPt1 : 정적할당
	delete pPt2; // pPt2 : 동적할당

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;

	// 연산자 오버로딩 //pt4 = pt2, pt3값 더하기
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
	delete[] ptary; // ptary 메모리 해제
	cout << endl;

	 // friend class
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);
	return 0;
}