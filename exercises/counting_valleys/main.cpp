#include <bits/stdc++.h>

using namespace std;

int countingValleys(int steps, string path)
{

    int sea_level_counter{}, level{};
    for (size_t i = 0; i < steps; i++)
    {
        if (path.at(i) == 'D')
            level--;
        else if (path.at(i) == 'U')
            level++;

        if (level == 0 && path.at(i) == 'U')
            sea_level_counter++;
    }
    return sea_level_counter;
}

int main()
{
    int res{};
    string path{"DDUUDDUU"};

    res = countingValleys(path.length(), path);
    cout << "Valleys: " << res << endl;

    return 0;
}
