#include <iostream>
#include <basics.h>
//#include "Math_Lib/basics.h"

int main () 
{

    int a, b;
    std::cout << "Please input 2 numbers!\n";
    std::cin >> a >> b;

    std::cout << "sum\t" << add (a,b) << "\n";
    std::cout << "subtrance\t" << subtract (a,b) << "\n";

    return 0;
}