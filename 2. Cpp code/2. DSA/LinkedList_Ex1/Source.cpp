#include<iostream>
#include<string>

using namespace std;

class StudentList
{
public:
	string name_, grade_, phone_;
	int score_;
	int idx_;
	StudentList* next = NULL;

	StudentList(string name, string grade, string phone, int score, int idx)
	{
		name_ = name;
		grade_ = grade;
		phone_ = phone;
		score_ = score;
	}
	void addStudent(string name, string grade, string phone, int score, int idx);
	void ShowList();
	string GetPhoneNum(string name);
	void removeStudent(string grade);
};

void StudentList::removeStudent(string grade)
{

}

string StudentList::GetPhoneNum(string name)
{
	StudentList* phone_num = this;
	while (phone_num->name_ != name)
	{
		phone_num = phone_num->next;
		if (phone_num == NULL) break;
	}

	if (phone_num != NULL) return phone_num->phone_;
	else { return "Can find " + name + " in student list."; }
}

void StudentList::ShowList()
{
	StudentList* temp = this;
	cout << "name" << "\t" << "grade" << "\t" << "phone" << "\t" << "score" << endl;
	while (temp != NULL)
	{
		cout << temp->name_ << "\t" << temp->grade_ << "\t" << temp->phone_ << "\t" << temp->score_ << endl;
		temp = temp->next;
	}
}

void StudentList::addStudent(string name, string grade, string phone, int score, int idx)
{
	StudentList* new_std =  new StudentList(name, grade, phone, score, idx);

	if (idx == 'f')
	{
		StudentList temp = *this;
		*this = *new_std;
		*new_std = temp;
		this->next = new_std;
	}
	else if (idx == 'l')
	{
		StudentList* last = this;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_std;
	}
}

int main()
{
	StudentList std_lst("Nam", "3", "09887654321", 7, 0);
	std_lst.addStudent("Hieu", "2", "01649128698", 8, 'f');
	std_lst.addStudent("Tuan", "3", "24985720394", 6, 'f');
	std_lst.ShowList();

	string test = std_lst.GetPhoneNum("DIEN");
	cout << test;
}