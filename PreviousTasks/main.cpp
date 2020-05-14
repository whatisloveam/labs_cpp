/*
Author: Melnikov Vladislav Andreevich
Group: ÐÈ280001
In this program i have done that tasks:
1.Sorting arrays with pointers
2.Max and min element of array
3.prev max, prev min
4.Find missing item
5.function which create structure with fields
*/

#include <iostream> 
#include <string> 

using namespace std;

void sort(int* st, int* end) // start and end pointers
{

	for (int i = 0; i < (end - st + 1); i++)
	{
		for (int j = i + 1; j < (end - st + 1); j++)
		{
			if (*(st + i) > * (st + j))
			{
				int t = *(st + i);
				*(st + i) = *(st + j);
				*(st + j) = t;
			}
		}
	}
}


int findMax(int* st, int* end) //start and end pointers
{
	int max = INT32_MIN;
	for (int i = 0; i < (end - st + 1); i++)
		if (st[i] > max) max = st[i];
	return max;
}

int findMin(int* st, int* end) //start and end pointers
{
	int min = INT32_MAX;
	for (int i = 0; i < (end - st + 1); i++)
		if (st[i] < min) min = st[i];
	return min;
}


int findPredMax(int* st, int* end) //start and end pointers
{
	int max = INT32_MIN;
	int predmax = INT32_MIN;
	for (int i = 0; i < (end - st + 1); i++)
	{
		if (st[i] > max)
		{
			if (max > predmax) predmax = max;
			max = st[i];
		}
	}
	return predmax;
}

int findPredMin(int* st, int* end) //start and end pointers
{
	int min = INT32_MAX;
	int predmin = INT32_MAX;
	for (int i = 0; i < (end - st + 1); i++)
	{
		if (st[i] < min)
		{
			if (min < predmin) predmin = min;
			min = st[i];
		}
	}

	return predmin;
}

void findMissingElement(int* st, int* end) //start and end pointers
{
	for (int i = 1; i < (end - st + 1); i++) {
		if (st[i] - st[i - 1] != 1) {
			cout << st[i] - 1 << " is missing" << endl;
			break;
		}
	}
}

void printFirst(int* ptr, int n) // just print first n elements of array 
{
	for (int i = 0; i < n; i++)
		cout << *(ptr + i) << " ";
}

struct Person 
{
	int age;
	string name;
	char letter;
};

Person AddPerson(int age, string name, char letter)
{
	Person temp;
	temp.age = age;
	temp.name = name;
	temp.letter = letter;
	return temp;
}

void CreateAndPrintPerson()
{
	Person firstPerson = AddPerson(10, "Petya", 'b');
	cout << firstPerson.age << '\n';
	cout << firstPerson.name << '\n';
	cout << firstPerson.letter;
}


int main()
{
	//Sorting with pointers
	int arr[] = { -12, 3523, 123, 12, 666, 5, 2, 310, 228, 69 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printFirst(arr, n);
	cout << endl << "sort part of array form 3 to 6" << endl;
	sort(arr+3, arr+6);
	printFirst(arr, n);
	cout << endl << "sort all array" << endl;
	sort(arr, arr + n - 1);
	printFirst(arr, n);

	cout << endl << endl << "Source array: ";
	int arr2[] = { -12, 213, 30, 12, 666, -35, 2, 23, 74, 69 };
	printFirst(arr2, n);
	cout << endl;
	//Max and min element of array
	cout << endl << "Max: " << findMax(arr2, arr2+n-1) << endl;
	cout << "Min: " << findMin(arr2, arr2+n-1) << endl;

	//prev max, prev min
	cout << endl << "Max without max: " << findPredMax(arr2, arr2+n-1) << endl;
	cout << "Min without min: " << findPredMin(arr2, arr2+n-1) << endl;
	cout << endl << endl;

	//Find missing item
	int arr3[] = { 4, 5, 7, 8, 9, 10, 11 };
	int m = sizeof(arr3) / sizeof(arr[0]);
	printFirst(arr3, m);
	cout << endl;
	findMissingElement(arr3, arr3+m-1);

	//function which create structure with fields
	CreateAndPrintPerson();
	return 0;
}

