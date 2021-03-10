#pragma once
#include <iostream>
#include <ctime>

using namespace std;

struct Node 
{
	int data;
	Node* next;
};

struct Cyclic_List
{
	Node* head = NULL;
	int size;

	void Initialization(int size)
	{
		this->size = size;

		head = new Node;
		head->data = rand() % 80 + 1;
		head->next = NULL;

		Node *end = head;

		for (int i = 0; i < size - 1; i++)
		{
			end->next = new Node;
			end = end->next;
			end->data = rand() % 80 + 1;
			end->next = NULL;
		}

		end->next = head;
	}

	void Printing()
	{
		Node* print = head;

		for (int i = 0; i < size; i++)
		{
			cout << print->data << ' ' << endl;
			print = print->next;
		}
	}
};

bool HasCycle_by_Slow_and_Fast_Pointers(Cyclic_List _list)
{
	if (_list.head == NULL)
		return false;

	Node* Slow = _list.head;
	Node* Fast = Slow->next;

	while (Fast != NULL && Slow != NULL)
	{
		Slow = Slow->next;
		Fast = Fast->next;

		if (Fast != NULL)
			if (Slow->next == Fast)
				return true;
	}

	return false;
}

bool HasCycle_by_reverse(Cyclic_List _list)
{
	Node* p_next = _list.head->next;
	Node* previous = NULL;
	Node* present = _list.head;

	while (p_next != NULL)
	{
		present->next = previous;
		previous = present;
		present = p_next;
		if (p_next != NULL)
			p_next = p_next->next;
	}

	_list.head->next = previous;
	_list.head = previous;
	
	if (present == _list.head)
	{
		return true;
	}
		
	else
	{
		return false;
	}
}
