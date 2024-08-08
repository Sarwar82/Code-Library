const int N = 200005, mod = 1000000007;
int fact[N];
int bigmod(int a, int b)
{
    if(b == 0) return 1;
    int x = bigmod(a, b / 2);
    x = (1ll * x * x) % mod;
    if(b & 1) x = (1ll * x * a) % mod;
    return x;
}
 
int inv(int a, int m)
{
    return bigmod(a, mod - 2);
}
 
int nCr(int n, int r)
{
    if(n < r) return 0;
    int x = fact[n], y = (1ll * fact[r] * fact[n - r]) % mod;
    int ans = (1ll * x * (inv(y, mod))) % mod;
    return ans;
}
 
void calc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = (1ll * fact[i - 1] * i) % mod;
}
