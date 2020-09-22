#include "Header.h"

//main function
int main()
{
    
    

    FILE *readingfile = NULL;
    
    int option = 0;
    Song *list = NULL, *remebertodelete = NULL;
    int check=0, count;
    int *r = NULL;
    char songname[50] = { NULL };


    readingfile = fopen("musicPlayList.csv", "r"); //open file for read
    while (option != 11)
    {
        option = mainMenu();
        switch (option)
        {
            case 1: 
                check = 0;
                check = load(&list, readingfile, &count);
                if(check == 1)
                {
                    printf("Load - Success\n");
                }
                fclose(readingfile);//close reading file
                break;
            case 2: 
                readingfile = fopen("musicPlayList.csv", "w");//open file for write
                check= store(list, readingfile);
                if (check == 1)
                {
                    fclose(readingfile);//close file
                    printf("Store - Success\n");
                }
                break;
            case 3:
                display(list);
                break;
            case 4:
                check = 0;
                check=insert(&list);
                if (check == 1)
                {
                    printf("Insert-Success\n");
                }
                else
                {
                    printf("Insert-Failed\n");
                }
                break;
            case 5:
                //get song name
                printf("Enter the song name:");
                gets_s(songname, 50);
                remebertodelete = deletion(&list, songname);
                break;
            case 6: 
                edit(list);
                break;
            case 7:
                sort(list);
                break;
            case 8: 
                rate(list);
                break;
            case 9: 
                play(list);
                break;
            case 10:
                r = (int*)malloc(count * sizeof(int));
                memset(r, 0, count * sizeof(int));
                generateRandom(r, count);
                playShuffle(list, r, count);
                free(r);
                break;
            case 11: 
                readingfile = fopen("musicPlayList.csv", "w");//open file for wirte
                Exit(list, readingfile);//quit
            case 12:
                //all test functions
                test();
        }

        system("Pause");
        system("cls");
    }
    return 0;
}
