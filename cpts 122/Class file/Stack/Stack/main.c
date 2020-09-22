#include "Stack.h"
#include "TestStack.h"

int main(void)
{
    Stack s = { NULL };
    char str[100] = "cat";

    int index = 0, success=0;

    for (index = 0; str[index] != '\0'; ++index)
    {
        //place chars into stack
        Data newData;
        newData.c = str[index];
        success = push(&s, newData);
    }

    for (index = 0; listEmpty(s); ++index)
    {
        Data newData;
        newData = pop(&s);
        str[index] = newData.c;
    }

    puts(str);
	return 0;
}