

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
