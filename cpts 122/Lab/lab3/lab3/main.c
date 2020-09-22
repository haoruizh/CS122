#include "Header.h"

int main()
{
    //tower of Hanoi
    Stack Dish1 = {0}, Dish2 = {0}, Dish3 = {0};
    int plates = 0;
    printf("How many plates you want to play?(At least 2): ");
    scanf("%d", &plates);
    int count;

    for (count = 1;count <= plates; --plates)
    {
        push(&Dish1, plates);
    }

    return 0;
}