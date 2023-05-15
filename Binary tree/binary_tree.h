#include <iostream>
using namespace std;

class Binary_tree
{
	struct Node
	{
		Node* left;
		Node* right;
		Node* parent;
		double data;
		Node(double, Node*, Node*, Node*);
	};
	Node* root;
	void printHelper(Node*,int, char);
	void delete_helper(Node*, double);
public:
	void delete_(double data) { delete_helper(root, data); }
	void insert(double);
	Binary_tree();
	double min();
	double max();
	bool search(double);
	void print();
	bool empty() { return root == nullptr; }
};
