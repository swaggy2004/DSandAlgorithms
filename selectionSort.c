/* The main function of Selection Sort is,
    1. to find the minimum value during each itteration and store it.
    2. Change it with the value we started that specific itteration with.
 */

#include <stdio.h>

void selectionSort(int array[], int n);

int main(void)
{
    // Initalizing the array and size of the array
    int arr[] = { 9, 2, 4, 1, 7}, size = sizeof(arr) / sizeof(int);

    // Print the unsorted array
    printf("Before Selection Sort: ");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Calling the Selection Sort function
    selectionSort(arr, size);
    return 0;
}

void selectionSort(int array[], int n)
{
    // Make variables to store the minimum value and it's index
    int minIndex, minValue;
    for (int i = 0; i < n - 1; i++)
    {
        // Set the index and value to whatever is at the start of each iteration
        minIndex = i;
        minValue = array[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            // Check if the current minimum value is greater than something else in the array
            if (minValue > array[j])
            {
                // Override what was in the varriables perviously
                minValue = array[j];
                // Why do we need the index? So when finish this loop we know at what index we can find the minimum value was and then later use it to store the starting vaue to that index.
                minIndex = j;
            }
        }
        // Assign the strating value of the iteration to tmp
        int tmp = array[i];
        // Swap what was in the starting position with the minimum value
        array[i] = minValue;
        // Go to where the minimum value was a put was in the staritng position
        array[minIndex] = tmp;
    }
    // Print array
    printf("After Selection Sort: ");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}