#include "binary_tree.cpp"

int main()
{
	Binary_tree a;
	a.insert(5);
	a.insert(4);
	a.insert(6);
	a.insert(4.5);
	a.delete_(4);
	a.print();
	return 0;
}