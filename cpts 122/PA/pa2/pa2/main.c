#include "Header.h"

//main function
int main()
{
    FILE *readingfile = NULL;
    readingfile = fopen("musicPlayList.csv", "r"); //open file for read
    int option = 0;
    Song *list = NULL;
    int check=0;
    while (option != 11)
    {
        option = mainMenu();
        switch (option)
        {
            case 1: 
                check = 0;
                check = load(&list, readingfile);
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
                printf("Not yet\n");
                break;
            case 5:
                printf("Not yet\n");
                break;
            case 6: 
                edit(list);
                break;
            case 7:
                printf("Not yet\n");
                break;
            case 8: 
                rate(list);
                break;
            case 9: 
                play(list);
                break;
            case 10:
                printf("Not yet\n");
                break;
            case 11: 
                readingfile = fopen("musicPlayList.csv", "w");//open file for wirte
                Exit(list, readingfile);//quit
        }

        system("Pause");
        system("cls");
    }
    return 0;
}
