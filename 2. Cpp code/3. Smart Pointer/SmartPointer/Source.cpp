#include <iostream>
#include <memory>

using namespace std;

class Resource
{
public:
	Resource() { cout << "Resource acquire\n"; }
	~Resource() { cout << "Resource Destroyed\n"; }
	string getData() { return "This is Data"; }
};

int main()
{
	unique_ptr<Resource> res(new Resource);

	if (res)
	{
		cout << (*res).getData() << endl;
	}
	return 0;
}