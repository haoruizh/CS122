#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ostream;
using std::fstream;

class Dietplan
{
public:
    //getter and setter for calores
    int getCalores() const;
    void setCalores(const int & _calories);

    //getter and setter for name
    string getName()const;
    void setName(const string& _name);

    //getter and setter for date
    string getDate() const;
    void setDate(const string & _date);

    //defalut constructor
    Dietplan();
    //overload constructor
    Dietplan(const Dietplan &dietplanSource);
    Dietplan& operator= (const Dietplan &dietplan);//= operator overload
private:
    int calores;
    string name;
    string date;
};

//overload << for printing to screen 
ostream & operator <<(ostream & lhs, Dietplan &rhs);
//overload << for writing to file
fstream & operator << (fstream &lhs, Dietplan &rhs);
//overload >> for reading from a file
fstream & operator >> (fstream & lhs, Dietplan &rhs);