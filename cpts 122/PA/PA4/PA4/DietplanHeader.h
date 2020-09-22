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
    int getCalores () const;
    void setCalores(const int & _calories);

    string getName ()const;
    void setName(const string& _name);

    string getDate() const;
    void setDate(const string & _date);

    Dietplan(const Dietplan &dietplanSource);
    Dietplan();
    ~Dietplan();
    Dietplan& operator= (const Dietplan &dietplan);
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