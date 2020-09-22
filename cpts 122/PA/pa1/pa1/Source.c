#include "Header.h" // include header file

/*Function: check the duplicate data
date change: 9/2/2018
variable: previous data, present data, counting number
return value: checking (0 or 1)*/
int deuplicateCheck(FitbitData previousdata, FitbitData presentdata, int *number)
{
	if (strcmp(previousdata.minute, presentdata.minute) == 0)
	{
        *number++;
		return 1;
	}
	return 0;
}
/*Function: reading and wrting data to data array
date change : 9 / 3 / 2018
variable : original data, symbol to stop reading, output data array
return value : none*/
void processline(char *data, char symbol, FitbitData *outputdata)
{
	char *tmpPtr = NULL, *secPtr = NULL;
	int pos = 0;
	while (data)
	{
		
		tmpPtr = NULL; //set templar pointer to NULL
		secPtr = strchr(data, symbol);//seperate string from original data
		
        if(secPtr!= NULL)//if reading something
		{
			int nsize = secPtr - data;
			if(nsize !=0)
			{
                //allocate space for writing
			    tmpPtr = (char *)malloc(nsize + 1);
                memset(tmpPtr, 0, nsize + 1);
				strncpy(tmpPtr, data, nsize);
			}
			data = secPtr + 1; //reading next data
		}

        else //if reading nothing(last object)
        {
            int nsize = strlen(data);
            if (nsize != 0)
            {
                //allocate spacer for writing
                tmpPtr = (char *)malloc(nsize + 1);
                memset(tmpPtr, 0, nsize + 1);
                strncpy(tmpPtr, data, nsize);
            }
        }

        //writing data to data array
		if (pos == 0)
		{
			if (tmpPtr != NULL)
				strcpy(outputdata->patient, tmpPtr);
		}

		else if (pos == 1)
		{
			if (tmpPtr != NULL)
				strcpy(outputdata->minute, tmpPtr);
		}

		else if (pos == 2)
		{
			if (tmpPtr != NULL)
				outputdata->calories = atof(tmpPtr);
			else
				outputdata->calories = -1;
		}

		else if (pos == 3)
		{
			if (tmpPtr != NULL)
				outputdata->distance = atof(tmpPtr);
		}

		else if (pos == 4)
		{
			if (tmpPtr != NULL)
				outputdata->floors = atoi(tmpPtr);
		}

		else if (pos == 5)
		{
			if (tmpPtr != NULL)
				outputdata->heartRate = atoi(tmpPtr);
			else
				outputdata->heartRate = -1;
		}

		else if (pos == 6)
		{
			if (tmpPtr != NULL)
				outputdata->steps = atoi(tmpPtr);
			else
				outputdata->steps = -1;
		}

		else //last object
		{
			if (tmpPtr != NULL)
				outputdata->sleepLevel = (Sleep)atoi(tmpPtr);
			else
				outputdata->sleepLevel = (Sleep)0;
            pos = 0;//reset pos
            break;//reread a new line
		}
        //free the space allocated
		free(tmpPtr);
        //move to next object
		++pos;
	}
}
/*function: printing out useless data
date change: 9/3/2018
variable: data array, index, trash data array, trash data index, output file
return: none*/
void printtrashdata(FitbitData *dataarray, int index, FitbitData *trashdata, int invalidindex, FILE *file)
{
    //print out datas that have missing information
    for (int i = 0; i < index; ++i)
    {
        if (dataarray[i].heartRate == -1 || (int)dataarray[i].sleepLevel == -1)
        {
            //writing data to file
            fprintf(file, "%s,%s,%f,%f,%d,%d,%d,%d\n", dataarray[i].patient, dataarray[i].minute,dataarray[i].calories,dataarray[i].distance,dataarray[i].floors,dataarray[i].heartRate,dataarray[i].steps,(int)dataarray[i].sleepLevel);
        }
    }

    //print data replicates and wrong patients
    for(int i=0; i<invalidindex-1; ++i)
    {
        fprintf(file, "%s,%s,%f,%f,%d,%d,%d,%d\n", trashdata[i].patient, trashdata[i].minute, trashdata[i].calories, trashdata[i].distance, trashdata[i].floors, trashdata[i].heartRate, trashdata[i].steps, (int)trashdata[i].sleepLevel);
    }
}

/*function: copy one line of data from a structure array to another aray
date changed: 9/3/2018
variable: data array, index, trash data array, trash data index
return: none*/
void strcturetostructure(FitbitData *dataarray, int index, FitbitData *trashdata, int invalidindex)
{
    //copy the origin invalid data to the trashdata array
    strcpy(trashdata[invalidindex].patient, dataarray[index].patient);
    strcpy(trashdata[invalidindex].minute, dataarray[index].minute);
    trashdata[invalidindex].calories = dataarray[index].calories;
    trashdata[invalidindex].distance = dataarray[index].distance;
    trashdata[invalidindex].floors = dataarray[index].floors;
    trashdata[invalidindex].heartRate = dataarray[index].heartRate;
    trashdata[invalidindex].steps = dataarray[index].steps;
    trashdata[invalidindex].sleepLevel = dataarray[index].sleepLevel;
}