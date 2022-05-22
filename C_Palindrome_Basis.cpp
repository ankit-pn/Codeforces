#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
void solve();
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}
bool isp(int n)
{
    string s = to_string(n);
    string t = s;
    reverse(s.begin(), s.end());
    if (s == t)
        return 1;
    return 0;
}
void generate(vector<int> &arr)
{
    int n = 4 * 10000;
    for (int i = 1; i < n; i++)
    {
        if (isp(i))
            arr.push_back(i);
    }
}
void cha(vector<int> &arr, vector<vector<int>> &dp)
{
    int szz = arr.size();

    for (int i = 0; i <= szz; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= 40000; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= szz; i++)
    {
        for (int j = 1; j <= 40000; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = (dp[i][j - arr[i - 1]] + dp[i - 1][j])%MOD;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}
void solve()
{
    int t;
    cin >> t;
    vector<int> arr;
    generate(arr);
    int szz = arr.size();
    vector<vector<int>> dp(szz + 1, vector<int>(40001, 0));
    cha(arr, dp);
    // cout<<dp[szz][12];
  

    while(t--){
     int n;
     cin>>n;
        cout<<dp[szz][n]<<"\n";
    }
}
