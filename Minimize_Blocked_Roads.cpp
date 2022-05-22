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
int initt(vector<int> &cities, int j, vector<vector<pair<int, int>>> &g)
{

    int sum = 1;
    if(g[j].empty())
    return 1;

    for (auto &it : g[j])
    {
        sum += initt(cities, it.first, g);
    }
    return sum;
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<pair<int, int>>> g(n + 1);
        vector<int> cities(n+1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(mp(b, c));
        }
        queue<pair<int, int>> que;
        int f = 0;
        int count = 0;
        for(int i=1;i<=n;i++){
            cities[i]=initt(cities,i,g);
        }
        // for(auto it:cities)
        // cout<<it<<" ";
        for (int i = 0; i < g[1].size(); i++)
        {
            if (g[1][i].second == 1)
            {
                k -= cities[g[1][i].first];
                count++;
            }
            else
            {
                que.push(g[1][i]);
            }
            if (k <= 0)
            {
                cout << count << "\n";
                f = 1;
                break;
            }
        }
        if (f)
            continue;

        while (!que.empty())
        {
            auto x = que.front();
            que.pop();
            for (int i = 0; i < g[x.first].size(); i++)
            {
                if (g[x.first][i].second == 1)
                {
                    k -= cities[g[x.first][i].first];
                    count++;
                }
                else
                {
                    que.push(g[x.first][i]);
                }
                if (k <= 0)
                {
                    cout << count << "\n";
                    f = 1;
                    break;
                }
            }
            if(f)
            break;
        }
        if (f)
        continue;
        else
        cout<<-1<<"\n";
    }
}
