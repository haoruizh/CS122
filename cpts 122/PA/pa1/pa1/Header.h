#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//sleep enum type
typedef enum sleep

{

	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3

} Sleep;

//fitbit data structure
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

int deuplicateCheck(FitbitData dataarray, FitbitData presentdata, int *number);
void processline(char *data, char symbol, FitbitData *outputdata);
void printtrashdata(FitbitData *dataarray, int index, FitbitData *trashdata, int invalidindex, FILE *file);
void strcturetostructure(FitbitData *dataarray, int index, FitbitData *trashdata, int invalidindex);