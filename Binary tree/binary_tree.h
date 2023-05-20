#include <iostream>
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

Binary_tree::Node::Node(double data = NULL, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
	data(data), parent(parent), left(left), right(right) {}

void Binary_tree::printHelper(Node* node, int spaceCount, char c)
{
	if (node->right != nullptr) {
		printHelper(node->right, spaceCount + 5, '/');
	}
	int sp = spaceCount - 3;
	for (int i = 0; i < sp; ++i) {
		std::cout << " ";
	}
	sp = spaceCount - sp;
	std::cout << c;
	for (int i = 0; i < sp; ++i) {
		std::cout << "-";
	}
	std::cout << node->data;
	std::cout << std::endl;
	if (node->left != nullptr) {
		printHelper(node->left, spaceCount + 5, '\\');
	}
}

void Binary_tree::delete_helper(Node* root, double data)
{
	if (root == nullptr)
		return;
	if (root->data > data)
		return delete_helper(root->left, data);
	else if (root->data < data)
		return delete_helper(root->right, data);
	else
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			if (root->parent->data > root->data)
			{
				root->parent->left = nullptr;
			}
			else
			{
				root->parent->right = nullptr;
			}
		}
		else if (root->left == nullptr && root->right != nullptr)
		{
			if (root->parent->data > root->data)
			{
				root->parent->left = root->right;
			}
			else
			{
				root->parent->right = root->right;
			}
		}
		else if (root->left != nullptr && root->right == nullptr)
		{
			if (root->parent->data > root->data)
			{
				root->parent->left = root->left;
			}
			else
			{
				root->parent->right = root->left;
			}
		}
		else
		{
			while (root->left != nullptr)
			{
				root = root->left;
				std::swap(root->data, root->parent->data);
			}
			root->parent->left = root->right;

		}
	}
}
void Binary_tree::insert(double data)
{
	if (root == nullptr)  root = new Node(data);
	else
	{
		Node* counter = root;
		while (counter != nullptr)
		{
			if (counter->data > data)
			{
				if (counter->left == nullptr) break;
				counter = counter->left;
			}
			else if (counter->data < data)
			{
				if (counter->right == nullptr) break;
				counter = counter->right;
			}
			else return;
		}
		if (counter->data > data)
		{
			counter->left = new Node(data, counter);
		}
		else counter->right = new Node(data, counter);
	}
}
Binary_tree::Binary_tree()
{
	root = nullptr;
}
double Binary_tree::min()
{
	if (root != nullptr)
	{
		Node* counter = root;
		int min = counter->data;
		while (counter->left != nullptr)
		{
			min = (counter->left)->data;
			counter = counter->left;
		}
		return min;
	}
}
double Binary_tree::max()
{
	if (root != nullptr)
	{
		Node* counter = root;
		int max = counter->data;
		while (counter->right != nullptr)
		{
			max = (counter->right)->data;
			counter = counter->right;
		}
		return max;
	}
}

bool Binary_tree::search(double data_)
{
	Node* counter = root;
	while (counter != nullptr)
	{
		if (data_ == counter->data)
		{
			return true;
		}
		else if (data_ > counter->data)
		{
			counter = counter->right;
		}
		else if (data_ < counter->data)
		{
			counter = counter->left;
		}
	}
	return false;
}

void Binary_tree::print()
{
	if (root != nullptr) {
		printHelper(root, 0, 0);
	}
}