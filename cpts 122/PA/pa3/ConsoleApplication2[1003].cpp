// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

struct Song {
    Song* next;
    Song* prev;
    char authour[100];
};

void swap(Song* a, Song *b)
{
    Song* tn = a->next;
    Song* tp = a->prev;

    //4
    a->next = b->next;
    if ( a->next != NULL)
        a->next->prev = a;
    //3 if b is next of a
    if (b->prev == a)
    {
        a->prev = b;
    }
    else
        a->prev = b->prev;
    if (a->prev != NULL)
        a->prev->next = a;
    //2 if b is next of a
    if (tn == b)
    {
        b->next = a;
    }
    else
        b->next = tn;
    if (b->next != NULL)
        b->next->prev = b;
    //1
    b->prev = tp;
    if (b->prev != NULL)
        b->prev->next = b;
}

void sortSong(Song* list, int count)
{
    int i;
    int maxIteration; //the maximum iteration to process
    int nLoop = 0; // how many songs are handled
    //empty or only one, no need to sort
    if (list == NULL || list->next == NULL)
        return;
    Song *first = list;
    //loop
    for (i = 0; i < count - 1; i++)
    {
        maxIteration = count - i - 1;
        nLoop = 0;
        Song * temp = first;
        while (nLoop < maxIteration)
        {
            Song* tempNext = temp->next;
            //compare
            if (strcmp(temp->authour, tempNext->authour) > 0)
            {
                //swap
                swap(temp, tempNext);   
                //we must make sure first is always updated
                if (tempNext->prev == NULL)
                    first = tempNext;
            }
            else
                temp = tempNext;
            ++nLoop;
        }
    }

}
int main()
{
    Song a,b,c,d,e,f;
    a.next = &b;
    a.prev = NULL;
    strcpy(a.authour, "Bill");
    b.next = &c;
    b.prev = &a;
    strcpy(b.authour, "Ana");
    c.next = &d;
    c.prev = &b;
    strcpy(c.authour, "Zack");
    d.next = &e;
    d.prev = &c;
    strcpy(d.authour, "Haorui");
    e.next = &f;
    e.prev = &d;
    strcpy(e.authour, "Haokun");
    f.next = NULL;
    f.prev = &e;
    strcpy(f.authour, "12345");
    sortSong(&a, 6);
    //test swap
    //now list is a->b->c->d->e->f
    swap(&a, &b);
    //now list is b->a->c->d->e->f
    char* nextauthor = a.next->authour;
    char *prev = a.prev->authour;  
     //now list is b->a->f->d->e->c  
    swap(&c, &f);
     //now list is d->a->f->b->e->c  
    swap(&b, &d);
    //
    sortSong(&d, 6);
    return 0;
}

