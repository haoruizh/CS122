#include "AppwraperHeader.h"
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::getline;


//print out menu and return the option
int FitnessAppWrapper::displaymenu()
{
    int option = 0;
    //1.    Load weekly diet plan from file.

    //    2.    Load weekly exercise plan from file.

    //    3.    Store weekly diet plan to file.

    //    4.    Store weekly exercise plan to file.

    //    5.    Display weekly diet plan to screen.

    //    6.    Display weekly exercise plan to screen.

    //    7.    Edit daily diet plan.

    //    8.    Edit daily exercise plan.

    //    9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files.

    cout << "Menu: " << endl;
    cout << "1). Load weekly diet plans" << endl;
    cout << "2). Load weekly exercise plans" << endl;
    cout << "3). Store weekly diet plans" << endl;
    cout << "4). Store weekly exercise plans" << endl;
    cout << "5). Display weekly diet plans" << endl;
    cout << "6). Display weekly exercise plans" << endl;
    cout << "7). Edit daily diet plan" << endl;
    cout << "8). Edit daily exercise plan" << endl;
    cout << "9). Exit" << endl;
    cin >> option;
    return option;
}

//run the app
void FitnessAppWrapper::runApp()
{
    int option = 0;
    for (option;option != 9;option = displaymenu())
    {
        switch (option)
        {
        case 1:
            loadWeeklyPlan(inputDietfile, weeklyDietplan);
            break;
        case 2:
            loadWeeklyPlan(inputExercisefile, weeklyExerciseplan);
            break;
        case 3:
            storeWeeklyPlan(outputDietfile, weeklyDietplan);
            break;
        case 4:
            storeWeeklyPlan(outputExercisefile, weeklyExerciseplan);
            break;
        case 5:
            displayWeeklyPlan(weeklyDietplan);
            break;
        case 6:
            displayWeeklyPlan(weeklyExerciseplan);
            break;
        case 7:
            editWeeklyPlan(weeklyDietplan);
            break;
        case 8:
            editWeeklyPlan(weeklyExerciseplan);
            break;
        }
        system("Pause");
        system("cls");
    }
    if (option == 9)
    {
        storeWeeklyPlan(outputDietfile, weeklyDietplan);
        storeWeeklyPlan(outputExercisefile, weeklyExerciseplan);
    }
}
//app destructor
FitnessAppWrapper::~FitnessAppWrapper()
{
    cout << "Diet file saved" << endl;
    cout << "Exercise file saved"<<endl;
}

//edit daily diet plan
void FitnessAppWrapper::editDailyPlan(Dietplan &dailyDiet)
{
    int cal = 0;
    string na = "\0", da = "\0", calstr="\0";
    cout << "Enter the cal:";
    getchar();
    getline(cin, calstr);
    cout << "Enter the name:";
    getline(cin, na);
    cout << "Enter the date:(MM/DD/YY)";
    getline(cin, da);

    if (na.empty())
    {
        dailyDiet.setName("N/A");
    }
    else
    {
        dailyDiet.setName(na);
    }

    if (calstr.empty())
    {
        dailyDiet.setCalores(0);
    }
    else
    {
        cal = atoi(calstr.c_str());
        dailyDiet.setCalores(cal);
    }

    if(da.empty())
    {
        dailyDiet.setDate("N/A");
    }
    else
    {
        dailyDiet.setDate(da);
    }
}

//edit daily exercise plan
void FitnessAppWrapper::editDailyPlan(Exerciseplan &dailyExercise)
{
    int step = 0;
    string na = "\0", da = "\0", stepstr="\0";
    cout << "Enter the step:";
    getchar();
    getline(cin, stepstr);
    cout << "Enter the name:";
    getline(cin, na);
    cout << "Enter the date:(MM/DD/YY)";
    getline(cin, da);

    //if name is empty
    if (na.empty())
    {
        dailyExercise.setName("N/A");
    }
    else
    {
        dailyExercise.setName(na);
    }

    //if step is empty
    if (stepstr.empty())
    {
        dailyExercise.setStep(0);
    }
    else
    {
        step = atoi(stepstr.c_str());
        dailyExercise.setStep(step);
    }

    //if date is empty
    if (da.empty())
    {
        dailyExercise.setDate("N/A");
    }
    else
    {
        dailyExercise.setDate(da);
    }
    
}

//edit weekly plan
void FitnessAppWrapper::editWeeklyPlan(Dietplan weeklyDietplan[])
{
    if (weeklyDietplan)//if plan exists
    {
        int index = 0, mode = 0;
        //two option of edit
        cout << "Choose the edit mode:" << endl;
        cout << "1). Week" << endl;
        cout << "2) Day" << endl;
        cout << "Which mode do you choose?";
        cin >> mode;
        if (mode == 1)
        {
            //edit the week plan
            for (index = 0;index < 7;++index)
            {
                editDailyPlan(weeklyDietplan[index]);
            }
        }
        else if (mode == 2)
        {
            //edit the daily plan
            cout<<"Enter the day you want to edit:";
            cin >> index;
            editDailyPlan(weeklyDietplan[index]);
        }
    }
    else
    {
        cout << "No existence plan" << endl;
    }
}

void FitnessAppWrapper::editWeeklyPlan(Exerciseplan weeklyExerciseplan[])
{
    if (weeklyExerciseplan)//if plan exists
    {
        int index = 0, mode = 0;
        //two modes
        cout << "Choose the edit mode:" << endl;
        cout << "1). Week" << endl;
        cout << "2) Day" << endl;
        cout << "Which mode do you choose?";
        cin >> mode;
        if (mode == 1)
        {
            //weekly
            for (index = 0;index < 7;++index)
            {
                editDailyPlan(weeklyExerciseplan[index]);
            }
        }
        else if (mode == 2)
        {
            //daily
            cout << "Enter the day you want to edit:";
            cin >> index;
            editDailyPlan(weeklyExerciseplan[index]);
        }
    }
    else
    {
        cout << "No existence plan" << endl;
    }
}

FitnessAppWrapper::FitnessAppWrapper()
{

}

//save the diet plan to file
void FitnessAppWrapper::storeWeeklyPlan(ofstream &filestream, Dietplan weeklyDiet[])
{
    //open file
    filestream.open("Diet.txt");

    if (filestream.is_open())//check if file is opened
    {
        int index = 0;
        while (index < 7)
        {
            //store the plan to the file
            storeDailyPlan(filestream, weeklyDiet[index]);
            ++index;
        }
    }
    else
    {
        cout << "File open failed" << endl;
    }
    filestream.close();//close file
}

//save the exercise plan to the file
void FitnessAppWrapper::storeWeeklyPlan(ofstream &filestream, Exerciseplan weeklyExercise[])
{
    //open file
    filestream.open("Exercise.txt");

    if (filestream.is_open())//if the file is opened
    {
        int index = 0;
        while (index < 7)
        {
            //save daily plan to file
            storeDailyPlan(filestream, weeklyExercise[index]);
            ++index;
        }
    }
    else
    {
        cout << "File open failed" << endl;
    }

    filestream.close();
}

//Load
//load daily diet plan
void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, Dietplan  &dailyDiet)
{
    int goal = 0;
    string name = "\0", date = "\0", goalstring="\0", ignore="\0";
    //get the data
    getline(fileStream, name);
    getline(fileStream, goalstring);
    getline(fileStream, date);
    getline(fileStream, ignore);//skip the empty line

    //check if the name is empty
    if (name.empty())
    {
        name = "N/A";
    }
    //check if the goal is empty
    if (goalstring.empty())
    {
        goalstring = "0";
    }
    //check if the date is empty
    if (date.empty())
    {
        date = "N/A";
    }

    //set plan variables to daily plan
    goal = atoi(goalstring.c_str());
    dailyDiet.setCalores(goal);
    dailyDiet.setDate(date);
    dailyDiet.setName(name);
}

//load daily exercise plan
void FitnessAppWrapper::loadDailyPlan(ifstream &fileStream, Exerciseplan &dailyExercise)
{
    int goal = 0;
    string name = "\0", date = "\0", goalstring="\0", ignore="\0";
    
    //get data
    getline(fileStream, name);
    getline(fileStream, goalstring);
    getline(fileStream, date);
    getline(fileStream, ignore);

    //if name is empty
    if (name.empty())
    {
        name = "N/A";
    }
    //if goal is empty
    if (goalstring.empty())
    {
        goalstring = "0";
    }
    //if date is empty
    if (date.empty())
    {
        date = "N/A";
    }
    //set plan varibles as file datas
    goal = atoi(goalstring.c_str());
    dailyExercise.setStep(goal);
    dailyExercise.setDate(date);
    dailyExercise.setName(name);
}

//load weekly
//weekly diet plan
void FitnessAppWrapper::loadWeeklyPlan(ifstream &fileStream, Dietplan weeklyDiet[])
{
    //open file
    fileStream.open("Diet.txt");

    if (fileStream.is_open())//if the file is opened
    {
        int index = 0;
        while (index < 7 || !fileStream.eof())
        {
            //load daily diet plan
            loadDailyPlan(fileStream, weeklyDiet[index]);
            ++index;
        }
    }
    fileStream.close();//close the file
}

//load exercise plan
void FitnessAppWrapper::loadWeeklyPlan(ifstream &filestream, Exerciseplan weeklyExercise[])
{
    //open the file
    filestream.open("Exercise.txt");

    if (filestream.is_open())//if file is opened
    {
        int index = 0;
        while (index < 7 || !filestream.eof())
        {
            //load daily exercise plan
            loadDailyPlan(filestream, weeklyExercise[index]);
            ++index;
        }
    }
    filestream.close();//close file
}

//Display
//Daily
//display diet plan
void FitnessAppWrapper::displayDailyplan(Dietplan &dailyDiet)
{
    cout << "Name:" << dailyDiet.getName() << endl;
    cout << "Goal:" << dailyDiet.getCalores() << " calores" << endl;
    cout << "Date:" << dailyDiet.getDate() << endl << endl;
}

//display daily exercise plan
void FitnessAppWrapper::displayDailyplan(Exerciseplan &dailyExercise)
{
    cout << "Name:" << dailyExercise.getName() << endl;
    cout << "Goal:" << dailyExercise.getStep() << " steps" << endl;
    cout << "Date:" << dailyExercise.getDate() << endl << endl;
}

//Weekly
//display weekly diet plan
void FitnessAppWrapper::displayWeeklyPlan(Dietplan weeklyDiet[])
{
        for (int index = 0;index < 7;++index)
        {
            cout << "Day " << index+1 << endl;
            displayDailyplan(weeklyDiet[index]);
        }
}

//display weekly exercise plan
void FitnessAppWrapper::displayWeeklyPlan(Exerciseplan weeklyExercise[])
{
        for (int index = 0;index < 7;++index)
        {
            cout << "Day " << index + 1 << endl;
            displayDailyplan(weeklyExerciseplan[index]);
        }
}

//store plan
//daily
//store daily plan
void FitnessAppWrapper::storeDailyPlan(ofstream &filestream, Dietplan &dailyDiet)
{
    filestream << dailyDiet.getName() << endl;
    filestream << dailyDiet.getCalores() << endl;
    filestream << dailyDiet.getDate() << endl;
    filestream << endl;//add one empty line
}

//store daily exercise plan
void FitnessAppWrapper::storeDailyPlan(ofstream &filestream, Exerciseplan &dailyExercise)
{
    filestream << dailyExercise.getName() << endl;
    filestream << dailyExercise.getStep() << endl;
    filestream << dailyExercise.getDate() << endl;
    filestream << endl;//add one empty line
}