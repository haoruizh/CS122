#include "DietplanHeader.h"
#include "ExerciseplanHeader.h"

using std::ofstream;
using std::ifstream;

class FitnessAppWrapper
{
public:
    void runApp();

    //Load
    //load daily
    void loadDailyPlan(ifstream &fileStream, Dietplan  &dailyDiet);
    void loadDailyPlan(ifstream &fileStream, Exerciseplan &dailyExericse);
    //load weekly
    void loadWeeklyPlan(ifstream &fileStream, Dietplan weeklyDiet[]);
    void loadWeeklyPlan(ifstream &filestream, Exerciseplan weeklyExercise[]);
    
    //Display
    //Daily
    void displayDailyplan(Dietplan &dailyDiet);
    void displayDailyplan(Exerciseplan &dailyExercise);

    //Weekly
    void displayWeeklyPlan(Dietplan weeklyDiet[]);
    void displayWeeklyPlan(Exerciseplan weeklyExercise[]);
    
    //store plan
    //daily
    void storeDailyPlan(ofstream &filestream, Dietplan &dailyDiet);
    void storeDailyPlan(ofstream &filestream, Exerciseplan &dailyExercise);
    //weekly
    void storeWeeklyPlan(ofstream &filestream, Dietplan weeklyDiet[]);
    void storeWeeklyPlan(ofstream &filestream, Exerciseplan weeklyExercise[]);

    //display menu
    int displaymenu();

    //edit
    void editDailyPlan(Dietplan &dailyDiet);
    void editDailyPlan(Exerciseplan &dailyExercise);
    void editWeeklyPlan(Dietplan weeklyDietplan[]);
    void editWeeklyPlan(Exerciseplan weeklyExerciseplan[]);
    FitnessAppWrapper();
    ~FitnessAppWrapper();

private:
    //input and output files for diet and exercise
    ifstream inputDietfile;
    ifstream inputExercisefile;
    ofstream outputDietfile;
    ofstream outputExercisefile;
    //diet and exercise plan
    Dietplan weeklyDietplan[7];
    Exerciseplan weeklyExerciseplan[7];
};
#pragma once
