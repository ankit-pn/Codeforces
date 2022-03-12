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
int e = 10e5;
bool** dp;
int isSubsetSum(vector<ll> set, ll n, ll sum)
    {
        // The value of subset[i][j] will be true if there
        // is a subset of set[0..j-1] with sum equal to i
        bool subset[sum + 1][n + 1];
        ll count[sum + 1][n + 1];
 
        // If sum is 0, then answer is true
        for (ll i = 0; i <= n; i++)
        {
            subset[0][i] = true;
            count[0][i] = 0;
        }
     
        // If sum is not 0 and set is empty,
        // then answer is false
        for (ll i = 1; i <= sum; i++)
        {
            subset[i][0] = false;
            count[i][0] = INF;
        }
 
        // Fill the subset table in bottom up manner
        for (ll i = 1; i <= sum; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                subset[i][j] = subset[i][j - 1];
                count[i][j] = count[i][j - 1];
                if (i >= set[j - 1])
                {
                    subset[i][j] = subset[i][j] ||
                                subset[i - set[j - 1]][j - 1];
 
                    if (subset[i][j])
                        count[i][j] = min(count[i][j - 1],
                                    count[i - set[j - 1]][j - 1] + 1);
                }
            }
        }
 
        return count[sum][n];
    }
void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll fact[16];
        fact[0] = 0;
        fact[1] = 1;
        fact[2] = 2;
        fact[3] = 6;
        for (ll i = 4; i < 16; i++)
            fact[i] = fact[i - 1] * i;
        ll pow[40];
        pow[0] = 1;
        pow[1] = 2;
        pow[2] = 4;
        for (ll i = 3; i < 40; i++)
            pow[i] = pow[i - 1] * 2;
        vector<ll> res;
        for (ll i = 0; i < 16; i++)
            res.push_back(fact[i]);
        for (ll i = 0; i < 40; i++)
            res.push_back(pow[i]);
        ll q;
        cin >> q;
        // cout<<q<<"\n";
        // for(auto it:res)
        // cout<<it<<"\n";
        // cout << Count(res, res.size(), q) << "\n";
        cout<<isSubsetSum(res,res.size(),q)<<"\n";
    }
}
