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
ll bs(vector<pair<ll, ll>> &arr, ll target);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
    // vector<pair<ll,ll>> arr={mp(1LL,0LL),{4LL,0LL},{5LL,0LL}};
    // ll target=1;
    // cout<<bs(arr,target);
}
ll bs(vector<ll> &arr, ll target)
{
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        if(r - l <= 2)
            break;
        int mid = (l + r) / 2;
        ll m1 = arr[mid];
        if (m1 == target)
            return 0;
        else if (target < m1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n, 0);
        vector<ll> b(n, 0);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        ll x1=INF;
        ll x2=INF;
        ll x3=INF;
        ll x4=INF;
        for(ll i=0;i<n;i++)
        x1=min(x1,abs(b[i]-a[0]));
        for(ll i=0;i<n;i++)
        x2=min(x2,abs(b[i]-a[n-1]));
        for(ll i=0;i<n;i++)
        x3=min(x3,abs(a[i]-b[0]));
        for(ll i=0;i<n;i++)
        x4=min(x4,abs(a[i]-b[n-1]));
        ll x5=abs(a[0]-b[0]);
        ll x6=abs(a[n-1]-b[n-1]);
        ll x7=abs(a[0]-b[n-1]);
        ll x8=abs(b[0]-a[n-1]);
        //   cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<x5<<" "<<x6<<" "<<x7<<" "<<x8<<"\n";
        ll ans=min(x5+x6,x7+x8);
        ans=min(ans,x1+x2+x3+x4);
    //   cout<<x1+x2+x3+x4<<"\n";
        ans=min(ans,min(x5+x2+x4,min(x6+x1+x3,min(x7+x2+x3,x8+x1+x4))));
        
        cout << ans << "\n";
    }
}
