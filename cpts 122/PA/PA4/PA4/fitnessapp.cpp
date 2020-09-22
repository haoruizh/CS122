#include "AppwraperHeader.h"

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;


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

void FitnessAppWrapper::runApp()
{
    int option = 0;
    for(option;option!=9;option = displaymenu())
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
        system("cls");
    }
    FitnessAppWrapper::~FitnessAppWrapper();
}

FitnessAppWrapper::~FitnessAppWrapper()
{
    this->inputDietfile.close();
    this->inputExercisefile.close();
    this->outputDietfile.close();
    this->outputExercisefile.close();
}

void editWeeklyPlan(Dietplan weeklyDietplan[]);
void editWeeklyPlan(Exerciseplan weeklyExerciseplan[]);