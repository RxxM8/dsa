#include <stdio.h>

int stack[100];
int top = -1;

void push(int x)
{
    if (top == 99)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    return stack[top--];
}

int peek()
{
    if (top == -1)
        return -1;
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int data[100], result[100];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

   

    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty() && peek() <= data[i])
            pop();

        result[i] = peek();   

        push(data[i]);
    }

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", data[i], result[i]);

    return 0;
}