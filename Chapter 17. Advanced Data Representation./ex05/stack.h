#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>

#define STRLEN 256

typedef struct node
{
    char item;
    struct node * previous;
} Node;

typedef Node * Stack;

/**
 * Initializes a new stack.
 *
 * @param pstack A pointer to the stack to be initialized. If the stack is not yet created,
 *               it should be set to NULL before calling this function.
 *
 * @return A pointer to the initialized stack. If the stack could not be initialized,
 *         this function will return NULL.
 *
 * @note This function does not allocate memory for the stack. It only initializes
 *       the stack pointer to NULL.
 *
 * @note If the stack is already initialized (i.e., not NULL), this function will not
 *       modify the existing stack.
 */
Stack * InitializeStack(Stack * pstack);

bool PushItem(const char * pch, Stack * pstack);

bool PopItem(char * pch, Stack * pstack);

void EmptyStack(Stack * pstack);



#endif