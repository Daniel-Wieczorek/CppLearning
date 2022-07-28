//============================================================================
// Name        : Playground.cpp
// Author      : DWI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int *pointerArray[5] {NULL}; // it will be the array of the pointers!

    int a {10}, b {20}, c {30};
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;

    pointerArray[0] = ptr_a;
    pointerArray[1] = ptr_b;
    pointerArray[2] = ptr_c;
    
    /* MANUAL WAY */
    cout << "Address of the array element +0 : " << pointerArray << endl;   // addresses of the array
    cout << "Address of the array element +1 : " << pointerArray+1 << endl; // addresses of the array
    cout << "Address of the array element +2 : " << pointerArray+2 << endl; // addresses of the array
    cout << "Address of the array element +3 : " << pointerArray+3 << endl; // addresses of the array
    cout << "Address of the array element +4 : " << pointerArray+4 << endl; // addresses of the array

    cout << "Value under array +0 : " << *(pointerArray) << endl;   // addresses of the array elements (array of pointers)
    cout << "Value under array +1 : " << *(pointerArray+1) << endl; // addresses of the array elements (array of pointers)
    cout << "Value under array +2 : " << *(pointerArray+2) << endl; // addresses of the array elements (array of pointers)
    cout << "Value under array +3 : " << *(pointerArray+3) << endl; // addresses of the array elements (array of pointers)
    cout << "Value under array +4 : " << *(pointerArray+4) << endl; // addresses of the array elements (array of pointers)

    cout << "Value under array pointer +0 : " << *(pointerArray[0]) << endl;   // addresses of the array elements (array of pointers)
    cout << "Value under array pointer +1 : " << *(pointerArray[1]) << endl; // addresses of the array elements (array of pointers)
    cout << "Value under array pointer +2 : " << *(pointerArray[2]) << endl; // addresses of the array elements (array of pointers)
 
    for(const auto &var: pointerArray)
    {
        cout << "Pointers addresses in array: " << var << endl;
    }

    cout << endl;
    for(const auto &var: pointerArray)
    {
        cout << "Pointer values in array: " << *var << endl; // there should be an error after 3rd element - pointing to NULL
    }

    cout << " --- PROGRAM ENDS " << endl;

    /*
    What is more:

    char* argv[] AND char ** argv
    
    ARE THE SAME
    
    */
    return 0;
}