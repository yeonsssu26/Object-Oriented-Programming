#include<iostream>
using namespace std;
template<class T>
class Point {
private:
	T x;
	T y;
public:
	Point(T _x, T _y);
	void setXY(T _x, T _y);
	T getX();
	T getY();
	void print();
};

template<class T>
Point<T>::Point(T _x, T _y) : x(_x), y(_y) {}

template<class T>
void Point<T>::setXY(T _x, T _y) {
	x = _x;
	y = _y;
}

template<class T>
T Point<T>::getX() { return this->x; }

template<class T>
T Point<T>::getY() { return this->y; }

template<class T>
void Point<T>::print() { cout << x << ", " << y << endl; }

int main() {
	Point<int> pt(1, 2);
	Point<double> pt2(1.1, 2.2);
	pt.print();
	pt2.print();
}