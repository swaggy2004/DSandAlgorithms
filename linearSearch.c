#include <stdio.h>

int main(void)
{
    int arr[] = {1, 4, 2, 7, 9, 3, 5, 21, 69}, state = 0, target = 5;
    
    do
    {
        for (int i = 0; i < 9; i++)
        {
            if ( target == arr[i])
            {
                printf("Found target at %i\n", i);
                state = 1;
            }
        }
    }
    while (state == 0);
}