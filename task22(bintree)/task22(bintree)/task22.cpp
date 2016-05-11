#include "stdio.h"
#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
	Node *tree = createTree();
	int k;
	while (true)
	{
		cin >> k;
		if (k == 0)
			break;
		tree = addValue(tree, k);
	}
	fprintIncrease(tree, tree);
	cout << endl;
	try
	{
		findEven(tree);
	}
	catch (const exception& exc)
	{
		cout << exc.what() << endl;
		deleteTree(tree);
		throw;
	}
	cout << "false" << endl;
	deleteTree(tree);
	return 0;
}