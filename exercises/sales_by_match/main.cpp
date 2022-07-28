
#include <iostream>
#include <vector>

using namespace std;

int Number_Of_Elements(int n, vector<int> ar)
{
    // mark all elements as not visited:
    vector<bool> visited(n, false);

    // go through all array elements and count freq:
    for (size_t i = 0; i < n; i++)
    {
        // check if visited and then skip
        if (visited[i] == true)
            continue;

        // count frequency
        int count{1};
        for (int j = i + 1; j < n; j++)
        {
            if (ar.at(i) == ar.at(j))
            {
                visited[j] = true;
                count++;
            }
        }
        std::cout << "Number of elements " << ar.at(i) << " : " << count << std::endl;
    }
}

int sockMerchant2(int n, vector<int> ar)
{

    /**
         * f is the frequency array
         * i is the control variable of for loops
         * c stores the total number of pairs
         */

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

int main()
{
    vector<int> ar{1, 2, 1, 2, 1, 3, 2, 5, 5};
    Number_Of_Elements(ar.size(), ar);
    sockMerchant2(ar.size(), ar);
    
    return 0;
}
