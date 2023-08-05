#include <stdio.h>
#include <stdlib.h>

// Defining the global size variable
#define SIZE 5

// Calling the prototypes
void enqueue(int value);
int dequeue();
int isEmpty();
int isFull();
void printQueue(void);
void peekFront(void);
void peekRear(void);

// Making a structure called queue with with relevant variables inside it
struct queue
{
    int front, rear;
    int array[SIZE];
} queue;

int main(void)
{
    // "removed" is to get the dequeue value
    int removed;

    // Initializing the front to to be 0 and the rear to -1. Whenever we add one the rear will increment by one and pass the front value eventually
    queue.front = 0;
    queue.rear = -1;

    /* Try thr following

    > Try enqueue(<value>) to add a value to the queue, e.g: enqueue(38)
    > Try dequeue() to remove values from the front of the queue. Might have to assign the return value to "removed" if you fancy
    > Try isFull or isEmpty, but you'll have to implement a if condition in the main function to compare the return value. E.g:
        if (isFull == 1)
        {
            printf("Queue is full");
        }

    > Try peekFront() and peekRear() to view the front and rear value respectively
    > Finally use print printQueue() to print out the value inside the queue in order.

    */
    /*enqueue(10);
    enqueue(57);
    enqueue(34);
    enqueue(13);
    printQueue();
    peekFront();
    peekRear();
    dequeue();
    dequeue();
    dequeue();
    peekFront();*/
}

// Adding values
void enqueue(int value)
{
    // Checking if the array is full
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }
    else
    {
        // Adding 1 to the rear
        queue.rear++;

        // Assigning to the queue the value we want
        queue.array[queue.rear] = value;
        printf("%i added to location %i\n", value, queue.rear);
    }
}

// Removing Values
int dequeue()
{
    // "removed" is to keep track on the removed item
    int removed;
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        exit(1);
    }
    else
    {
        // We get the front value to the removed variable
        removed = queue.array[queue.front];
        printf("Removed %i from location %i\n", removed, queue.front);

        // We add 1 to the front to tell what was before 1 to be the new front. We are basically ignoring the old front value
        queue.front++;
    }
    return removed;
}

// Checks if the queue is full
int isFull()
{
    if (queue.rear == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Checks if the array is empty
int isEmpty()
{
    if (queue.front > queue.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prints the value of the queue starting from the front
void printQueue(void)
{
    if (!isEmpty())
    {
        for (int i = queue.front; i <= SIZE - 1; i++)
        {
            printf("%d\n", queue.array[i]);
        }
    }
    else
    {
        printf("Nothing to print!\n");
    }
}

// This is to view the front of the array
void peekFront(void)
{
    if (!isEmpty())
    {
        printf("Value at the front: %d\n", queue.array[queue.front]);
    }
    else
    {
        printf("Empty Queue!\n");
    }
}

// To view the last rear/last element of the queue
void peekRear(void)
{
    if (!isEmpty())
    {
        printf("Value at the rear: %d\n", queue.array[queue.rear]);
    }
    else
    {
        printf("Empty Queue!\n");
    }
}