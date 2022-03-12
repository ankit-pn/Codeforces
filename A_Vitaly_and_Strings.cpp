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
void solve()
{
    string s;
    string t;
    cin >> s >> t;
    int n = s.length();
    string ans = "";
    int f = 0;
    int in = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] < t[i] && t[i] - s[i] != 1)
        {
            f = 1;
            in = i;
            ans += (s[i] + 1);
            break;
        }
        else if (s[i] == t[i])
            ans += s[i];
        else if (t[i] == s[i] + 1 && i + 1 < n)
        {
            if (s[i + 1] != 'z')
            {
                ans += s[i];

                ans += (s[i + 1] + 1);
            }
            else
            {
                ans += t[i];
                ans += 'a';
                  in = i + 2;
                f = 3;
                break;
            }
            in = i + 1;
            f = 2;
            break;
        }

        else
            break;
    }
    if (f == 3)
    {
        int g = 0;
        for (int i = in; i < n; i++)
        {
            ans += min('a', t[i]);
            if (t[i] != 'a')
            {
                g = 1;
            }
        }
        if (g == 0)
            cout << "No such string\n";
        else
            cout << ans << nline;
    }
    else if (f == 0)
        cout << "No such string\n";
    else
    {
        if (in + 1 < n)
            ans += s.substr(in + 1, n);
        cout << ans << nline;
    }
}
