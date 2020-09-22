#include "ExerciseplanHeader.h"

using std::endl;
//overload << for printing to screen 
ostream & operator <<(ostream & lhs, const Exerciseplan &rhs)
{
    lhs << rhs.getName() << endl;
    lhs << rhs.getStep() << endl;
    lhs << rhs.getDate() << endl;
    return lhs;
}
//overload << for writing to file
fstream & operator << (fstream &lhs, const Exerciseplan &rhs)
{
    lhs << rhs.getName() << endl;
    lhs << rhs.getStep() << endl;
    lhs << rhs.getDate() << endl;
    return lhs;
}
//overload >> for reading from a file
fstream & operator >> (fstream & lhs, Exerciseplan &rhs)
{
    int read_step = 0;
    string read_name, read_date;
    lhs >> read_step;
    lhs >> read_name;
    lhs >> read_date;
    rhs.setStep(read_step);
    rhs.setName(read_name);
    rhs.setDate(read_date);
    return lhs;
}

int Exerciseplan::getStep()const
{
    return Goalstep;
}
string Exerciseplan::getName()const
{
    return name;
}
string Exerciseplan::getDate()const
{
    return date;
}
void Exerciseplan::setStep(const int _step)
{
    Goalstep = _step;
}
void Exerciseplan::setName(const string _name)
{
    name = _name;
}
void Exerciseplan::setDate(const string _date)
{
    date = _date;
}

Exerciseplan::Exerciseplan()
{

}

//overload copy constructor
Exerciseplan::Exerciseplan(const Exerciseplan &exerciseplan)
{
    this->setName(exerciseplan.getName());
    this->setDate(exerciseplan.getDate());
    this->setStep(exerciseplan.getStep());
}

//overload = operator, return the Exerciseplan type
Exerciseplan& Exerciseplan::operator= (const Exerciseplan &exerciseplan)
{
    this->setName(exerciseplan.getName());
    this->setDate(exerciseplan.getDate());
    this->setStep(exerciseplan.getStep());
    return *this;
}