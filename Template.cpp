const long long N=998244353;
vector <int> prims={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
long long ncr(int n,int r)
{
    long long ans=1,a,b;
    map<long,long>mp;
    if(n<r || r<0)return 0; 
    r=min(r,n-r);
    for(int i=1;i<=r;i++){
        a=n;b=i; n--;  
        for(auto x:prims){
            while (!(a%x) && a>1){ a/=x; mp[x]++; }
            while (!(b%x) && b>1){ b/=x; mp[x]--; }       
        }          
    }
    for(auto x:prims){
            a=mp[x];
            while (a--){ ans=(ans*x)%N; }           
         }
    return ans%N;  
}

long long mod;

 long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int a_b_divide_mod(int a,int b)
{
    int ans=binpow(b,mod-2);
    ans=((ans%mod)*(a%mod))%mod;
    return ans;
}
