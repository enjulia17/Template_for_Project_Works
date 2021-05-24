#pragma once
#include <string>

using namespace std;

struct Node
{
	string val;
	int count;
	Node *left, *right;
	Node(string str = "") : val(str), count(1), left(nullptr), right(nullptr) {};
};

class Tree
{
protected:
	Node* root = nullptr;
public:
	Node* GetRoot();
	void Push(string str);
	int Search(string str);
};

Node* Tree::GetRoot()
{
	return root;
}

void Tree::Push(string str)
{
	if (root == nullptr)
	{
		Node* new_elem = new Node(str);
		root = new_elem;
		return;
	}
	Node* temp = root;
	while (temp != nullptr)
	{
		if ((str < temp->val) && (temp->left == nullptr))
		{
			Node* new_elem = new Node(str);
			temp->left = new_elem;
			return;
		}
		else if (str < temp->val)
		{
			temp = temp->left;
			continue;
		}
		if ((str > temp->val) && (temp->right == nullptr))
		{
			Node* new_elem = new Node(str);
			temp->right = new_elem;
			return;
		}
		else if (str > temp->val)
		{
			temp = temp->right;
			continue;
		}
		if (str == temp->val)
		{
			temp->count++;
			return;
		}
	}
}

int Tree::Search(string str)
{
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->val > str)
		{
			temp = temp->left;
		}
		else if (temp->val < str)
		{
			temp = temp->right;
		}
		else if (temp->val == str)
		{
			return temp->count;
		}
	}
	return 0;
}

