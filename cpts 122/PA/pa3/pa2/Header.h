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
    char artist[50];
    char Albumtitle[50];
    char Songtitle[50];
    char Gnere[20];
    Duration Length;
    int timesplayed;
    int rating;//1-5
}Record;

//song node 
typedef struct songs
{
    Record song;
    struct songs *nextSong;
    struct songs *prevSong;
}Song;


typedef struct songRef
{
    Song* pSong;
    struct songRef* pre;
    struct songRef* next;
}SongRef;


Song * newsong(Record music);
int mainMenu();
int load(Song **songList, FILE *file, int *count);
int insertAtfront(Song **list, Record music);
int store(Song *list, FILE *file);
int insert(Song **list);
Song * deletion(Song **list, char* songName);
void display(Song *list);
int edit(Song *list);
void rate(Song *list);
void play(Song *list);
void Exit(Song *list, FILE *file);
void wait(int sec);
void removeSpace(char *str);
void sort(Song *list);
void sort_name(Song *list);
void sort_album(Song *list);
void sort_rating(Song *list);
void sort_timesplayed(Song *list);
void swap(Song *i, Song *j);
void playShuffle(Song* plist, int *r, int count);
void test();
