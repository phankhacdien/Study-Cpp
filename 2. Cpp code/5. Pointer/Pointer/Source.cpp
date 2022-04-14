#include <iostream>

using namespace std;

struct Human {
	Human(int t, float vong_1, float chieu_cao) {
		age = t;
		v1 = vong_1;
		height = chieu_cao;
	}
	int age;
	float v1, height;
};


int main()
{
	Human Thao(23, 99, 160.5);
	Human Trang(22, 90, 163.5);
	Human Linh(24, 95, 155);

	Human *girl_fr = nullptr;

	// Monday
	girl_fr = &Thao;
	cout << "Girls friend age: " << (*girl_fr).age << endl;

	// Tuesday
	girl_fr = girl_fr + 1;
	cout << "Girls friend v1: " << (*girl_fr).v1 << endl;

	return 0;
}