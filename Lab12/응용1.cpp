#include <iostream>
using namespace std;
class Polygon {
protected:
	int mPoint; // 꼭지점의 갯수
	double mLength; // 한 변의 길이
public:
	Polygon() {}
	Polygon(int point, float length) { this->mPoint = point; this->mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter : empty" << endl; }
	virtual void calcArea() { cout << "Area : empty" << endl; }
};
class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon::Polygon(point,length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Perimeter : " << Polygon::mPoint * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area : " << Polygon::mLength * Polygon::mLength << endl; }
};
int main() {
	Polygon pol;
	Rectangle rec(4, 10);
	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	return 0;
}