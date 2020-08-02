

// Get a vector with primes
vector<ll> prime;
void calcPrime(long long m) {
    memset(isNotPrime, 0, sizeof(isNotPrime));
    for (int i = 2; i <= m; i++) {
        if (isNotPrime[i] == false) {
            prime.push_back(i);
            ll x = i + i;
            while (x <= m) {
                isNotPrime[x] = true;
                x+=i;
            }
        }
    } 
}

// decompose prime: 
// The array stores a factor for each number.
// Use the array to decompose prime factors
int p[N];
void init()
{
    for(int i=2;i<N;i++)
        if(p[i]==0){
            p[i]=i;
            for(int j=i+i;j<N;j+=i)
                if(!p[j])
                    p[j]=i;
        }
}