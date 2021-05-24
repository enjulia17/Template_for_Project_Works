#include <iostream>
#include "Search trees.h"

int main()
{
	Tree T;
	T.Push("dan");
	T.Push("dan");
	T.Push("tekst");
	T.Push("bez");
	T.Push("bez");
	T.Push("bez");
	T.Push("zaglavnykh");
	T.Push("bukv");
	cout << "dan dan tekst bez bez bez zaglavnykh bukv" << endl;
	cout << "How many times did the word 'dan' occur in the sentence? " << T.Search("dan") << endl;
	cout << "How many times did the word 'tekst' occur in the sentence? " << T.Search("tekst") << endl;
	cout << "How many times did the word 'bez' occur in the sentence? " << T.Search("bez") << endl;
	cout << "How many times did the word 'zaglavnykh' occur in the sentence? " << T.Search("zaglavnykh") << endl;
	cout << "How many times did the word 'bukv' occur in the sentence? " << T.Search("bukv") << endl;

	system("pause");
	return 0;
}