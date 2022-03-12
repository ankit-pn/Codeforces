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
// ll arr[4001];
// ll m(ll n, ll a, ll b, ll c)
// {

//     if (n == 0)
//         return 1;
//     if (n < 0)
//         return INT_MIN;
//     if (n >= a && arr[n - a] == -1)
//         arr[n - a] = m(n - a, a, b, c);
//     if (n >= b && arr[n - b] == -1)
//         arr[n - b] = m(n - b, a, b, c);
//     if (n >= c && arr[n - c] == -1)
//         arr[n - c] = m(n - c, a, b, c);

//     if (n >= a && n >= b && n >= c)
//         return 1 + max(arr[n - a], max(arr[n - b], arr[n - c]));
//     else if (n >= a && n >= b)
//         return 1 + max(arr[n - a], arr[n - b]);
//     else if (n >= b && n >= c)
//         return 1 + max(arr[n - b], arr[n - c]);
//     else if (n >= a && n >= c)
//         return 1 + max(arr[n - a], arr[n - c]);
//     else if (n >= a)
//         return 1 + arr[n - a];
//     else if (n >= b)
//         return 1 + arr[n - b];
//     else 
//         return 1 + arr[n - c];
// }


// int con=1e5;

// int m(int n,int a,int b,int c){
//         if(n<0)
//         return con*-1;



//         if(n==0)
//         return 0;
        




//         if(n>=a && arr[n-a]==con)
//         arr[n-a]=m(n-a,a,b,c);
//         if(n>=b && arr[n-b]==con)
//         arr[n-b]=m(n-b,a,b,c);
//         if(n>=c && arr[n-c]==con)
//         arr[n-c]=m(n-c,a,b,c);


//     if (n >= a && n >= b && n >= c)
//         return 1 + max(arr[n - a], max(arr[n - b], arr[n - c]));
//     else if (n >= a && n >= b)
//         return 1 + max(arr[n - a], arr[n - b]);
//     else if (n >= b && n >= c)
//         return 1 + max(arr[n - b], arr[n - c]);
//     else if (n >= a && n >= c)
//         return 1 + max(arr[n - a], arr[n - c]);
//     else if (n >= a)
//         return 1 + arr[n - a];
//     else if (n >= b)
//         return 1 + arr[n - b];
//     else 
//         return 1 + arr[n - c];
// }














void solve()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> arr(4001,-700000);
    arr[0]=0;
    arr[a]=1;
    arr[b]=1;
    arr[c]=1;
    for(int i=1;i<=n;i++){
        if(i-c>=0 && i-b>=0 && i-a>=0)
        arr[i]=1+max(arr[i-c],max(arr[i-a],arr[i-b]));
        else if(i-c>=0 && i-b>=0)
        arr[i]=1+max(arr[i-c],arr[i-b]);
        else if(i-b>=0 && i-a>=0)
        arr[i]=1+max(arr[i-a],arr[i-b]);
        else if(i-a>=0 && i-c>=0)
        arr[i]=1+max(arr[i-a],arr[i-c]);
        else if(i-a>=0 && arr[i-a]!=-1)
        arr[i]=1+arr[i-a];
        else if(i-b>=0 && arr[i-b]!=-1)
        arr[i]=1+arr[i-b];
        else if(i-c>=0 && arr[i-c]!=-1)
        arr[i]=1+arr[i-c];
    }
    // debug(arr[25])
    cout<<arr[n];
}
