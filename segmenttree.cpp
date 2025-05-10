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
int a[N],tree[4*N];
void build(int node, int st,int ed){
    if(st==ed){
        tree[node]=a[st];
        return;
    }
    int mid=(st+ed)/2;
    build(2*node+1,st,mid);
    build(2*node+2,mid+1,ed);
    tree[node] = tree[2*node+1]+tree[2*node+2];

}
int query(int node ,int st,int en,int l,int r){
    if(st>r || en<l){
       return 0; 
    }
    if(l<=st && en<=r){
        return tree[node];
    }
     int mid=(st+en)/2;
     int q1 = query(2*node+1,st,mid,l,r);
      int q2 = query(2*node+2,mid+1,en,l,r);
      return q1+q2;
}
void update(int node,int st,int en,int pos, int diff){
    if(st>pos || en<pos) return;
    tree[node]+=diff;
    if(st!=en){
        int mid=(st+en)/2;
        update(2*node+1,st,mid,pos,diff);
        update(2*node+2,mid+1,en,pos,diff);
    }
}
void rai()
{  
  int f=1,n;cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
//long long ans=0;
    build(0,0,n-1);
    for(int i=0;i<15;i++){
       // cout<<tree[i]<<" ";
    }
    int d=10-5;
    a[0]=10;
    update(0,0,n-1,0,5);
    cout<<endl;
    int l,r;cin>>l>>r;
    int ans= query(0,0,n-1,l,r);
      cout<<ans<<endl;

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