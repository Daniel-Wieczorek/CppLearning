//============================================================================
// Name        : Playground.cpp
// Author      : DWI
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
//======================== SWITCH CASE =============================================
cout << "---------------------------------------------" << endl;

enum Direction {
	left, right, up, down
};

Direction heading {left};

switch (heading)
{
	case left: 
		cout << "LEFT" << endl;
		break;
	case right:
		cout << "RIGHT" << endl;
		break;
	case up:
		cout << "UP" << endl;
		break;
	case down:
		cout << "DOWN" << endl;
		break;
	default:
		break;
}

//======================== CONDITIONAL OPERATOR ==========================================
cout << "---------------------------------------------" << endl;

int a {0};
int b {0};
int result {0};

//cin >> a >> b;

result = (a > b) ? a : b;
cout << "Bigger is: " << result << endl;

//==================== FOR LOOP RANGE BASED =====================
cout << "---------------------------------------------" << endl;
int scores [] {100, 90, 80};

// for (auto scoreIterator : scores)
// 	cout << scoreIterator << endl;

// for (auto character : "Daniel")
// 	cout << character;
// cout << endl;

vector <double> temperatures {10.2, 13.433, 46.5, 66.6};
double average_temp{};
double total{};

for (auto temp: temperatures)
{
	total += temp;
}
cout << fixed << setprecision(1);
cout << "Average temp:" << total << endl;

//======================== WHILE LOOP ============================================
cout << "---------------------------------------------" << endl;

bool done {false};
int number {};

while (!done)
{
	cout << "Enter valid number";
	cin >> number;

	if (number <= 1 or number >= 5)
		cout << "Out of range" << endl;
	else
	{
		cout << "Thanks" << endl;
		done = true;
	}
	
}

//====================== NESTED LOOP VECTOR =======================================
cout << "---------------------------------------------" << endl;

vector <vector<int>> vector_2d
{
	{1, 2, 3},
	{10, 20, 30, 40},
	{100, 200, 300, 400, 500}
};

for (auto vecOut: vector_2d)
{
	for (auto vecIn: vecOut)
	{
		cout << vecIn << " ";
	}
	cout << endl;
}


//============================================================================
	cout << "___ END ___" << endl;
	return 0;
}
