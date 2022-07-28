#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int a {30};
    int b {620};

    auto func = [=](int a, int b) {return (a>b) ? a : b;};
    cout << func(a,b) << endl;

    return 0;
}