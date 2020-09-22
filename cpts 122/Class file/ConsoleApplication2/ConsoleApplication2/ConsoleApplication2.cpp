// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>

typedef enum sleep

{

	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;

typedef struct fitbit

{

	char patient[10];

	char minute[9];

	double calories;

	double distance;

	unsigned int floors;

	unsigned int heartRate;

	unsigned int steps;

	Sleep sleepLevel;

} FitbitData;


void processLine(char*line, char delimit, FitbitData* pData)
{
	char * tmp=NULL;
	int pos = 0;
	while (line)
	{
		char * subp = strchr(line, delimit);
		tmp = NULL;
		if (subp != NULL)
		{
			int nsize = subp-line;
			if (nsize == 0)
			{
				printf(":*\n");
			}
			else
			{
				tmp = (char*)malloc(nsize + 1);
				memset(tmp, 0, nsize + 1);
				strncpy(tmp, line, nsize);
				printf(" tmp = %s\n", tmp);
			}
			line = subp + 1;
		}
		else
		{
			int nsize = strlen(line);
			if (nsize == 0)
			{
				printf(":*\n");
			}
			else
			{
				tmp = (char*)malloc(nsize + 1);
				memset(tmp, 0, nsize + 1);
				strncpy(tmp, line, nsize);
				printf(" tmp = %s\n", tmp);
			}
		}

		if ( pos == 0 )
		{
			//patien id
			memset(pData->patient, 0, sizeof(pData->patient));
			strcpy(pData->patient, tmp);
		}
		else if (pos == 1)
		{
			//minute
			memset(pData->minute, 0, sizeof(pData->minute));
			strcpy(pData->minute, tmp);
		}
		else if (pos == 2)
		{
			if (tmp != NULL)
				pData->calories = atof(tmp);
			else
				pData->calories = -1;
		}
		
		else if (pos == 3)
		{
			if (tmp != NULL)
				pData->distance = atof(tmp);
			else
				pData->distance = -1;
		}
		else if (pos == 4)
		{
			if (tmp != NULL)
				pData->floors = atoi(tmp);
			else
				pData->floors = -1;
		}
		else if (pos == 5)
		{
			if (tmp != NULL)
				pData->heartRate = atoi(tmp);
			else
				pData->heartRate = -1;
		}
		else if (pos == 6)
		{
			if (tmp != NULL)
				pData->steps = atoi(tmp);
			else
				pData->steps = -1;
		}
		else 
		{
			if (tmp == NULL)
			{
				pData->sleepLevel = NONE;
			}
			else
			{
				pData->sleepLevel = (Sleep) atoi(tmp);
			}
			//exit loop
			line = NULL;

		}
		free(tmp);
		++pos;
	}
}

int main()
{
	char* test = "12cx7,3:09:00,0.968900025,,0,0,56,1";
	FitbitData a;
	processLine(test, ',',&a);

    return 0;
}

