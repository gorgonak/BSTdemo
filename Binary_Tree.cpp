#include "Binary_Tree.h"

using namespace std;

Binary_Tree::Binary_Tree()  // creating our tree and setting the root to NULL
{
	root = NULL;
}

node* Binary_Tree::insert2(node* temp, node* newnode)  // where does the value go & what else needs to be arranged in the tree to accomodate (rearranges the data)
{
	if (temp == NULL)
		temp = newnode;

	else if (temp->info < newnode->info)
	{
		insert2(temp->Right, newnode);
		if (temp->Right == NULL)
			temp->Right = newnode;
	}

	else
	{
		insert2(temp->Left, newnode);
		if (temp->Left == NULL)
			temp->Left = newnode;
	}

	return temp;
}

void Binary_Tree::insert1(int n)  // what the value is that we are inserting (new data insert) recursively calls insert2 to sort the data after it is introduced.
{
	node* temp = root;
	node* newnode;  // could also be written as node* temp = root, newnode;
	newnode = new node;

	newnode->Left = NULL;
	newnode->Right = NULL;
	newnode->info = n;

	root = insert2(temp, newnode);
}

void Binary_Tree::pretrav(node* t)  // this traversal method starts with the root and then goes down the left sub-tree followed by the right sub-tree
{
	if (root == NULL)
		cout << "THERE IS NOTHING IN THE TREE" << endl;
	else if (t != NULL)
	{
		cout << t->info << " ";
		pretrav(t->Left);
		pretrav(t->Right);
	}
}

void Binary_Tree::intrav(node* t)  // traverses to the tree from the left sub-tree to right putting the values producing values in ascending order
{
	if (root == NULL)
		cout << "THERE IS NOTHING IN THE TREE" << endl;
	else if (t != NULL)
	{
		intrav(t->Left);
		cout << t->info << " ";
		intrav(t->Right);
	}
}

void Binary_Tree::posttrav(node* t)  // mainly used for deleting nodes, post order starts from the bottom left to right and moves its way up to the root.
{
	if (root == NULL)
		cout << "THERE IS NOTHING IN THE TREE" << endl;
	else if (t != NULL)
	{
		posttrav(t->Left);
		posttrav(t->Right);
		cout << t->info << " ";
	}
}

int Binary_Tree::findMax(node* t)  // finds the maximum value present in the tree by navigating to the right

{
	
	
	if (root == NULL)
	{
		cout << "THERE IS NOTHING IN THE TREE" << endl;
	}
		
	if (t != NULL)
	{
	node* current = t;

	while(current->Right != NULL)
	{
		current = current->Right;
	}

	cout << "THE MAXIMUM ELEMENT IS: " << current->info << endl;
		
	return(current->info);
	}	
}

void Binary_Tree::Delete(int key)  // traverses the tree looking for the user input value. if it is found it deletes is and then adjusts the rest of the data
{
	node* temp = root;
	node* parent = root;
	node* marker;

	if (temp == NULL)
		cout << "THERE IS NOTHING IN THE TREE TO DELETE" << endl;  // you can get away with no { } if there is only one c++ statement after the if statement
	else
	{
		while (temp != NULL && temp->info != key)
		{
			parent = temp;
			if (temp->info < key)
				temp = temp->Right;
			else
				temp = temp->Left;
		}
	}
	
	marker = temp;

	if (temp == NULL)
		cout << "VALUE NOT FOUND" << endl;
	else if (temp == root)
	{
		if (temp->Right == NULL && temp->Left == NULL)
			root = NULL;
		else if (temp->Left == NULL)
			root = temp->Right;
		else if (temp->Right == NULL)
			root = temp->Left;
		else
		{
			node* temp1;
			temp1 = temp->Right;
			while (temp1->Left != NULL)
			{
				temp = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right)
			{
				temp->Left = temp1->Right;
				temp1->Right = root->Right;
			}
			temp1->Left = root->Left;
			root = temp1;
		}
	}
	else
	{
		if (temp->Right == NULL && temp->Left == NULL)
		{
			if (parent->Right == temp)
				parent->Right = NULL;
			else
				parent->Left = NULL;
		}
		else if (temp->Left == NULL)
		{
			if (parent->Right == temp)
				parent->Right = temp->Right;
			else
				parent->Left = temp->Right;
		}
		else if (temp->Right == NULL)
		{
			if (parent->Right == temp)
				parent->Right = temp->Left;
			else
				parent->Left = temp->Left;
		}
		else
		{
			node* temp1;
			parent = temp;
			temp1 = temp->Right;
			while (temp1->Left != NULL)
			{
				parent = temp1;
				temp1 = temp1->Left;
			}
			if (temp1 != temp->Right)
			{
				temp->Left = temp1->Right;
				temp1->Right = parent->Right;
			}
			temp1->Left = parent->Left;
			parent = temp1;
		}
	}
	delete marker;
}
