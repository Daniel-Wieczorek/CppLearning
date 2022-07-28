#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int f[101], i;
    int c = 0;

    //initializing the array with all 0s

    for (i = 0; i < 101; i++)
        f[i] = 0;

    //filling up the frequency array

    for (i = 0; i < n; i++)
        f[ar.at(i)]++;

    //counting the total number of pairs

    for (i = 1; i <= 100; i++)
        c += f[i] / 2;

    return c;
}