// Queue.cpp : Defines the entry point for the console application.
//


#include <fstream>
#include "stdafx.h"

using std::fstream;
using std::ifstream;
using std::ofstream;

int main()
{
    Node n1("PJ1");

    Queue printJobs;

    ifstream input;//input("printjons.txt");

    input.open("printjobs.txt");
    string pj;

    input >> pj;
    char line[100];
    input.getline(line, 100);
    return 0;
}

