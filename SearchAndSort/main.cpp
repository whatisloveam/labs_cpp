#include <iostream>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;

constexpr int N = 1000;
constexpr int M = 100;//N for second task

int Search(const int* array, int size, int value) // without sorted array
{
    for (int i = 0; i < size; ++i)
        if (array[i] == value)
            return i;
    return -1001; // not contain, can't use -1 because random values for task in range(-1000, 1000)
}


void RandomArrayFill(int* arr, int size, int min, int max) {
    std::default_random_engine generator(time(0));
    std::uniform_int_distribution<int> distribution(min + 1, max - 1);
    for (int i = 0; i < size; ++i)
        arr[i] = distribution(generator);
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void QuickSort(int* arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        } while (left <= right);
        QuickSort(arr, first, right);
        QuickSort(arr, left, last);
    }
}


int partition(int* arr, int start, int end)
{
    int pivot = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

void NotRecursiveQuickSort(int *arr, int start, int end)
{
    int* stack = new int[end - start + 1];

    int top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0) 
    {
        end = stack[top--];
        start = stack[top--];

        int p = partition(arr, start, end);

        if (p - 1 > start) 
        {
            stack[++top] = start;
            stack[++top] = p - 1;
        }
        if (p + 1 < end) 
        {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
    delete[] stack;
}

int BSearch(int* arr, int val, int left, int right) {
    int mid = (right + left) / 2;
    if (arr[mid] == val)
        return mid;
    if (arr[mid] > val)
        return BSearch(arr, val, left, mid);
    if (arr[mid] < val)
        return BSearch(arr, val, mid + 1, right);
    return -1;
}

int NotRecursiveBSearch(const int* arr, int value, int left, int right) {
    while (right >= left) {
        int mid = (right + left) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            right = mid;
        if (arr[mid] < value)
            left = mid + 1;
    }
    return -1;
}

void PrintFirst(int* arr, int n, string prefix)
{
    cout << prefix;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(0));
    //first task linear search
    int arr[N];
    RandomArrayFill(arr, N, -1000, 1000);
    cout << "linear search result: " << Search(arr, N, 43) << endl;

    //Second task recursive quicksort
    int arr2[M];
    RandomArrayFill(arr2, M, -10, 10);
    PrintFirst(arr2, 30, "randoms ");
    QuickSort(arr2, 0, M - 1);
    PrintFirst(arr2, 30, "recusive quicksort ");

    //not recursive quicksort

    int arr3[M];
    RandomArrayFill(arr3, M, -10, 10);
    PrintFirst(arr3, 50, "randoms ");
    NotRecursiveQuickSort(arr3, 0, M - 1);
    PrintFirst(arr3, 50, "not recusive quicksort ");

    //third task recursive BinarySearch
    int arr4[] = { 1, 2, 3, 4, 5 };
    cout << BSearch(arr4, 1, 0, 4) << endl;
    cout << NotRecursiveBSearch(arr4, 5, 0, 4) << endl;
    //fourth task time compare
    int arr5[N];
    RandomArrayFill(arr5, N, -10, 10);
    PrintFirst(arr5, 50, "randoms ");


    auto beginLinearSearch = std::chrono::steady_clock::now();
    Search(arr5, N, 8);
    auto endLinearSearch = std::chrono::steady_clock::now();

    QuickSort(arr5, 0, N - 1);

    PrintFirst(arr5, 50, "sorted ");

    auto beginRecursiveBinarySearch = std::chrono::steady_clock::now();
    BSearch(arr5, 8, 0, N - 1);
    auto endRecursiveBinarySearch = std::chrono::steady_clock::now();

    auto beginNotRecursiveBinarySearch = std::chrono::steady_clock::now();
    NotRecursiveBSearch(arr5, 8, 0, N - 1);
    auto endNotRecursiveBinarySearch = std::chrono::steady_clock::now();

    auto linearSearchTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endLinearSearch - beginLinearSearch).count();
    auto recursiveBinarySearchTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endRecursiveBinarySearch - beginRecursiveBinarySearch).count();
    auto notRecursiveBinarySearchTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endNotRecursiveBinarySearch - beginNotRecursiveBinarySearch).count();

    std::cout << "Linear search time: " << linearSearchTime << " ns" << endl;
    std::cout << "Recursive binary search time: " << recursiveBinarySearchTime << " ns" << endl;
    std::cout << "Not recursive binary search time: " << notRecursiveBinarySearchTime << " ns" << endl;
}