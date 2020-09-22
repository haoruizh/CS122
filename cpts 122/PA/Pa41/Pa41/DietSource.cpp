#include "DietplanHeader.h"
using std::endl;


//overload << for printing to screen 
ostream & operator <<(ostream & lhs, const Dietplan &rhs)
{
    lhs << rhs.getCalores() << endl;
    lhs << rhs.getName() << endl;
    lhs << rhs.getDate() << endl << endl;
    return lhs;
}

//overload << for writing to file
fstream & operator << (fstream &lhs, const Dietplan &rhs)
{
    lhs << rhs.getCalores() << endl;
    lhs << rhs.getName() << endl;
    lhs << rhs.getDate() << endl << endl;
    return lhs;
}

//overload >> for reading from a file
fstream & operator >> (fstream & lhs, Dietplan &rhs)
{
    int read_calores = 0;
    string read_name, read_date;
    lhs >> read_calores;
    lhs >> read_name;
    lhs >> read_date;
    rhs.setCalores(read_calores);
    rhs.setName(read_name);
    rhs.setDate(read_date);
    return lhs;
}

int Dietplan::getCalores()const
{
    return calores;
}
void Dietplan::setCalores(const int & _calories)
{
    calores = _calories;
}

string Dietplan::getName()const
{
    return name;
}
void Dietplan::setName(const string& _name)
{
    name = _name;
}

string Dietplan::getDate() const
{
    return date;
}
void Dietplan::setDate(const string & _date)
{
    date = _date;
}

Dietplan::Dietplan()
{

}

//overload copy constructor
Dietplan::Dietplan(const Dietplan &dietplanSource)
{
    this->setCalores(dietplanSource.getCalores());
    this->setDate(dietplanSource.getDate());
    this->setName(dietplanSource.getName());
}

//overload = operator, return Dietplan reference type
Dietplan& Dietplan::operator= (const Dietplan &dietplan)
{
    this->setCalores(dietplan.getCalores());
    this->setDate(dietplan.getDate());
    this->setName(dietplan.getName());
    return *this;
}