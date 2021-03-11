#include "Cyclic_list.h"

int main()
{
	Cyclic_List current;
	int size;
	cout << "Enter the size of the list: ";
	cin >> size;
	current.Initialization(size);
	current.Printing();

	cout << "Checking the list for a cycle using slow and fast pointers: ";
	if (HasCycle_by_Slow_and_Fast_Pointers(current))
		cout << "This list has a cycle" << endl;
	else
		cout << "This list doesn't have a cycle" << endl;

	cout << "Checking the list for a cycle using reverse: ";
	if (HasCycle_by_reverse(current))
		cout << "This list has a cycle" << endl;
	else
		cout << "This list doesn't have a cycle" << endl;

	current.Printing();

	system("pause");
	return 0;
}
	


	