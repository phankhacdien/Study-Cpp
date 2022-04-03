#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Human {
public:
	Human(string name, double age, double weight, double height):
		name_(name), age_(age), weight_(weight), height_(height)
	{}

	double getWeight() { return weight_; };
	double getHeight() { return weight_; };
	void getBMIIndex();
private:
	string name_;
	double age_;
	double weight_;
	double height_;
};

void Human::getBMIIndex()
{
	float bmi = weight_ / pow(height_, 2);
	string BMI_result;

	if ((bmi > 0) && (bmi < 18.5)) {
		BMI_result = "Under weight";
	}
	else if ((bmi >= 18.5) && (bmi < 25)) {
		BMI_result = "Normal";
	}
	else if ((bmi >= 25) && (bmi < 30)) {
		BMI_result = "Over weight";
	}

	std::cout << "BMI scores of  " << name_ << " is: " << bmi << std::endl;
	std::cout << "Physical condition of " << name_ << " is: " << BMI_result << std::endl;
}

int main()
{
	string ob_name;
	double ob_age, ob_height, ob_weight;
	cout << "Your name, please: ";
	cin >> ob_name;
	cout << "Your age: ";
	cin >> ob_age;
	cout << "Your weight (Kg): ";
	cin >> ob_weight;
	cout << "Your height (m): ";
	cin >> ob_height;
	Human* ob = new Human(ob_name, ob_age, ob_weight, ob_height);
	ob->getBMIIndex();
}