// compute (a * b) % mod
long long mul(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    long long t = mul(a, b / 2, mod);
    t = (t + t) % mod;
    if (b % 2 == 1) t = (t + a) % mod;
    return t;
}
 
// compute (x ^ k) % mod
long long power(long long x, long long k, long long mod) {
    if (k == 0) return 1;
    long long t = power(x, k / 2, mod);
    t = mul(t, t, mod);
    if (k % 2 == 1) t = mul(t, x, mod);
    return t;      
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


cout << std::fixed << std::setprecision(6);