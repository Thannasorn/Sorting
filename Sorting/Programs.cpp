#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include "Sorting.h"

using namespace std;

vector<int> container;

bool flag = false;

int Menu()
{
	string output;
	int choice;

	output = "Assignment 4 : Sorting\n";
	output += "======================\n";
	output += " 1. Enter Input\n";
	output += " 2. Insertion Sort\n";
	output += " 3. Quick Sort\n";
	output += " 4. Quit\n";
	output += "Enter Choice : ";

	system("CLS");

	cout << output;
	cin >> choice;

	return choice;
}

void EnterInput()
{
	int items;

	do
	{
		cout << "\nHow many items ? : ";
		cin >> items;

		if (items < 1)
		{
			cout << "\n => Error! Please enter more than 0.\n";

			system("PAUSE");
		}
		else
		{
			container.resize(items);

			int element;

			for (int n = 0; n < items; n++)
			{
				do
				{
					cout << "\nEnter Element " << (n + 1) << " : ";
					cin >> element;

					if (element < 0)
					{
						cout << "\n => Error! Please enter more than or equal 0.\n";

						system("PAUSE");
					}
					else
					{
						container[n] = element;
					}
				} while (element < 0);
			}

			cout << "\n => Success! Input Finished.\n";

			system("PAUSE");
		}
	} while (items < 1);

	flag = true;
}

void Insertion()
{
	if (flag)
	{
		cout << "\nOriginal       ";

		for (unsigned int n = 0; n < container.size(); n++)
		{
			cout << container[n] << setw(5) << setfill(' ') << " ";
		}

		cout << "   P. Moved\n";
		cout << setw(96) << setfill('-') << "-\n";

		clock_t c_start = clock();

		insertionSort(container);

		clock_t c_end = clock();

		double elapsed = c_end - c_start;

		cout << "\nUsed time : [ " << elapsed / CLOCKS_PER_SEC << " sec. ]" << endl;
	}
	else
	{
		cout << "\n => Error! Please enter input first.\n";
	}

	system("PAUSE");
}

void Quick()
{
	if (flag)
	{
		int cutoff;

		do
		{
			cout << "\nEnter Cutoff : ";
			cin >> cutoff;

			if (cutoff > 0)
			{
				cout << "\nOriginal     ";

				for (unsigned int n = 0; n < container.size(); n++)
				{
					cout << container[n] << setw(5) << setfill(' ') << " ";
				}

				cout << endl;

				cout << setw(78) << setfill('-') << "-\n";

				clock_t c_start = clock();

				quickSort(container, cutoff);

				clock_t c_end = clock();

				double elapsed = c_end - c_start;

				cout << "\nUsed time : [ " << elapsed / CLOCKS_PER_SEC << " sec. ]" << endl;
			}
			else
			{
				cout << "\n => Error! Please enter more than 0.\n";
			}
		} while (cutoff < 1);
	}
	else
	{
		cout << "\n => Error! Please enter input first.\n";
	}

	system("PAUSE");
}

void main()
{
	int choice;

	do
	{
		choice = Menu();

		switch (choice)
		{
			case 1: EnterInput();
				break;
			case 2: Insertion();
				break;
			case 3: Quick();
				break;
			case 4: exit(0);
				break;
			default: cout << "\n => Error! Please enter only 1 - 4.\n";
					 system("PAUSE");
				break;
		}
	} while (choice != 4);

	system("PAUSE");
}