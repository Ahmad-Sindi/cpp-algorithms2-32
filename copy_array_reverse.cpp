/* Algorithm Challenge & Problem Solving
 * 32 - Copy Array in Reverse Order
 *
 * This program fills an array (max size 100) with random numbers from 1 to 100.
 * It then copies the entire array into a second array, but in reverse order.
 *
 * Concepts Reinforced:
 *   - Using rand() to generate random values
 *   - Working with arrays and indices
 *   - Reverse-order copying using indexing logic
 *   - Passing arrays to functions
 *   - Understanding how to map forward indices to reversed ones
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Generates a random number between From and To (inclusive)
int Randnumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Fills an array with random numbers from 1 to 100
void FillArrayWithRandomNumbers(int arr[100], int &ArrayLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> ArrayLength;

    for (int i = 0; i < ArrayLength; i++)
        arr[i] = Randnumber(1, 100); // Fill with random values
}

// Prints all elements of the array
void PrintArray(int arr[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

// Copies array into another array in reverse order
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int ArrayLength)
{
    // Reverse copy technique:
    // arrDestination[i] = arrSource[lastIndex - i]
    for (int i = 0; i < ArrayLength; i++)
    {
        /*
            Explanation:
            - ArrayLength - 1 gives the last valid index.
            - Subtracting i walks from end to start.
            - When i = 0 → copy arrSource[last]
            - When i = 1 → copy arrSource[last - 1]
            - ...
            - This perfectly reverses the array.
        */
        arrDestination[i] = arrSource[ArrayLength - 1 - i];
    }
}

int main()
{
    // Seed random generator (call once)
    srand((unsigned)time(NULL));

    int arr[100], ArrayLength;

    FillArrayWithRandomNumbers(arr, ArrayLength);

    int arr2[100];
    CopyArrayInReverseOrder(arr, arr2, ArrayLength);

    cout << "\nArray 1 Elements     : ";
    PrintArray(arr, ArrayLength);

    cout << "\nCopy Array 2 Elements: ";
    PrintArray(arr2, ArrayLength);

    return 0;
}
