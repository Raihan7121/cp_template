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
    Node *links[26];
    bool flag =false;
    int cntEndWith=0;
    int cntPrefix=0;
    bool containskey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag=true;
    }
    bool isEnd(){
       return flag; 
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){ 
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie {
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
    
    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
           if(node->containskey(word[i])) {
            node=node->get(word[i]);
           }
           else return 0;
        }
        node->getEnd();
    }

    int countWordStringWith(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
           if(node->containskey(word[i])) {
            node=node->get(word[i]);
           }
           else return 0;
        }
        return node->getPrefix();
    }
    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
           if(node->containskey(word[i])) {
            node=node->get(word[i]);
            node->reducePrefix();
           }
           else return;
        }
         node->deleteEnd();
    }

    int countDistinctSubstring(string &word){
        int cnt=0;
        for(int i=0;i<word.size();i++){
            Node* node = root;
            for(int j=i;j<word.size();j++){
                if(!node->containskey(word[j])){
                    cnt++;
                    node->put(word[j],new Node());
                }
                node=node->get(word[j]);
            }
        }
        return cnt+1;  //1 for empty string
        
    }
    
};



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
    cout<<trie.countDistinctSubstring(s1)<<endl;
   
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