// This example serves as a C refresher on 
// arrays, strings, pointers, and structs.

// History: 8/24 - Defined a struct data, starting
//                 separating the line from a file using
//                 strok ().
//          8/22 - Created the "data.csv" file. Format of
//                 the file is entry number,"lastname, firstname".
//                 Opened the file programmatically.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi ()

typedef struct data
{
	int recordNumber;
	char name[100];
	//char *pName;
}Data;

int main(void)
{
	FILE *infile = NULL;

	infile = fopen("data.csv", "r");

	char line[100] = "";
	fgets(line, 100, infile);

	Data e1;
	printf("size: %d\n", sizeof(Data));

	char *pRN = strtok(line, ",");
	// get the first token on the line; convert it to an
	// integer
	e1.recordNumber = atoi(pRN);
	/*while ()
	{

	}*/
	// The double quotes indicate a special
	// situation. How do we want to get the
	// second token?
	if (line[strlen(pRN) + 1] == '\"')
	{
//char *pName = strtok(NULL, );
	}

	return 0;
}