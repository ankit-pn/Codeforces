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
// void solve()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> arr(n - 1, 0);
//          vector<int> tree[n + 1];
//         for (int i = 0; i < n - 1; i++)
//             cin >> arr[i];
//         string s;
//         cin >> s;

//         for (int i = 1; i <= n; i++)
//         {
//             int a;
//             cin>>a;
//             tree[a].push_back(i+1);
//         }
//         map<int, pair<int, int>> mp1;
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i - 1] == 'W')
//                 mp1[i] = mp(1, 0);
//             else if (s[i - 1] == 'B')
//                 mp1[i] = mp(0, 1);
//         }
//         queue<pair<int, pair<int, int>>> q;
//         vector<bool> dp(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             if (tree[i].size() == 0)
//             {
//                 q.push(mp(i, mp1[i]));
//                 dp[i] = 1;
//             }
//         }
//         int c = 0;

//         while (!dp[1] && !q.empty())
//         {
//             auto x = q.front();
//             int y = x.first;
//             if ((tree[y].size() == 1 && dp[tree[y][0]] == 0) || (tree[y].size() == 2 && (dp[tree[y][0]] == 0 || dp[tree[y][1]] == 0)))
//             {
//                 q.pop();
//                 continue;
//             }
//             dp[y] = 1;
//             if (y == 1)
//             {
//                 if (x.second.second == x.second.first)
//                     c++;
//                 q.pop();
//                 break;
//             }
//             if (x.second.second == x.second.first)
//                 c++;
//             int parent = arr[y - 2];
//             auto qq = mp1[parent];
//             qq.first += x.second.first;
//             qq.second += x.second.second;
//             mp1[parent] = qq;
//             if ((tree[parent].size() == 1 && dp[tree[parent][0]] == 1) || (tree[parent].size() == 2 && (dp[tree[parent][0]] == 1 && dp[tree[parent][1]] == 1)))
//                 q.push(mp(parent, mp1[parent]));
//             q.pop();
//         }
//         cout << c << "\n";
//     }
// }


int dp(int x, string &s, vector<vector<int>> &tree,int &res)
{
    int bal = (s[x - 1] == 'W') ? -1 : 1;
    if(tree[x].size()==0)
    return bal;
    for (int it : tree[x])
    {
        bal += dp(it,s,tree,res);
    }
    if (bal == 0)
        res++;
    return bal;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> tree(n+1);
        for (int i = 2; i <= n; i++)
        {
            int a;
            cin >> a;
            tree[a].push_back(i);
        }
        string s;
        cin >> s;
        int res=0;
        dp(1, s, tree,res);
        cout << res << "\n";
    }
}
