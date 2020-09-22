#include <stdio.h>
//Task a

//int recursive(char *str, int strlen, int count)
//{
//	char temp = NULL;
//	if (count >= strlen / 2)
//	{
//		return 0;
//	}
//	else
//	{
//		temp = str[strlen - 1 - count];
//		strcpy(str[strlen - 1 - count],str[count]);
//		str[count] = temp;
//		recursive(str, strlen, ++count);
//	}
//}



//task d

//typedef struct
//{
//	char letter;
//	int count;
//	int lineNum[];
//}Letter;
//
//void letterCount(Letter *list, FILE *inputfile)
//{
//	int i = 0;
//	int currentline;
//	char line[100];
//	while (!feof(inputfile))
//	{
//		fgets(line, 100, inputfile);
//		while (line[i] != '\0')
//		{
//			list[(int)(line[i]) - 'a'].letter = line[i];
//			list[(int)(line[i]) -'a'].count++;
//			list[(int)(line[i]) - 'a'].lineNum[list[(int)(line[i])-'a'].count -1 ] = currentline;
//			i++;
//		}
//		currentline++;
//	}
//}

int main()
{
	/*recursive("aaabbb", 6, 0);*/
	return 0;
}