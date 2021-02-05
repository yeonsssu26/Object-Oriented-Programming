#include <iostream>
#include <vector>
using namespace std;
class Train {
protected:
	int mPeople; // ��� ��
public:
	Train() {}
	Train(int people) { this->mPeople = people; }
	~Train() {}
	virtual void station(int takeOff, int takeOn) { mPeople = mPeople - takeOff + takeOn; }

};
class Ktx : public Train {
public:
	Ktx() : Train::Train(0) {}
	Ktx(int people) : Train::Train(people) {}
	~Ktx() {}
	void station(int takeOff, int takeOn) override { Train::mPeople = Train::mPeople - takeOff + takeOn; }
	int getPeople() { return Train::mPeople; }
};
int main()
{
	Ktx k;
	bool flag = 0;
	int max = -1;
	for (int i = 1; i <= 5; i++) {
		cout << i << "���� >> "; int off, in; cin >> off >> in;
		k.station(off, in);
		if (k.getPeople() > 300) { cout << "�����ʰ��Դϴ�" << endl; flag = 0; break; }
		else if (k.getPeople() < 0) { cout << "�����̴��Դϴ�" << endl; flag = 0; break; }
		else {
			flag = 1;
			if (i == 1) max = k.getPeople();
			else {
				if (max < k.getPeople()) max = k.getPeople();
			}
		}
	}
	if (flag == 1)	cout << "���� ���� ����� ž������ ���� ��� �� : " << max << endl;
	return 0;
}