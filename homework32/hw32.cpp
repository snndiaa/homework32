#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 20;

void shuffle_array(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = rand() % size;  
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int find_random_position(int arr[], int size, int random_num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == random_num)
        {
            return i;
        }
    }
    return -1;
}

void sort_descending(int arr[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = left; j < right - 1 - (i - left); ++j)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_ascending(int arr[], int left, int right)
{
    for (int i = left; i < right; i++)
    {
        for (int j = left; j < right - 1 - (i - left); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_array(int arr[], int size, int pos)
{
    if (pos > 0)
    {
        sort_descending(arr, 0, pos);
    }
    if (pos < size - 1)
    {
        sort_ascending(arr, pos + 1, size);
    }
}

int main()
{
    srand(time(0));
    int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    shuffle_array(arr, SIZE);

    cout << "Your array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int random_num = arr[rand() % SIZE];
    cout << "Random number: " << random_num << endl;

    int pos = find_random_position(arr, SIZE, random_num);
    cout << "Position: " << pos << endl;

    sort_array(arr, SIZE, pos);

    cout << "Modified array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
	cout << endl;

    return 0;
}