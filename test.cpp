
#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define ll long long
int recur(int n)
{
    int i, sum;
    if (n == 0)
        return 1;
    else
    {
        sum = 0;
        for (i = 0; i < n; i++)
            sum = sum + recur(i);
        return sum;
    }
}
int main()
{
    cout<<recur(10);
    return 0;
}