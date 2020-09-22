#include <iostream>
#include <string>

using namespace std;

//function overloading
int add(int n1, int n2);
double add(double n1, double n2);
string add(string n1, string n2);

int sub(int n1, int n2); //passing by values
int multiplication(int &n1, int &n2);

int main()
{
    cout << "Hello CptS 122!" << endl;
    
    int number = 0;
    cout << "Enter a number";
    cin >> number;
    cout << "number: " << number << endl;

    cout << "Integer add result" << add(6, 7) << endl;

    cout << "Double add result" << add(6.3, 7.8) << endl;
    
    string s1 = "cat", s2 = "dog";

    cout << "string add result:" << add(s1, s2) << endl;


    //reference (direct operation)
    int n1 = 10, n3=3;
    int &n2 = n1; //reference to n1

    cout << "Integer sub result: " << sub(7, n1) << endl;

    //call sub by reference
    cout << "Integer sub result: " << sub(7, n2) << endl;

    cout << "n1: " << n1 << endl;
    cout << "Integer multiplication result: " << multiplication(n1, n3) << endl;
    cout << "n1: " << n1 << endl; //n1 = n1*n3
    return 0;
}

//add function for int type
int add(int n1, int n2)
{
    return n1 + n2;
}

//add function for double type
double add(double n1, double n2)
{
    return n1 + n2;
}

//add function for string type
string add(string n1, string n2)
{
    return n1 + n2;
}

//subtract function
int sub(int n1, int n2)
{
    return n1 - n2;
}

int multiplication(int &n1, int &n2)
{
    return n1 = n1*n2;
}
