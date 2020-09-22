#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::fstream;

class Exerciseplan
{
public:
    int getStep()const;
    string getName()const;
    string getDate()const;
    void setStep(const int _step);
    void setName(const string _name);
    void setDate(const string _date);
    Exerciseplan(const Exerciseplan &exerciseplan);
    Exerciseplan();
    ~Exerciseplan();
    Exerciseplan& operator= (const Exerciseplan &exerciseplan);
private:
    int Goalstep;
    string name;
    string date;
};

//overload << for printing to screen 
ostream & operator <<(ostream & lhs, const Exerciseplan &rhs);
//overload << for writing to file
fstream & operator << (fstream &lhs, const Exerciseplan &rhs);
//overload >> for reading from a file
fstream & operator >> (fstream & lhs, Exerciseplan &rhs);