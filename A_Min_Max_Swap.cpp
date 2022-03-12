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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n, 0);
        vector<ll> brr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> brr[i];
        int t = *max_element(arr.begin(), arr.end());
        int t1 = *max_element(brr.begin(), brr.end());
        if (t > t1)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < brr[i])
                    brr[i] = arr[i];
            }
            int t3 = *max_element(brr.begin(), brr.end());

            cout << t * t3 << nline;
        }
        else if (t < t1)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > brr[i])
                    arr[i] = brr[i];
            }
            int t3 = *max_element(arr.begin(), arr.end());

            cout << t1 * t3 << nline;
        }
        else
        {
            vector<ll> temp = arr;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > brr[i])
                    temp[i] = brr[i];
            }
            int tem1 = *max_element(temp.begin(), temp.end());
            int m1 = tem1 * t1;

            vector<ll> temp2 = brr;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < brr[i])
                    temp2[i] = arr[i];
            }
            int tem2 = *max_element(temp2.begin(), temp2.end());
            int m2 = tem2 * t;

            cout << min(m1, m2) << nline;
        }
    }
}
