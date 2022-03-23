#ifndef SOTRING_H
#define SORTING_H
	#include <iostream>
	#include <iomanip>
	#include <vector>

	using namespace std;

	template <class Comparable>
	const Comparable & median3(vector<Comparable> & a, int left, int right);

	template <class Comparable>
	inline void swapPos(Comparable & obj1, Comparable & obj2);

	template <class Comparable>
	void insertionSort(vector<Comparable> & a);

	template <class Comparable>
	void insertionSort(vector<Comparable> & a, int left, int right);

	template <class Comparable>
	void quickSort(vector<Comparable> & a, int cutoff);

	template <class Comparable>
	void quickSort(vector<Comparable> & a, int left, int right, int cutoff, int & round);

	template <class Comparable>
	const Comparable & median3(vector<Comparable> & a, int left, int right)
	{
		int center = (left + right) / 2;

		if (a[center] < a[left])
			swapPos(a[left], a[center]);
		if (a[right] < a[left])
			swapPos(a[left], a[right]);
		if (a[right] < a[center])
			swapPos(a[center], a[right]);

		// Place pivot at position right - 1
		swapPos(a[center], a[right - 1]);

		return a[right - 1];
	}

	template <class Comparable>
	inline void swapPos(Comparable & obj1, Comparable & obj2)
	{
		Comparable tmp = obj1;

		obj1 = obj2;
		obj2 = tmp;
	}

	template <class Comparable>
	void insertionSort(vector<Comparable> & a)
	{
		for (unsigned int p = 1; p < a.size(); p++)
		{
			Comparable tmp = a[p];
			int moved = 0;

			int j;

			for (j = p; j > 0 && tmp < a[j - 1]; j--)
			{
				a[j] = a[j - 1];
				
				++moved;
			}

			a[j] = tmp;

			cout << "After p = " << p << "    ";

			for (unsigned int n = 0; n < a.size(); n++)
			{
				cout << a[n] << setw(5) << setfill(' ') << " ";
			}

			cout << "   " << moved << endl;
			cout << "   " << j << endl;
		}
	}

	template <class Comparable>
	void insertionSort(vector<Comparable> & a, int left, int right)
	{
		int moved = 0;

		for (int p = left + 1; p <= right; p++)
		{
			Comparable tmp = a[p];
			int j;

			for (j = p; j > left && tmp < a[j - 1]; j--)
			{
				a[j] = a[j - 1];

				++moved;
			}

			a[j] = tmp;

			cout << "\nAfter p = " << p << "  ";

			for (unsigned int n = 0; n < a.size(); n++)
			{
				cout << a[n] << setw(5) << setfill(' ') << " ";
			}

			cout << "\n\tMoved = " << moved << endl;
		}
	}

	template <class Comparable>
	void quickSort(vector<Comparable> & a, int cutoff)
	{
		int round = 0;

		quickSort(a, 0, a.size() - 1, cutoff, round);
	}

	template <class Comparable>
	void quickSort(vector<Comparable> & a, int left, int right, int cutoff, int & round)
	{
		if (left + cutoff <= right)
		{
			Comparable pivot = median3(a, left, right);

			// Begin partitioning
			int i = left, j = right - 1;

			++round;

			for (; ; )
			{
				while (a[++i] < pivot) {}

				while (pivot < a[--j]) {}

				if (i < j)
				{
					swapPos(a[i], a[j]);
				}
				else
				{
					break;
				}
			}

			swapPos(a[i], a[right - 1]);  // Restore pivot

			cout << "\nRound " << round << "      ";

			for (unsigned int n = 0; n < a.size(); n++)
			{
				cout << a[n] << setw(5) << setfill(' ') << " ";
			}

			cout << "\n\tPivot = " << pivot << endl;

			quickSort(a, left, i - 1, cutoff, round);     // Sort small elements
			quickSort(a, i + 1, right, cutoff, round);    // Sort large elements
		}
		else  // Do an insertion sort on the subarray
		{
			insertionSort(a, left, right);
		}
	}

#endif