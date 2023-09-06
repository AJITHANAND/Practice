#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Solution
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        vector<int> result;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (num1[i] > num2[j])
            {
                result.push_back(num2[j++]);
            }
            else if (num1[i] < num2[j])
            {
                result.push_back(num1[i++]);
            }
            else
            {
                result.push_back(num1[i++]);
                result.push_back(num2[j++]);
            }
        }
        while (i < m)
        {
            result.push_back(num1[i++]);
        }
        while (j < n)
        {
            result.push_back(num2[j++]);
        }
        num1 = result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> num2 = {2, 5, 6};
    int n = 3;

    Solution st;
    st.merge(num1, m, num2, n);
    for (auto x : num1)
    {
        cout << x << " ";
    }

    return 0;
}