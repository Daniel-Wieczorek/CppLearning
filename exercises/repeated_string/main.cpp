#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n)
{
    long long cnt {}, remaining {}, repetition {}, remCnt {};

    long long len = s.length();
    remaining = n % len;
    repetition = n / len;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a')
            cnt++;
        if (s[i] == 'a' && i < remaining)
            remCnt++;
    }
    return (cnt * repetition) + remCnt;
}

int main()
{
#if 0
    string strin = "abcd";
    int length = strin.length();

    for (int i = 0; i < 10; i++)
    {
        strin = strin + strin.at(0);
        strin.erase(0, 1);
        cout << "Length: " << strin.length() << "| i :" << i << " | string: " << strin << endl;
    }
#endif

    long long res{};
    string path{"a"};

    res = repeatedString(path, 1000000000000);
    cout << "result: " << res << endl;
    cout << "result: " << 1000000000000 << endl;

    return 0;
}
