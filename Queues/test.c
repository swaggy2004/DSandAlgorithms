#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the Queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the Queue is empty
int is_empty()
{
    return front == -1;
}

// Function to check if the Queue is full
int is_full()
{
    return rear == MAX_SIZE - 1;
}

// Function to enqueue an element into the Queue
void enqueue(int item)
{
    if (is_full())
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (is_empty())
    {
        front = 0; // If the Queue is empty, set front to 0
    }

    rear++;
    queue[rear] = item; // Add the element to the rear
}

// Function to dequeue an element from the Queue
int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate failure
    }

    int removed_item = queue[front]; // Store the front element to return later

    if (front == rear)
    {
        // If there's only one element in the Queue, set front and rear to -1
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return removed_item;
}

// Function to print the elements in the Queue
void print_queue()
{
    if (!is_empty())
    {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty.\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    print_queue(); // Output: Queue: 10 20 30 40 50

    dequeue();
    dequeue();

    print_queue(); // Output: Queue: 30 40 50

    enqueue(60);
    enqueue(70);

    print_queue(); // Output: Queue: 30 40 50 60 70

    enqueue(80); // Output: Queue is full. Cannot enqueue.

    return 0;
}
