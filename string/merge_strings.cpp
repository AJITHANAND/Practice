#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string finalStr = "";
        int n = word1.length();
        int m = word2.length();
        int start, i;
        start = min(n, m);

        for (i = 0; i < start; i++)
        {
            finalStr += word1[i];
            finalStr += word2[i];
        }

        while (i < n)
        {
            finalStr += word1[i];
            i++;
        }

        while (i < m)
        {
            finalStr += word2[i];
            i++;
        }

        return finalStr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution t;
    cout << t.mergeAlternately("ab", "pqrs");

    return 0;
}