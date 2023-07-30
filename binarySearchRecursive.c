#include <stdio.h>

int binarySearch(int arr[], int startIndex, int endIndex, int key);

int main (void)
{
    int array[10] = {2, 8, 9, 11, 15, 45, 58, 78, 99};
    int start = 0, end = sizeof(array) / sizeof(int), target = 2;
    int result = binarySearch(array, start, end, target);
    if (result != -1)
    {
        printf("Target found at index: %d\n", result);
        return 0;
    }
    else
    {
        printf("Target not found.\n");
        return 1;
    }
}

int binarySearch(int arr[], int startIndex, int endIndex, int key)
{
    // Check if the array is valid or not
    if (startIndex > endIndex)
    {
        return -1;
    }
    else
    {
        // Find the middle index
        int middleIndex = (startIndex + endIndex) / 2;

        // Check if the key is greater than, less than, or equal to the middle index
        if (key > arr[middleIndex])
        {
            // If the key is greater than the middle index then we know that the key is in the right half of the array
            return binarySearch(arr, ++middleIndex, endIndex, key);
        }
        // Check if the key is less than the middle index
        else if (key < arr[middleIndex])
        {
            // If the key is less than the middle index then we know that the key is in the left half of the array
            return binarySearch(arr, startIndex, --middleIndex, key);
        }
        // If the key is equal to the middle index then we know that the key is in the middle of the array
        else
        {
            // Return the middle index
            return middleIndex;
        }
    }
}