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
    success = checkvalid(aSong);
    //if aSong is not empty
    if(success)
    {
        aSong->nextSong = *list;
        //if list is not empty
        if (*list != NULL)
        {
            aSong->nextSong->prevSong = aSong;
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
        "11) Exit\n"
        "12) Test\n");
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
int load(Song **songList, FILE *file, int *count)
{
    *count = 0;
    int success=0;
    char data[100] = { NULL };
    Record music = { 0 };
    Duration songDuration = { 0 };

    while (fgets(data, 100, file)!=NULL)//while not end of file
    {
        //getting data
        char *firstName = NULL, *lastName = NULL, *min = NULL, *sec = NULL;
        if (data[0] == '"')//if artist name has first and last name
        {
            firstName = strtok(data, "\",");
            lastName = strtok(NULL, "\",");
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
        ++(*count);
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
    if (list == NULL)
    {
        return 0;
    }
    Song *pCur = NULL;
    pCur = (Song*)malloc(sizeof(Song*));
    pCur = list;
    display(pCur);//print information on screen
    char Songname[31], minute[3] = { 0 }, second[3] = { 0 };
    int success = 0;
    printf("Enter the song name:");
    gets_s(Songname,30);//get songs name
    //while list is not empty and current song is not the selected song
    while (strcmp(Songname, pCur->song.Songtitle)!=0)
    {
        pCur = pCur->nextSong;
    }
    system("cls");
    //print out song information
    printf("%s, %s, %s, %s, %d:%d, %d, %d\n", pCur->song.artist, pCur->song.Albumtitle, pCur->song.Songtitle, pCur->song.Gnere, pCur->song.Length.minute, pCur->song.Length.second, pCur->song.timesplayed, pCur->song.rating);
    //editing
    printf("Starting editing:\n");
    printf("Artist(Follow this format: \"XXXX, YYYY\" if artist has first and last name):");
    gets_s(pCur->song.artist, sizeof(pCur->song.artist));
    printf("Song name:");
    gets_s(pCur->song.Songtitle, sizeof(pCur->song.Songtitle));
    printf("Album title:");
    gets_s(pCur->song.Albumtitle, sizeof(pCur->song.Albumtitle));
    printf("Gnere: ");
    gets_s(pCur->song.Gnere, sizeof(pCur->song.Gnere));
    printf("Minute:");
    gets_s(minute, 3);
    printf("Second:");
    gets_s(second, 3);
    pCur->song.Length.minute = atoi(minute);
    pCur->song.Length.second = atoi(second);
    printf("Time played:");
    scanf("%d", &pCur->song.timesplayed);
    getchar();
    printf("Rating:");
    scanf("%d", &list->song.rating);
    getchar();
    //set success to 1 and free pCur
    free(pCur);
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
        getchar();
    }
}

//play a song
void playSingle(Song *aSong)
{
    printf("%s, %s, %s, %s, %d:%d, %d, %d\n", aSong->song.artist, aSong->song.Albumtitle, aSong->song.Songtitle, aSong->song.Gnere, aSong->song.Length.minute, aSong->song.Length.second, aSong->song.timesplayed, aSong->song.rating);
}
//play songs from list
void play(Song *list)
{
    int total=0;
    //while list is not empty
    while (list != NULL)
    {
        total = (list->song.Length.minute * 60) + list->song.Length.second + 5;//get the song duration+5 secs
        playSingle(list); //play song
        wait(1.5);//wait till song ends
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

//insert a new song to the front at the list
int insert(Song **list)
{
    //insert data to a new song
    Record newSong;
    char minute[3] = { 0 }, second[3] = { 0 };
    printf("Starting editing:\n");
    printf("Artist(Follow this format: \"XXXX, YYYY\" if artist has first and last name):");
    gets_s(newSong.artist, sizeof(newSong.artist));
    printf("Song name:");
    gets_s(newSong.Songtitle, sizeof(newSong.Songtitle));
    printf("Album title:");
    gets_s(newSong.Albumtitle, sizeof(newSong.Albumtitle));
    printf("Gnere: ");
    gets_s(newSong.Gnere, sizeof(newSong.Gnere));
    printf("Minute:");
    gets_s(minute, 3);
    printf("Second:");
    gets_s(second, 3);
    newSong.Length.minute = atoi(minute);
    newSong.Length.second = atoi(second);
    printf("Time played:");
    scanf("%d", &newSong.timesplayed);
    getchar();
    printf("Rating:");
    scanf("%d", &newSong.rating);
    getchar();

    //insert new song at the front of list
    int success = 0;
    success = insertAtfront(&*list, newSong);
    return success;
}

//delete a song based on the song name
Song * deletion(Song **list, char* songName)
{
    Song * deletedsong, *head = *list;
    int bFound = 0;
    //if list is empty
    if ((*list) == NULL)
    {
        return NULL;
    }

    //search for the song
    while ((*list) != NULL)
    {
        if (strcmp(songName, (*list)->song.Songtitle) == 0)
        {
            bFound = 1;
            deletedsong = (*list);
            break;
        }
        (*list) = (*list)->nextSong;
    }
    //deletion
    if (bFound)
    {
        //delete the only or firstelement
        if ((*list)->prevSong == NULL)
        {
            if ((*list)->nextSong == NULL)
            {
                *list = NULL;
                head = NULL;
            }
            else
            {
                (*list)->nextSong->prevSong = NULL;
                (*list) = (*list)->nextSong;
                head = *list;
            }
        }
        else
        {
            //last element
            if ((*list)->nextSong == NULL)
            {
                (*list)->prevSong->nextSong = NULL;
                (*list) = (*list)->prevSong;
            }
            //normal case not front, not end ,not one
            else
            {
                (*list)->prevSong->nextSong = (*list)->nextSong;
                (*list)->nextSong->prevSong = (*list)->prevSong;
            }
        }    
    }
    *list = head;
    return deletedsong;
}


//sorting
void sort(Song *list)
{
    int option = 0;
    printf("How you want to sort?\n");
    printf("1). Artist (A-Z)\n2). Album title (A-Z)\n3). Rating (1-5)\n4). Time played (Largest -Smallest)\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        sort_name(list);
        break;
    case 2:
        sort_album(list);
        break;
    case 3:
        sort_rating(list);
        break;
    case 4:
        sort_timesplayed(list);
        break;
    }
}

//sort by name
void sort_name(Song *list)
{
    int count = sizeof(*list) / sizeof(list);//how many songs
    int i = 0, maxIteration=0, handledNumber = 0;
    Song *pHead = NULL;
    //if list is empty or only one element
    if (list->nextSong == NULL || list == NULL)
    {
        return;
    }
    pHead = list;

    //A-Z
    for (i;i < count;i++)
    {
        maxIteration = count - i - 1;
        handledNumber = 0;
        Song *pTemp = pHead;
        Song *tempNext = pTemp->nextSong;
        if (tempNext != NULL)
        {
            while (handledNumber < maxIteration && tempNext != NULL)
            {
                tempNext = pTemp->nextSong;
                //compare
                if (strcmp(pTemp->song.artist, tempNext->song.artist) > 0 && tempNext != NULL)
                {
                    //swap
                    swap(pTemp, tempNext);

                    //update pHead 
                    if (tempNext->prevSong == NULL)
                    {
                        pHead = tempNext;
                    }
                }
                else
                {
                    //next song
                    pTemp = tempNext;
                    ++handledNumber;
                }
            }
        }
    }
    display(pHead);
} 


//sort by album
void sort_album(Song *list)
{
    Song* pCur = NULL;
    pCur = list;

    while (pCur != NULL)
    {
        //A-Z
        while (strcmp(pCur->song.Albumtitle, pCur->nextSong->song.Albumtitle)< 1 && (pCur)->nextSong != NULL)
        {
            pCur = pCur->nextSong;
            pCur->nextSong = pCur;
            
        }
    }
}


//sort by rating
void sort_rating(Song *list)
{
    Song* pCur = NULL;
    pCur = list;

    while (pCur != NULL)
    {
        //1-5
        while (pCur->song.rating > pCur->nextSong->song.rating && (pCur)->nextSong !=NULL)
        {
            pCur->nextSong = pCur;
            pCur = pCur->nextSong;
        }
    }
}


//sort by timeplayed
void sort_timesplayed(Song *list)
{
    Song* pCur = NULL;
    pCur = list;

    while (pCur != NULL)
    {
        //largest - smallest
        while (pCur->song.timesplayed < pCur->nextSong->song.timesplayed && (pCur)->nextSong != NULL)
        {
            pCur->nextSong = pCur;
            pCur = pCur->nextSong;
        }
    }
}

void swap(Song *i, Song *j)
{
    Song *pN = i->nextSong;
    Song *pP = i->prevSong;

    i->nextSong = j->nextSong;
    if (i->nextSong != NULL)
    {
        i->nextSong->prevSong = i;
    }

    if (j->prevSong == i)
    {
        i->prevSong = j;
    }
    else
    {
        i->prevSong = j->prevSong;
    }

    if (pN == j)
    {
        j->nextSong = i;
    }
    else
    {
        j->nextSong = pN;
    }
    if (j->nextSong != NULL)
    {
        j->nextSong->prevSong = j;
    }
    j->prevSong = pP;
    if (j->prevSong != NULL)
    {
        j->prevSong->nextSong = j;
    }
}



int checkUnique(int* a, int count, int c)
{
    for (int i = 0; i < count; ++i)
    {
        if (a[i] == c)
        {
            return 0;
        }
    }
    return 1;
}

void generateRandom(int* r, int count)
{
    srand((time)NULL);
    int i = 0, tr;
    for (i = 0;i < count;i++)
    {
        tr = rand() % count + 1;
        while (!checkUnique(r, i, tr))
        {
            tr = rand() % count + 1;
        }
        r[i] = tr;
    }

}


void  createSongRef(SongRef ** pSongref, int count)
{
    *pSongref = (SongRef*)malloc(count * sizeof(SongRef));
    for (int i = 0; i < count;++i)
    {
        if (i == 0)
            (*pSongref+i)->pre = NULL;
        else
            (*pSongref+i)->pre = *pSongref + i - 1;
        if (i == count - 1)
            (*pSongref+i)->next = NULL;
        else
        {
            (*pSongref + i)->next = *pSongref + i + 1;
        }
        (*pSongref+i)->pSong = NULL;
    }
}

void shuffle(Song *plist, int* r, int count, SongRef* pSongRef)
{

    int i, tr;

  
    for (i=0;i < count;i++)
    {
        Song* temp = plist;
        int j = 0;
        while (j < r[i] - 1)
        {
            temp = temp->nextSong;
            ++j;
        }
        pSongRef[i].pSong = temp;         
    }
}

void playShuffle(Song* plist, int *r, int count)
{
    int i = 0;  
    SongRef* pRef = NULL, *head;
    createSongRef(&pRef, count);
    shuffle(plist, r, count, pRef);
    head = pRef;
    while (pRef != NULL)
    {
        playSingle(pRef->pSong);
        pRef = pRef->next;
    }
    //delete
    free(head);
}

//test insert
void testInsert()
{
    //For the insert test function you must provide a test case with the following test point : artist name = “Perry, Katy”, album title = “Witness”, song title = “Chained to the Rhythm”, genre = “pop”, song length = “4 : 36”, times played = -1, rating = 6. List state = initially empty.You must think about what is your expected result ? Should you able to insert a song with - 1 times played ? Should you able to add a song with rating 6 ? Is the head pointer of the list updated ?
    Song a, *list1=NULL, b, *list2=NULL;
    //test invalid
    a.nextSong = NULL;
    a.prevSong = NULL;
    strcpy(a.song.artist, "\"Perry, Katy\"");
    strcpy(a.song.Albumtitle, "Witness");
    strcpy(a.song.Gnere, "pop");
    strcpy(a.song.Songtitle, "Chained to the Rhythm");
    a.song.Length.minute = 4;
    a.song.Length.second = 36;
    a.song.rating = 5;
    a.song.timesplayed = -1;

    int check = insertAtfront(&list1, a.song);

    if (check == 0 && list1 == NULL)
    {
        printf("Invalid Insert test OK\n");
    }
    else
    {
        printf("Invalid Insert test Fail\n");
    }


    //test valid
    b.nextSong = NULL;
    b.prevSong = NULL;
    strcpy(b.song.artist, "\"Perry, Katy\"");
    strcpy(b.song.Albumtitle, "Witness");
    strcpy(b.song.Gnere, "pop");
    strcpy(b.song.Songtitle, "Chained to the Rhythm");
    b.song.Length.minute = 4;
    b.song.Length.second = 36;
    b.song.rating = 5;
    b.song.timesplayed = 1;
    check = insertAtfront(&list2, b.song);

    if (check == 1 && list2->song.Length.second == 36)
    {
        printf("Valid insert OK\n");
    }
    else
    {
        printf("Valid insert Failed\n");
    }
}

int checkvalid(Song *tempsong)
{
    int check = 1;

    //if tempsong is empty
    if (tempsong == NULL)
    {
        check = 0;
        return check;
    }


    //if time of played is negative
    if (tempsong->song.timesplayed < 0)
    {
        check = 0;
    } 

    //if rating is > 5 or < 1
    if(tempsong->song.rating > 5 || tempsong->song.rating < 1)
    {
        check = 0;
    }

    //if minute >= 60 or <0
    if (tempsong->song.Length.minute > 59 || tempsong->song.Length.minute < 0)
    {
        check = 0;
    }

    //if second >= 60 or <0
    if (tempsong->song.Length.second > 59 || tempsong->song.Length.second < 0)
    {
        check = 0;
    }

    //if artist is empty
    if (strlen(tempsong->song.artist) == 0)
    {
        check = 0;
    }

    //if genre is empty
    if (strlen(tempsong->song.Gnere) == 0)
    {
        check = 0;
    }

    //if albumtitle is empty
    if (strlen(tempsong->song.Albumtitle) == 0)
    {
        check = 0;
    }

    //if songtitle is empty
    if (strlen(tempsong->song.Songtitle) == 0)
    {
        check = 0;
    }
    return check;
}

//test delete
void testDeltetion()
{
    //“Chained to the Rhythm”.List state = artist name = “Perry, Katy”, album title = “Witness”, song title = “Chained to the Rhythm”, genre = “pop”, song length = “4:36”, times played = 3, rating = 5
    Song a, *list1, *list2, *list3, b, c;
    Song * check;

    //list 1
    a.nextSong = NULL;
    a.prevSong = NULL;
    strcpy(a.song.artist, "\"Perry, Katy\"");
    strcpy(a.song.Albumtitle, "Witness");
    strcpy(a.song.Gnere, "pop");
    strcpy(a.song.Songtitle, "Chained to the Rhythm");
    a.song.Length.minute = 4;
    a.song.Length.second = 36;
    a.song.rating = 5;
    a.song.timesplayed = 3;

    //list 2
    b.nextSong = NULL;
    b.prevSong = NULL;
    strcpy(b.song.artist, "\"Perry, Katy222\"");
    strcpy(b.song.Albumtitle, "Witness222");
    strcpy(b.song.Gnere, "pop22");
    strcpy(b.song.Songtitle, "Chained to the Rhythm22");
    b.song.Length.minute = 4;
    b.song.Length.second = 36;
    b.song.rating = 5;
    b.song.timesplayed = 3;


    //list 3
    c.nextSong = NULL;
    c.prevSong = NULL;
    strcpy(c.song.artist, "\"Perry, Katy333\"");
    strcpy(c.song.Albumtitle, "Witness333");
    strcpy(c.song.Gnere, "pop33");
    strcpy(c.song.Songtitle, "Chained to the Rhythm33");
    c.song.Length.minute = 4;
    c.song.Length.second = 36;
    c.song.rating = 5;
    c.song.timesplayed = 3;

    //delete one
    list1 = &a;
    check = deletion(&list1, "Chained to the Rhythm");
    //check if deletion success
    if (strcmp(check->song.Songtitle, "Chained to the Rhythm") == 0  && list1==NULL)
    {
        printf("Delete Test case 1 OK\n");
    }
    else
        printf("Delete Test case 1 Fail\n");

    //delete one from two 
    list2 = &a;
    a.prevSong = NULL;
    a.nextSong = &b;
    b.prevSong = &a;
    b.nextSong = NULL;
    check = deletion(&list2, "Chained to the Rhythm");
    //check if deletion success
    if (strcmp(check->song.Songtitle, "Chained to the Rhythm") == 0 && list2 == &b)
    {
        printf("Delete Test case 2 OK\n");
    }
    else
        printf("Delete Test case 2 Fail\n");

    //delete mid one from three
    list3 = &a;
    a.nextSong = &b;
    b.nextSong = &c;
    c.nextSong = NULL;
    a.prevSong = NULL;
    b.prevSong = &a;
    c.prevSong = &b;
    check = deletion(&list3, "Chained to the Rhythm22");
    //check if deletion success
    if (strcmp(check->song.Songtitle, "Chained to the Rhythm22") == 0 && list3 == &a && list3->nextSong == &c)
    {
        printf("Delete Test case 3 OK\n");
    }
    else
        printf("Delete Test case 3 Fail\n");
}

//test shuffle if is 3,1,2
void testShuffle()
{
    //create test list
    Song a, b, c;
    SongRef * songref;
    createSongRef(&songref, 3);
    a.nextSong = &b;
    b.nextSong = &c;
    c.nextSong = NULL;
    a.prevSong = NULL;
    b.prevSong = &a;
    c.prevSong = &b;
    strcpy(a.song.artist, "A");
    strcpy(b.song.artist, "B");
    strcpy(c.song.artist, "C");
    //set order and shuffle
    int test[3] = { 3,1,2 };
    shuffle(&a, test, 3, songref);
    //check shuffle
    if (strcmp(c.song.artist, songref[0].pSong->song.artist) == 0 && strcmp(a.song.artist, songref[1].pSong->song.artist) == 0 && strcmp(b.song.artist, songref[2].pSong->song.artist)==0)
    {
        printf("Shuffle OK\n");
    }
    else
    {
        printf("Shuffle failed\n");
    }
    free(songref);
}

int testSwap()
{
    Song *list1 = NULL, *list2 = NULL, *list3 = NULL;
    Song a, b, c;
    strcpy(a.song.Songtitle, "A");
    strcpy(b.song.Songtitle, "B");
    strcpy(c.song.Songtitle, "C");
    a.nextSong = NULL;
    a.prevSong = NULL;
    //one single element
    list1 = &a;
    swap(&a, &a);
    if (strcmp(list1->song.Songtitle, "A") == 0)
    {
        printf("Swap one single element OK\n");
    }
    else
    {
        printf("Swap one single element faield\n");
    }

    //two elements
    list2 = &a;
    a.nextSong = &b;
    b.prevSong = &a;
    b.nextSong = NULL;
    swap(&a, &b);
 
    if (b.nextSong == &a)
    {
        printf("Swap two element OK\n");
    }
    else
    {
        printf("Swap two element Fail\n");
    }

    //3 elements
    list3 = &a;
    a.nextSong = &b;
    a.prevSong = NULL;
    b.prevSong = &a;
    b.nextSong = &c;
    c.prevSong = &b;
    c.nextSong = NULL;
    swap(&a, &b);
    if (b.nextSong==&a && a.nextSong == &c)
    {
        printf("Swap first 2 elements in 3 elements list OK\n");
    }
    else
    {
        printf("Swap first 2 elements in 3 elements list fail\n");
    }
}

//test functions
void test()
{
    testInsert();
    testDeltetion();
    testShuffle();
    testSwap();
}
