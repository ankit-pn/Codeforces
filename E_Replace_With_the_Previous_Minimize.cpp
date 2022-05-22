#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void solve();
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
fastio();
     solve() ;  
}
void solve(){
        int t;
        cin>>t;
        while(t--){
         int n,k;
         cin>>n>>k;
         string s;
         cin>>s;
         int szz=s.length();
         int q=0;
         int m=-1;
         for(int i=0;i<szz;i++){
                int x=s[i]-'a';
                q=max(q,x);
                if()
         }     

        //  cout<<q<<"\n"; 
         int f=0;
         if(k>=q){
             for(int i=0;i<szz;i++)
             s[i]='a';
             f=1;
         }   
         if(f){
             cout<<s<<"\n";
             continue;
         }

        //  int temp = INT_MIN , tempIndex = -1;
        //  for(int i=0;i<n;i++){
        //      if(s[i]-'a' <= k ){
        //          s[i]='a';
        //          k-=(s[i]-'a');
                // temp = s[i] - 'a';
                // tempIndex = i;
                // cout<<"k "<<k<<"\n";
            //  }
            //  else
            //  break;
        //  }
        //  for(int i = 0 ; i < n ; ++i){
        //      if(s[i] - 'a' <= temp){
        //          s[i] = 'a';
        //      }
        //  }
        //  if(temp >= 0)
        //  k -= temp;

        // tempIndex = max(tempIndex+1 , 0);

        //  cout<<temp<<' '<<tempIndex<<endl;
        // int m=-1;
        // for(int i=0;i<n;i++){
        //     if(s[i])
        // }
         for(int i=0;i<szz;i++){
             
            while(s[i]!='a' && k>0){
                int x=s[i];
            for(int j=0;j<szz;j++){
                if(s[j]==x)
                s[j]--;
            }
            k--;
            }
            if(k==0)
            break;
         }   
         cout<<s<<"\n";
        }
}
