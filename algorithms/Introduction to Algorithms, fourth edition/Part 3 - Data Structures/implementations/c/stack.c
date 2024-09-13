// ! Stack

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *array;
};


int main() {
    struct Stack stack;
    stack.size = 10;
    stack.top = -1;
    stack.array = (int *)malloc(stack.size * sizeof(int));

    printf("Is stack empty? %d\n", IsEmpty(&stack));
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    printf("Is stack empty? %d\n", IsEmpty(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Pop: %d\n", Pop(&stack));
    printf("Is stack empty? %d\n", IsEmpty(&stack));
}

int IsEmpty(struct Stack *stack) {
    if (stack->top <= 0) {
        return 1;
    } else {
        return 0;
    }
}

int Push(struct Stack *stack, int number) {
    if (stack->top == stack->size) {
        return -1;
    }

    stack->top += 1;
    stack->array[stack->top] = number;
}

int Pop(struct Stack *stack) {
    if (IsEmpty(stack)) {
        return -1;
    }

    stack->top -= 1;
    return stack->array[stack->top + 1];
}