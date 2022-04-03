#include <iostream>
#include <memory>

using namespace std;

class Shape
{
public:
	Shape(int w, int h):
		w_(w),h_(h)
	{
		cout << "Resource acquired!\n";
	}
	~Shape() { cout << "Resource released!\n"; }

	int Area() 
	{ 
		AreaCal();
		return a; 
	}

protected:
	int w_, h_;
	int a;

	virtual void AreaCal()
	{
		a = (w_ * h_) / 2;
	}
};

class Triangle : public Shape
{
public:
	Triangle(int w, int h) :
		Shape(w,h) {}
};


class Rectangle :public Shape
{
public:
	Rectangle(int w, int h) :
		Shape(w, h) {}

protected:
	void AreaCal()
	{
		a = w_ * h_;
	}
};

int main()
{
	int width, high;
	cout << "Enter width and high: "; cin >> width >> high;
	
	unique_ptr<Rectangle> normal =  make_unique<Rectangle>(width, high);
	int area = normal->Area();

	cout << "Area is: " << area << endl;
	return 0;
}