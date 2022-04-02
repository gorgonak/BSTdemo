#pragma once
#include <cstddef>

using namespace std;

struct node  // creating our node class to hold our info (data) node and Left / Right nodes.
{
	int info;
	node* Left;
	node* Right; // could also be written as node *Left, *Right;
};

