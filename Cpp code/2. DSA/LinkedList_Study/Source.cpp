#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;

	void Show(Node** head_pt);
	void Push(Node** head_pt, int new_dt);
	void Insert(int new_dt, int idx);
	void Delete(int del_dt);
	void DeleteAt(int pos);
};

void Node::Show(Node** head_pt)
{
	Node *tmp = *head_pt;
	cout << "Data in linked list is: ";
	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

void Node::Push(Node** head_pt, int new_dt)
{
	Node* new_node = new Node();
	new_node->data = new_dt;
	new_node->next = *head_pt;
	*head_pt = new_node;
}

void Node::Insert(int new_dt, int idx)
{
	Node* new_ = new Node();
	Node* tmp_ = this;

	while (tmp_->data != idx)
	{
		tmp_ = tmp_->next;
	}
	new_->data = new_dt;
	new_->next = tmp_->next;
	tmp_->next = new_;
}

void Node::Delete(int del_dt)
{
	Node* tmp;
	Node* prep = this;
	while(prep->next->data != del_dt)
	{
		prep = prep->next;
	}
	tmp = prep->next;
	prep->next = prep->next->next;
	delete tmp;
}

void Node::DeleteAt(int pos)
{
	Node* tmp = this;
	for (int i = 0; i < pos; i++)
	{
		tmp = tmp->next;
	}
	this->Delete(tmp->data);
}

int main()
{
	Node *test = NULL;
	test->Push(&test, 3);
	test->Push(&test, 1);
	test->Insert(2, 1);
	test->Insert(4, 3); 

	test->Show(&test);

	test->DeleteAt(0);
}