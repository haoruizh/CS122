// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <stdio.h>
#include <tchar.h>
 


// TODO: reference additional headers your program requires here


class  complex
{
public:
     complex();
    ~ complex();
    void Read();
    void Print();
    void Add();
    void Sub();
    void setPart();
    double getter();

private:
    double realPart;
    double imagernPart;
};

int testComplex();