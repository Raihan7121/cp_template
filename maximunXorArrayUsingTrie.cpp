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

struct Node
{
    Node *links[2];
    bool containskey(int bit){
        return (links[bit] != NULL);
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie {
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=3;i>=0;i--){
            int bit=num&(1ll<<i);
            if(!node->containskey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    
    int getMax(int num){
        Node* node= root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=num*(1ll<<i);
            if(node->containskey(1-  bit)){
                maxNum = maxNum | (1<<i); 
                node = node->get(!bit); 
            } else {
                node = node->get(bit); 
            }
        }
        return maxNum; 
    }
   
    
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie; 
    for(int i = 0;i<n;i++) {
        trie.insert(arr1[i]); 
    }
    int maxi = 0;
    for(int i = 0;i<m;i++) {
        maxi = max(maxi, trie.getMax(arr2[i])); 
    }
    return maxi; 
}



void rai()
{  
  int f=1,n;
//long long ans=0;
    Trie trie;
    string s,s1,s2;
    cin>>s>>s1;
    //trie.insert(s);
    //cout<<trie.search(s1)<<endl;
    //cout<<trie.startsWith(s1)<<endl;
    //cout<<trie.countDistinctSubstring(s1)<<endl;
   
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