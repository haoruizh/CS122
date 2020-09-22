#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

//duration structure
typedef struct duration
{
    int minute;
    int second;
}Duration;

//record structure to contain informations about each song
typedef struct record
{
    char artist[20];
    char Albumtitle[30];
    char Songtitle[20];
    char Gnere[20];
    Duration Length;
    int timesplayed;
    int rating;//1-5
}Record;

//song node 
typedef struct songs
{
    Record song;
    struct song *nextSong;
    struct song *prevSong;
}Song;


Song * newsong(Record music);
int mainMenu();
int load(Song **songList, FILE *file);
int insertAtfront(Song **list, Record music);
int store(Song *list, FILE *file);
void display(Song *list);
int edit(Song *list);
void rate(Song *list);
void play(Song *list);
void Exit(Song *list, FILE *file);
void wait(int sec);
void removeSpace(char *str);