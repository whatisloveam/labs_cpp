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

//prototypes....
void sort(int n, int* ptr, int start, int end);
void CreateAndPrintPerson();

int main()
{
	//Sorting with pointers
#pragma region ArraySortByPointers
	int n = 10;
	int arr[] = { -12, 3523, 123, 12, 666, 5, 2, 310, 228, 69 };
	cout << "sort part of array form 3 to 6" << endl;
	sort(n, arr, 3, 6);
	cout << endl << "sort all array" << endl;
	sort(n, arr, 0, n - 1);
#pragma endregion

	//Max and min element of array
#pragma region MaxAndMin
	cout << endl << "Max: " << *(arr + n - 1) << endl;
	cout << "Min: " << *arr << endl;
	//prev max, prev min
	cout << endl << "Max without max: " << *(arr + n - 2) << endl;
	cout << "Min without min: " << *(arr + 1) << endl;
	cout << endl << endl;
#pragma endregion
	//Find missing item
#pragma region FindMissing
	int arr2[] = { 4, 5, 7, 8, 9, 10, 11 };
	int m = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < m; i++) {
		if (arr2[i] - arr2[i - 1] != 1) {
			cout << arr2[i] - 1 << " is missing" << endl;
			break;
		}
	}
#pragma endregion
	//function which create structure with fields
#pragma region CreatingStucture
	CreateAndPrintPerson();
#pragma endregion
	return 0;
}

struct Person {
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

void sort(int n, int* ptr, int start, int end)
{
	int i, j, tmp;

	for (i = start; i <= end; i++) {
		for (j = i + 1; j <= end; j++) {
			if (*(ptr + j) < *(ptr + i)) {
				tmp = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		cout << *(ptr + i) << " ";
}