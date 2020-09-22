// This example uses a stack data structure to reverse a string.
// We'll also use this example to show how to implement some test cases

// History: 9/10 - Implemented the required structs for the application.
//                 Implemented makeNode (), push (), pop (), isEmpty (),
//                 and the application to reverse a string.

#include "Stack.h"
#include "TestStack.h"

int main(void)
{
	Stack s = {NULL};
	char str[100] = "this is a longer string than cat";

	int index = 0, success = 0;

	printf("Original string: %s\n", str);
	// we will use our stack to reverse the string;
	// push all characters in string to stack, until
	// the null character is reached.
	for (index = 0; str[index] != '\0'; ++index)
	{
		// place chars into stack
		Data newData;
		newData.c = str[index]; // our stack operations need info
		                        // wrapped in our struct Data, not
		                        // just plain char
		success = push(&s, newData);
	}

	// the characters in the stack are now accessible in the reversed
	// order of the original string --- think LIFO
	for (index = 0; !isEmpty(s); ++index)
	{
		Data newData;
		newData = pop(&s);
		str[index] = newData.c;
	}

	printf ("Reverse of string: %s\n", str); // should display the reversed string

	return 0;
}