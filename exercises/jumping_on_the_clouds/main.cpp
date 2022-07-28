#include <bits/stdc++.h>
#include <vector>

using namespace std;

int jumpingOnClouds(vector<int> c)
{
    int n, jumps = 0;
    n = c.size();


    for (int i = 0; i < n; i++) {
        if (i+2 < n && !c[i+2]) {
            jumps++;
            i++;
        } else if (i+1 < n && !c[i+1]) {
            jumps++;
        }
    }

    return jumps;
}

int main()
{
    int res{};
    vector<int> clouds{0, 0};
    vector<int> clouds7{0, 0, 1, 0, 0, 1, 0};
    vector<int> clouds6{0, 0, 0, 1, 0, 0};
    vector<int> clouds2{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0};

    res = jumpingOnClouds(clouds);
    cout << "Clouds: " << res << endl;

    return 0;
}
