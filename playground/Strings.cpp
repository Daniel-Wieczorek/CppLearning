//============================================================================
// Name        : Strings.cpp
// Author      : DWI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
//======================== C BASED STRINGS =============================================
cout << "---------------------------------------------" << endl;
char first_name[20] {};
char last_name[20] {};
char full_name[20] {};

char temp[] {"And this is Daniel BRO"};

strcpy(last_name,"Wieczorek");

char var1[] = {0x10, 0x10, 0x10};
unsigned char var2[] = {0xFF, 0xFF, 0xFF};
//signed char var3[] = {0xFF, 0xFF, 0xFF};

std::cout << strlen(var1) << std::endl; // ToDo -> how to handle unsigned char data. 

strcpy(first_name, "Daniel");
strcpy(full_name, first_name);
strcat(full_name, " ");
strcat(full_name, last_name);

std::cout << full_name << std::endl;
cout << "---------------------------------------------" << endl;

#if 0
//======================== STRINGS IN CPP ==========================================
cout << "---------------------------------------------" << endl;
string fruit_1 {"Apple"};
string myName {"Daniel Wieczorek"};

cout << fruit_1 << endl << myName << endl << "my name params: " \
<< myName.length() << " " << myName.size() << endl;

string x_array (10, 'X');
cout << x_array <<endl;

//==================== FOR LOOPs =====================

for (size_t i {0}; i < myName.length(); i++)
{
	cout << myName.at(i) << endl;
}

cout << "SECOND LOOP" << endl;
for (auto character : myName)
	cout << character << endl;
cout << "____________" << endl;

//======================== SUB_STRING ============================================

cout << myName.substr(0,6) <<endl;

//====================== FIND WORD =======================================
string word {"W"};

size_t position = myName.find(word);
cout << position << endl;

if (position != string::npos)
	cout << "Found" << endl;
else
	cout << "Not Found" << endl;

# endif
//============================================================================
	cout << "___ END ___" << endl;
	return 0;
}
