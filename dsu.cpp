#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);cerr << '}';}

void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "Line(" << __LINE__ << "): [" << #x << "] = ["; _print(x)

const int N=1e5+10;
int parent[N];
void makes(int v){
    parent[v]=v;
    }
int finds(int v){
    if(v== parent[v])return v;
    return parent[v]=finds(parent[v]);
}
void unions(int a,int b){
    a=finds(a);
    b=finds(b);
    if(a!=b){
        parent[b]=a;
    }
}
void rai()
{  
  int f=1,n;
//long long ans=0;

   
      //cout<<ans<<endl;
 //cout<<(f?"YES":"NO")<<endl;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
     // cout<<"hello";
    int t=1;
        //cin>>t;
        for (int tt = 1; tt <= t; tt++) {
        //  cout<<"Case "<<tt<<':'<<' ';
              rai(); 
        }
  return 0;  
}