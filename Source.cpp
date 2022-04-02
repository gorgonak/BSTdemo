#include <ctime>
#include <vector>

#include "Binary_Tree.h"

using namespace std;

void load_data();  // gives the user the ability to load preset data from an array
void rand_data();  // allows uer to select the number of random numbered nodes they want to start with in their tree
void add_rand();  // if the user wants some random data added to the tree they can use this function

Binary_Tree bt;  // initializing the tree class

int main() {

	srand(time(NULL));  // random seed generator for my random number needs

	int choice, data_choice, n, key;
	bool loop = true;

	

	while(loop)
	{
		cout << "\n\nChoose your data option: \n\n\t1. Load Preset Data\n\t2. Load Random Data\n\t3. Create Your Own Data\n\nEnter your choice: " << endl;
		cin >> data_choice;

		switch (data_choice) // this switch cased is used to access the data options before creating the tree.
		{
		case 1:
			system("CLS");
			cout << "\n\nDATA: ";
			load_data();
			cout << endl;
			loop = false;
			break;
		case 2:
			rand_data();
			cout << endl;
			loop = false;
			break;
		case 3:
			loop = false;
			break;
		
		default:
			break;
		}	
	}

	
	while (true) {
		cout << "\n\n\t1. Insert\n\t2. Delete\n\t3. Preorder Traversal\n\t4. Inorder Treversal\n\t5. Postorder Traversal\n\t6. Max Element\n\t7. Add Nodes with Random Data\n\t8. Clear Screen\n\n\t0. Exit\n" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) {  // this switch  cases gives access to the functions based off the user menu created above. 
		case 1:
			cout << "Enter item: ";
			cin >> n;
			bt.insert1(n);  // inserts the user input into the tree
			break;
		case 2:
			cout << "Enter element to delete: ";
			cin >> key;
			bt.Delete(key);  // deletes a specific value (taken from user input) from the tree
			break;
		case 3:
			cout << endl;
			bt.pretrav(bt.root);  // tree navigation (PRE ORDER)
			break;
		case 4:
			cout << endl;
			bt.intrav(bt.root);  // tree navigation (IN ORDER)
			break;
		case 5:
			cout << endl;
			bt.posttrav(bt.root); // tree navigation (POST ORDER)
			break;
		case 6:
			cout << endl;
			bt.findMax(bt.root);  // allows the user to pull the highest (maximum) value from the tree data
			break;
		case 7:
			add_rand();  // adds a variable number of random data to the tree (user specified)
			break;
		case 8:
			system("CLS");  // clears the screen (if needed)
			break;
			
		case 0:
			cout << "Good bye." << endl;  // exits the program 
			return(0);
			
		default:  
			break;
		}
	}

	return 0;
}

void load_data()  // using a preset array of data for the user to load if needed uses a for loops to stuff the data from the array into the BST
{
	int num_array[10] = { 50, 20, 13, 5, 32, 15, 16, 22, 14, 42 };
	
	for (int i = 0; i < 10; i++)
	{
		cout << num_array[i] << " ";
		bt.insert1(num_array[i]);
	}
}

void rand_data() // if the user wants a random data set but doesn't want to manually enter it all they can use this. 
{
	int num = 10;

	cout << "How many nodes would you like in your array?" << endl;
	cin >> num;

	system("CLS");
	cout << "\n\nDATA: ";
	
	int* num_array = new int(num);  // this line turns the array pointer into a faux dynamic array to allow a variable amount of data to be created

	for (int i = 0; i < num; i++)
	{
		const auto rand_num = rand() % 50 + 1;
		num_array[i] = rand_num;  // stuffing the randomly generated numbers into our array one at a time
		
		cout << num_array[i] << " "; // displaying the data for the user to review
		bt.insert1(num_array[i]);  // putting the data into the tree one piece at a time
		
	}
}

void add_rand()  // allows the user to add a variable amount of randomized data into their tree after the initial data set was created.
{
	int num;

	cout << "How many nodes would you like to add?" << endl;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		const auto rand_num = rand() % 50 + 1;
		bt.insert1(rand_num);
	}
}


