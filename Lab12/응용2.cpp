#include <iostream>
#include <cmath> // 루트계산
using namespace std;
class Polygon {
protected:
	int mPoint; // 꼭지점의 갯수
	double mLength; // 한 변의 길이
public:
	Polygon() {}
	Polygon(int point, float length) { this->mPoint = point; this->mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter : empty" << endl; } // 둘레
	virtual void calcArea() { cout << "Area : empty" << endl; } // 넓이
};
class Rectangle : public Polygon {
public:
	Rectangle() {}
	Rectangle(int point, float length) : Polygon::Polygon(point, length) {}
	~Rectangle() {}
	void calcPerimeter() override { cout << "Perimeter : " << Polygon::mPoint * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area : " << Polygon::mLength * Polygon::mLength << endl; }
};
class Triangle : public Polygon {
public:
	Triangle() {}
	Triangle(int point, float length) : Polygon::Polygon(point,length){}
	~Triangle(){}
	void calcPerimeter() override { cout << "Perimeter : " << Polygon::mPoint * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area : " << sqrt(3) / 4 * Polygon::mLength*Polygon::mLength << endl; }
};
class Circle : public Polygon{
public:
	Circle(){}
	Circle(int point, float length):Polygon::Polygon(point,length){}
	~Circle(){}
	void calcPerimeter() override { cout << "Perimeter : " << 2*3.14*Polygon::mLength << endl; }
	void calcArea() override { cout << "Area : " << 3.14*Polygon::mLength*Polygon::mLength << endl; }
};
int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);
	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();
	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();
	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();
	return 0;
}