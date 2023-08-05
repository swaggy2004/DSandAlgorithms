#include <stdio.h>
#include <stdlib.h>

// Defining a global variable SIZE
#define SIZE 4

void push(int value);
int pop(void);
int isFull(void);
int isEmpty(void);
int peek(void);
void printStack();

// Making a structure called stack which has the related variable to the stack and naming it stack.
struct stack
{
    int top;
    int array[SIZE];
} stack;

int main(void)
{
    // Initialising the top to be -1 as the base value, telling the stack is emtpy
    stack.top = -1;
    int removed, item;
    /* Try something from these options

    > Try push(<value>) to put something in the array, e.g: push(27)
    > Try pop() to remove the value at the top. You can assign it to the variable "removed" and print it
    > Call isFull or isEmpty to see if the stack is full or empty
    > Try peek() to view the value at the current top position of the stack by saving the value to variable "item" and printing it
    > Try printStack() to print out what is in the stack

    */
    printStack();
    return 0;
}

void push(int value)
{
    // Check if the stack isn't full before pushing. Refer to isFull to see understand this better 
    if (isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        // Incrementing the top variable to by 1
        stack.top++;

        // Using top to access the location of the array and assigning the value
        stack.array[stack.top] = value;
    }
}

// This is just and illusion to trick the user to believe the value has been deleted
int pop(void)
{
    // Checking if the stack is already empty. Refer to isEmpty to see how this work
    if (isEmpty())
    {
        // Calling Stack Underflow meaning trying to delete something that isn't in the array
        printf("Stack Underflow\n");

        // Exiting the code with an error
        exit(1);
    }
    else
    {
        // We put the last value we put into value
        int value = stack.array[stack.top];

        // Decrement top by one to give the illusion that the top element has been deleted
        stack.top--;

        // Returning the value we supposedly deleted
        return value;
    }
}

// To check if the stack is full
int isFull(void)
{
    if (stack.top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// To check is the stack is empty
int isEmpty(void)
{
    if (stack.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// To view the value at the top
int peek(void)
{
    return stack.array[stack.top];
}

// Prints the values inside the stack if there are any
void printStack()
{
    if (isEmpty())
    {
        printf("Sorry the stack is empty, there is nothing to print!\n");
    }
    else
    {
        for (int i = stack.top; i > -1; i--)
        {
            printf("%d\n", stack.array[i]);
        }
    }
}