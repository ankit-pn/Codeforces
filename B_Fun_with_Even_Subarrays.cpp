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
// int so1(vector<ll> arr,int n){
//          int k = 1;
//         int in = arr[0];
//         int i = 1;
//         int c = 0;
//         if(n>1  && arr[1]!=in)
//         c++;
//         while (i < n)
//         {
//             int d = (k * k)+1;
//             // i=d-1;

//             // 4 2 4 4 4
//             //
//             //  1

//             // 0
//             while (i < d && i < n)
//             {
//                 if (arr[i] != in)
//                 {
//                     i = d ;
//                     c++;
//                     continue;
//                 }
//                 else 
//                 i++;
//             }
//             k++;
//         }
//         return c;
// }
int so(vector<ll> arr,ll n){
         ll k = 2;
        ll in = arr[0];
        ll i = 2;
        ll c = 0;
        if(n>1  && arr[1]!=in)
        c++;
        while (i < n)
        {
            ll d = k * k;
            // i=d-1;

            // 4 2 4 4 4
            //
            //  1

            // 0
            while (i < d && i < n)
            {
                if (arr[i] != in)
                {
                    i = d ;
                    c++;
                    continue;
                }
                else 
                i++;
            }
            k++;
        }
        return c;
}
void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        // if(n%2==1)
        // n--;
        vector<ll> temp;

        reverse(arr.begin(), arr.end());
        for(ll i=1;i<n;i++)
        temp.push_back(arr[i]);
        // int k = 2;
        // int in = arr[0];
        // int i = 2;
        // int c = 0;
        // if(n>1  && arr[1]!=in)
        // c++;
        // while (i < n)
        // {
        //     int d = k * k;
        //     // i=d-1;

        //     // 4 2 4 4 4
        //     //
        //     //  1

        //     // 0
        //     while (i < d && i < n)
        //     {
        //         if (arr[i] != in)
        //         {
        //             i = d ;
        //             c++;
        //             continue;
        //         }
        //         else 
        //         i++;
        //     }
        //     k++;
        // }
        // cout << c << nline;
        if(n==1)
        cout<<0<<nline;
        else if(n==2){
            if(arr[0]==arr[1])
            cout<<0<<nline;
            else
            cout<<1<<nline;
        }
        else
        cout<<min(so(arr,n),so(temp,n-1))<<nline;
        
    }
}
