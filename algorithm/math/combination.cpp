
ll C( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;
 
    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result = result * (n-i+1) % MOD;  
    }
    for( int i = 2; i <= k; ++i ) {
        result = modDivide(result, i, MOD);
    }
    
    
    return result;
}



// C function for extended Euclidean Algorithm 
long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    long long x1, y1; 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
 
  
// Function to find modulo inverse of b. 
long long modInverse(long long b, long long m) 
{ 
    long long x, y; 
    long long g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
long long modDivide(long long a, long long b, long long m) 
{ 
    a = a % m; 
    return (a * modInverse(b, m)) % m; 
} 



/*
    Calculate C(a,b)
*/
ll fact[300505];
ll n, m , t, k,x,y,z,d,f;
vector<pair<ll,ll>> a;
ll pw(ll a,ll b){
    if(!b)return 1ll;
    if(b&1)return (a*pw(a,b-1))%MOD;
    ll x=pw(a,b>>1ll);
    return (x*x)%MOD;
}
ll C(ll n,ll k){
    if(n < k) return 0;
    return (fact[n]*pw((fact[n-k]*fact[k])%MOD,MOD-2))%MOD;
}
int main() {
    memset(fact, 0, sizeof(fact));
    fact[0]=1;
    for(ll i=1;i<300005;i++)fact[i]=(fact[i-1]*i)%MOD;

  
}

