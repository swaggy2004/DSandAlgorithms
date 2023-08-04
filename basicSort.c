#include <stdio.h>

int main(void)
{
    // Initialising the array
    int array[] = {3, 6, 7, 1, 4, 2, 8, 5};

    // Printing the unchanged array
    printf("Unsorted: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sorting the array
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            // To sort in ascending order

            // Checks if there are numbers after the ith position that are smaller. This logic can be flipped to get the descending order
            if (array[j] < array[i])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }

    printf("Sorted: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}