#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class Binary_Tree
{

public:
	node* root;
	Binary_Tree();
	void insert1(int n);
	node* insert2(node* temp, node* newnode);
	void Delete(int key);

	void pretrav(node* root);
	void intrav(node* root);
	void posttrav(node* root);

	int findMax(node* root);

};
