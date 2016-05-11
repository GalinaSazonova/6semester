#include "binaryTree.h"

struct Node
{
	int value;
	Node *left;
	Node *right;
};

Node *createNode(int newValue)
{
	Node *root = new Node;
	root->value = newValue;
	root->left = nullptr;
	root->right = nullptr;
	return root;
}

Node *createTree()
{
	return nullptr;
}

Node *parent(Node *root, Node *child)
{
	Node *temp = root;
	while (temp->left != child && temp->right != child)
	{
		if (child->value < temp->value)
		{
			temp = temp->left;
			continue;
		}
		if (child->value > temp->value)
		{
			temp = temp->right;
			continue;
		}
	}
	return temp;
}

Node *max(Node *root)
{
	Node *temp = root;
	while (root->right != nullptr)
	{
		root = root->right;
	}
	return root;
}

int maxVal(Node *root)
{
	return max(root)->value;
}

Node *addValue(Node *root, int value)
{
	if (root == nullptr)
	{
		root = createNode(value);
	}
	if (value < root->value)
	{
		if (root->left == nullptr)
		{
			root->left = createNode(value);
		}
		else
		{
			addValue(root->left, value);
		}
	}
	if (value > root->value)
	{
		if (root->right == nullptr)
		{
			root->right = createNode(value);
		}
		else
		{
			addValue(root->right, value);
		}
	}
	return root;
}

Node *removeLeaf(Node *mainRoot, Node *leaf)
{
	if (leaf->left != nullptr && leaf->right == nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = leaf->left;
		}
		else
		{
			Node *parentOfRoot = parent(mainRoot, leaf);
			if (leaf->left->value > parentOfRoot->value)
			{
				parentOfRoot->right = leaf->left;
			}
			else
			{
				parentOfRoot->left = leaf->left;
			}
		}
	}
	if (leaf->left == nullptr && leaf->right != nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = leaf->right;
		}
		else
		{
			Node *parentOfRoot = parent(mainRoot, leaf);
			if (leaf->right->value > parentOfRoot->value)
			{
				parentOfRoot->right = leaf->right;
			}
			else
			{
				parentOfRoot->left = leaf->right;
			}
		}
	}
	if (leaf->left == nullptr && leaf->right == nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = nullptr;
		}
		else
		{
			Node *parentOfRoot = parent(mainRoot, leaf);
			parentOfRoot->left = nullptr;
			parentOfRoot->right = nullptr;
		}
	}
	delete leaf;
	return mainRoot;
}

void fprintIncrease(Node *root, Node *r)
{
	if (root != nullptr)
	{
		fprintIncrease(root->left, r);
		cout << root->value << " (distance " << distanceToRoot(r, root) << ") ";
		fprintIncrease(root->right, r);
	}
}

int distanceToRoot(Node *root, Node *child)
{
	int i = 0;
	Node *par = child;
	while (par != root)
	{
		i++;
		par = parent(root, par);
	}
	return i;
}

void deleteTree(Node *root)
{
	if (root == nullptr)
	{
		delete root;
		return;
	}
	if (root->left != nullptr)
	{
		deleteTree(root->left);
	}
	if (root->right != nullptr)
	{
		deleteTree(root->right);
	}
	delete root;
}

void findEven(const Node *root)
{
	if (root->value % 2 == 0)
	{
		throw exception("true");
	}
	if (root->left != nullptr)
	{
		findEven(root->left);
	}
	if (root->right != nullptr)
	{
		findEven(root->right);
	}
}