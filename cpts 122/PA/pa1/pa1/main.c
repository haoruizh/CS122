#include "Header.h" //include header file


int main()
{
	//open the file for reading and writing
	FILE *file1 = NULL;
	file1 = fopen("FitBitData.csv", "r");
    if (!file1)
    {
        printf("File open failed\n");
    }
	FitbitData dataarray[1450];//create array to hold data from file
    FitbitData invaliddata[10];
	
	//have target patient id
	char readingdata[100] = { 0 };//array for reading lines
	fgets(readingdata, 100, file1);//read the first line
	char *patient = strtok(readingdata,",");
	patient = strtok(NULL, ",");
	char *patientid = (char*)malloc(strlen(patient)+1);
	memset(patientid, 0, strlen(patient)+1);
	strcpy(patientid, patient);
	
	fgets(readingdata, 100, file1);//skip header line
	
	//processing data of each line
	int index = 0, invalidindex = 0; //counting the invalid data number

	while (!feof(file1))
	{
		char realdata[100] = { 0 };
		fgets(realdata, 100, file1); // get first line
		processline(realdata, ',', dataarray + index);
		if (strcmp(dataarray[index].patient, patientid) == 0)
		{
			if ( index ==0  || ( index > 0 && !deuplicateCheck(dataarray[index-1], dataarray[index], &invalidindex)))
			    ++index;
		}
        else
        {
            strcturetostructure(&dataarray, index, &invaliddata, invalidindex);
            ++invalidindex;
        }
	}//finish data process and collection

    FILE *file2 = fopen("Result.csv", "w");
    if (!file2)
    {
        printf("Failed");
    }
	//caculate total calories, distance, floor and step
	int i = 0;
	double totalCalories = 0, totalDistance = 0;
	int totalFloor = 0, totalStep = 0;
	for ( i = 0; i < index; ++i)
	{
		totalCalories += dataarray[i].calories;
		totalDistance += dataarray[i].distance;
		totalFloor += dataarray[i].floors;
		totalStep += dataarray[i].steps;
	}//end of loop

    //find max step
    int maxstep;
    maxstep = dataarray[0].steps;
    for (int i = 1; i < index; ++i)
    {
        if (maxstep < dataarray[i].steps)
        {
            maxstep = dataarray[i].steps;
        }
    }
    //total heartrate
    int heartrate = 0, counting=0;
    for (int i = 0; i < index; ++i)
    {
        if (dataarray[i].heartRate != -1)
        {
            heartrate += dataarray[i].heartRate;
            ++counting;
        }
    }//end of loop

    int averageHeartrate = heartrate / counting;//find average heartrate
    
    //maxsleep
    int maxSleep = 0, currentcount=0;//sleep time variabels;
    for (int i = 0; i < index; ++i)
    {
        while(dataarray[i].sleepLevel > 1)
        {
            currentcount++;
            if (maxSleep < currentcount)
            {
                maxSleep = currentcount;
            }
            ++i;
        }
        currentcount = 0;
    }

    /*output to file*/

    //first line
    fprintf(file2, "Calories ");
    fprintf(file2, "Distance ");
    fprintf(file2, "Floor ");
    fprintf(file2, "Step ");
    fprintf(file2, "Heartrate ");
    fprintf(file2, "M Step ");
    fprintf(file2, "Sleep \n");

    //second line
    fprintf(file2, "%.3f ", totalCalories);
    fprintf(file2, "%.3f ", totalDistance);
    fprintf(file2, "%d ", totalFloor);
    fprintf(file2, "%d ", totalStep);
    fprintf(file2, "%d ", averageHeartrate);
    fprintf(file2, "%d ", maxstep);
    fprintf(file2, "%d\n", maxSleep);
   
    //third line
    fprintf(file2, "N:\n");
    printtrashdata(&dataarray, index, &invaliddata, invalidindex, file2);

	free(patientid); //free memory space

	//close files
	fclose(file1);
	fclose(file2);
	
	return 0;
}