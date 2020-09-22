#include "Header.h"//header file 

//remove the space character before and after string
void removeSpace(char *str)
{
    //if str is empty
    if (str == NULL)
    {
        return;
    }
        char *copy = NULL, *last = NULL,*temp=NULL;
        copy = (char*)malloc(strlen(str) + 1);//allocate space for copy string
        temp = copy;
        strcpy(copy, str);//copy str to copy string
        last = copy + strlen(str) - 1;
        memset(str, 0, strlen(str) + 1);//set str to 0

        //if there is a space before string
        while (copy != NULL&&*copy == ' ')
        {
            copy++;
        }

        //if there is a space after string
        while (last != NULL&&*last == ' ')
        {
            last--;
        }
        strncpy(str, copy, last - copy + 1);//copy modified string to str
        //free temp
        free(temp);
}


//remove space character for a Record type variable
void removeMusicspace(Record *music)
{
    removeSpace(music->artist);
    removeSpace(music->Songtitle);
    removeSpace(music->Albumtitle);
    removeSpace(music->Gnere);
}

//from https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
//9/16/2018
//allow output to show on screen for sec time
void wait(int sec)
{
    clock_t end_wait;
    end_wait = clock() + sec * CLK_TCK;

    while (clock() < end_wait) {}
}

//insert node to the front of list
int insertAtfront(Song **list, Record music)
{
    int success = 0;
    Song *aSong = NULL;
    aSong = newsong(music);

    //if aSong is not empty
    if (aSong != NULL)
    {
        success = 1;
        aSong->nextSong = *list;
        //if list is not empty
        if (*list != NULL)
        {
            aSong->prevSong = aSong;
        }
        
        *list = aSong;
    }
    return success;
}

//print out the main menu and return the option
int mainMenu()
{
    int option = 0;
    printf("Main menu:\n");
    printf("1) Load\n"
        "2) Store\n"
        "3) Display\n"
        "4) Insert\n"
        "5) Delet\n"
        "6) Edit\n"
        "7) Sort\n"
        "8) Rate\n"
        "9) Play\n"
        "10) Shuffle\n"
        "11) Exit\n");
    scanf("%d", &option);
    getchar();
    return option;
}

//create a new song
Song * newsong(Record music) 

{
    Song *newSong = NULL;
    newSong = (Song *)malloc(sizeof(Song));//allocate space for newSong
    //if newSong successfully allocate space
    if (newSong != NULL)
    {
        newSong->song = music;
        newSong->nextSong = NULL;
        newSong->prevSong = NULL;
    }
    return newSong;
}

//write data from file to songList
int load(Song **songList, FILE *file)
{
    int success = 0;
    char data[100] = { NULL };
    Record music = { 0 };
    Duration songDuration = { 0 };

    while (fgets(data, 100, file)!=NULL)//while not end of file
    {
        //getting data
        char *firstName = NULL, *lastName = NULL, *min = NULL, *sec = NULL;
        if (data[0] == '"')//if artist name has first and last name
        {
            firstName = strtok(data, ",");
            lastName = strtok(NULL, ",");
            strcpy(music.artist, firstName);
            strcat(music.artist, ",");
            strcat(music.artist, lastName);
            strcpy(music.Albumtitle, strtok(NULL, ","));
            strcpy(music.Songtitle, strtok(NULL, ","));
            strcpy(music.Gnere, strtok(NULL, ","));
            min = strtok(NULL, ":");
            sec = strtok(NULL, ",");
            songDuration.minute = atoi(min);
            songDuration.second = atoi(sec);
            music.Length = songDuration;
            music.timesplayed = atoi(strtok(NULL, ","));
            music.rating = atoi(strtok(NULL, ","));
        }
        else//if artist name doesn't have last name
        {
            firstName = strtok(data, ",");
            strcpy(music.artist, firstName);
            strcpy(music.Albumtitle, strtok(NULL, ","));
            strcpy(music.Songtitle, strtok(NULL, ","));
            strcpy(music.Gnere, strtok(NULL, ","));
            min = strtok(NULL, ":");
            sec = strtok(NULL, ",");
            songDuration.minute = atoi(min);
            songDuration.second = atoi(sec);
            music.Length = songDuration;
            music.timesplayed = atoi(strtok(NULL, ","));
            music.rating = atoi(strtok(NULL, ","));
        }
        //remove white space for music
        removeMusicspace(&music);
        //imply the song
        success = insertAtfront(&*songList, music);
    }
    return success;
}

//print the list data to file
int store(Song *list, FILE *file)
{
    int storeCheck = 0;
    //if list is not empty
    while (list != NULL)
    {
        //print to file
        fprintf( file, "%s,%s,%s,%s,%d:%d,%d,%d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length, list->song.timesplayed, list->song.rating);
        list = list->nextSong;//move to next song
    }
    //if file is not empty(writting successfully)
    if (file != NULL)
    {
        storeCheck = 1;
    }
    return storeCheck;
}

//print song to screen
void display(Song *list)
{
    int option = 0;
    printf("Option:\n1.All record\n2.Artist\n");
    scanf("%d", &option);
    getchar();
    if (option == 1)//print all data
    {
        while (list != NULL)//if list is not empty
        {
            printf("%s,%s,%s,%s,%d:%d,%d,%d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length.minute, list->song.Length.second, list->song.timesplayed, list->song.rating);
            list = list->nextSong;
        }
    }
    if (option == 2)//print based on aritst name
    {
        char artistFirst[30] = { 0 }, artistLast[30] = { 0 };
        printf("Enter the artist first name:");
        scanf("%s", &artistFirst);
        getchar();
        printf("Enter the last(If dont have a last name, enter NONE):");
        scanf("%s", &artistLast);
        getchar();
        char *artist = NULL;
        if (strcmp(artistLast, "NONE")==0)//if artist only has first name
        {
            while (list != NULL)//when list is not empty
            {
                if (strcmp(artistFirst, list->song.artist) != 0)//if not same song
                {
                    list = list->nextSong;
                }
                else//if same song
                {
                    //print song to screen
                    printf("%s,%s,%s,%s,%d:%d,%d,%d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length.minute, list->song.Length.second, list->song.timesplayed, list->song.rating);
                    list = list->nextSong;
                }
            }
        }
        else//if artist has first and last name
        {
            artist = (char *)malloc(strlen(artistFirst)+strlen(artistLast)+5);//allocate space for string pointer artist
            memset(artist, 0, strlen(artistFirst) + strlen(artistLast) + 5);
            strcat(artist, "\"");
            strcat(artist, artistFirst);
            strcat(artist, ", ");
            strcat(artist, artistLast);
            strcat(artist, "\"");
            //while list is not empty
            while (list != NULL)
            {
                if (strcmp(artist, list->song.artist) != 0)
                {
                    list = list->nextSong;
                }
                else//print out the songs of this artist
                {
                    printf("%s, %s, %s, %s, %d:%d, %d, %d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length.minute, list->song.Length.second, list->song.timesplayed, list->song.rating);
                    list = list->nextSong;
                    
                }
            }
           free(artist); //free memory
        }
    }
}

//edit the selected song
int edit(Song *list)
{
    display(list);//print information on screen
    char Songname[31], minute[3] = { 0 }, second[3] = { 0 };
    int success = 0;
    printf("Enter the song name:");
    gets_s(Songname,30);//get songs name
    //while list is not empty and current song is not the selected song
    while (strcmp(Songname, list->song.Songtitle)!=0 && list!=NULL)
    {
        list = list->nextSong;
    }
    system("cls");
    //print out song information
    printf("%s, %s, %s, %s, %d:%d, %d, %d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length.minute, list->song.Length.second, list->song.timesplayed, list->song.rating);
    //editing
    printf("Starting editing:\n");
    printf("Artist(Follow this format: \"XXXX, YYYY\" if artist has first and last name):");
    gets_s(list->song.artist, sizeof(list->song.artist));
    printf("Song name:");
    gets_s(list->song.Songtitle, sizeof(list->song.Songtitle));
    printf("Album title:");
    gets_s(list->song.Albumtitle, sizeof(list->song.Albumtitle));
    printf("Gnere: ");
    gets_s(list->song.Gnere, sizeof(list->song.Gnere));
    printf("Minute:");
    gets_s(minute, 3);
    printf("Second:");
    gets_s(second, 3);
    list->song.Length.minute = atoi(minute);
    list->song.Length.second = atoi(second);
    printf("Time played:");
    scanf("%d", &list->song.timesplayed);
    printf("Rating:");
    scanf("%d", &list->song.rating);
    //set success to 1
    success = 1;
    return success;
}

//rating songs in list
void rate(Song *list)
{
    //list is not empty
    while (list != NULL)
    {
        printf("the song is %s, %s, %s, %s, enter your rate(1-5)", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere);
        //get rating
        scanf("%d", &list->song.rating);
        list = list->nextSong;
    }
}

//play the song
void play(Song *list)
{
    int total=0;
    //while list is not empty
    while (list != NULL)
    {
        total = (list->song.Length.minute * 60) + list->song.Length.second + 5;//get the song duration+5 secs
        printf("%s, %s, %s, %s, %d:%d, %d, %d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length, list->song.timesplayed, list->song.rating);
        wait(total);//wait till song ends
        list = list->nextSong;
    }
}

//quit the program and save list data to file
void Exit(Song *list, FILE *file)
{
    //when list is not empty
    while(list!=NULL)
    {
        fprintf(file, "%s,%s,%s,%s,%d:%d,%d,%d\n", list->song.artist, list->song.Albumtitle, list->song.Songtitle, list->song.Gnere, list->song.Length, list->song.timesplayed, list->song.rating);
        list = list->nextSong;
    }
    
    fclose(file);//close the file
}