#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

struct Node;
Node *createNode(int newValue);
Node *createTree();
Node *parent(Node *root, Node *child);
Node *max(Node *root);
int maxVal(Node *root);
Node *addValue(Node *root, int value);
Node *removeLeaf(Node *mainRoot, Node *leaf);
void fprintIncrease(Node *root, Node *r);
void deleteTree(Node *root);
void findEven(const Node *root);
int distanceToRoot(Node *root, Node *child);



