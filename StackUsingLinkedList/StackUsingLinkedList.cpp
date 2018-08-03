#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void mainmenu();
void push();
void pop();
void display();

struct node
{
	int data;
	node *link;
}; node *top = NULL, *newNode, *current, *temp;

void main()
{
	mainmenu();

	cout << endl;
	system("pause");
}

void mainmenu()
{
	system("CLS");
	cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter your choice:\n";
	switch (_getch())
	{
	case '1':
		push();
		break;
	case '2':
		pop();
		break;
	case '3':
		display();
		break;
	case '4':
		exit(0);
		break;
	default:
		cout << "\n\aWrong entry!!!";
		break;
	}
}
void push()
{
	system("CLS");

	newNode = new node;
	cout << "Enter integer you want to insert: ";
	cin>>newNode->data;

	if (top==NULL)
	{
		newNode->link = NULL;
		top = newNode;
	}
	else
	{
		newNode->link = top;
		top = newNode;
	}

	cout << "\nItem is successfully inserted in the list!\n";

	cout << "\nNew list:\n";
	current = top;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->link;
	}

	cout << "\n\nPress ENTER to add more or ESCAPE to go back to Main Menu.";
	char ch = _getch();
	if (ch == 13)
		push();
	else if (ch == 27)
		mainmenu();
	else
		cout << "\n\aWrong entry!!!";
	mainmenu();

}
void pop()
{
	system("CLS");
	if (top == NULL)
	{
		cout << "\n\aList is empty!";

		cout << "\n\nPress 1 to insert an item or ESCAPE to go back to Main Menu.";

		char ch = _getch();
		if (ch == 1)
			push();
		else if (ch == 27)
			mainmenu();
		else
			cout << "\n\aWrong entry!!!";
		mainmenu();
	}
	else
	{
		int n = top->data;
		temp = top;
		top = temp->link;
		delete temp;

		cout << "\n" << n << " is successfully deleted from the list!\n";

		cout << "\nNew list:\n";
		current = top;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->link;
		}

		cout << "\n\nPress ENTER to delete more or ESCAPE to go back to Main Menu.";
		char ch = _getch();
		if (ch == 13)
			pop();
		else if (ch == 27)
			mainmenu();
		else
			cout << "\n\aWrong entry!!!";
		mainmenu();
	}
	
}
void display()
{
	system("CLS");
	if (top==NULL)
	{
		cout << "\n\aList is empty!";

		cout << "\n\nPress 1 to insert an item or ESCAPE to go back to Main Menu.";

		char ch = _getch();
		if (ch == 1)
			push();
		else if (ch == 27)
			mainmenu();
		else
			cout << "\n\aWrong entry!!!";
		mainmenu();
	} 
	else
	{
		cout << "List:\n";
		current = top;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->link;
		}

		cout << "\n\nPress any key to go back to Main Menu.";
		if (_getch())
			mainmenu();
	}
}