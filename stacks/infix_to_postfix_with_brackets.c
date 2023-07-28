#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

struct Stack
{
  int top;
  int maxSize;
  int *array;
};

struct Stack *create (int max)
{
  struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));
  stack->maxSize = max;
  stack->top = -1;
  stack->array = (int *) malloc (stack->maxSize * sizeof (int));
  return stack;
}

int isFull (struct Stack *stack)
{
  if (stack->top == stack->maxSize - 1)
    {
      printf ("Will not be able to push maxSize reached\n");
    }
  return stack->top == stack->maxSize - 1;
}

int isEmpty (struct Stack *stack)
{
  return stack->top == -1;
}

void push (struct Stack *stack, int item)
{
  if (isFull (stack))
    return;
  stack->array[++stack->top] = item;
}

int pop (struct Stack *stack)
{
  if (isEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top--];
}

int peek (struct Stack *stack)
{
  if (isEmpty (stack))
    return INT_MIN;
  return stack->array[stack->top];
}

int checkIfOperand (char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;

    case '^':
      return 3;
    }
  return -1;
}

// The driver function for infix to postfix conversion 
int covertInfixToPostfix (char *expression)
{
  int i, j;

  // Stack size should be equal to expression size for safety  
  struct Stack *stack = create (strlen (expression));
  if (!stack)			// just checking is stack was created or not  
    return -1;
  char postfix[strlen(expression)];

  for (i = 0, j = -1; expression[i]; ++i)
    {
      // Here we are checking is the character we scanned is operand or not
      // and this adding to to output. 
      if (checkIfOperand (expression[i]))
	postfix[++j] = expression[i];

      else if (expression[i] == '(')
	push (stack, expression[i]);

      else if (expression[i] == ')')
	{
	  while (!isEmpty (stack) && peek (stack) != '(')
	    postfix[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != '(')
	    return -1;		// invalid expression              
	  else
	    pop (stack);
	}
      else			// if an opertor
	{
	  while (!isEmpty (stack)
		 && precedence (expression[i]) <= precedence (peek (stack)))
	    postfix[++j] = pop (stack);
	  push (stack, expression[i]);
	}

    }

  // Once all inital expression characters are traversed
  // adding all left elements from stack to exp
  while (!isEmpty (stack))
    postfix[++j] = pop (stack);

  postfix[++j] = '\0';
  printf ("%s", postfix);
}

int main ()
{
  char expression[20];
  printf("Enter the expression\n");
  scanf("%s",expression);
  covertInfixToPostfix (expression);
  return 0;
}