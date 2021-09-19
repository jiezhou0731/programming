// Get a vector with primes
const int MM = 3*pow(10,5) + 20;
vector<ll> prime;
bool isNotPrime[MM + 20];
void calcPrime() {
    memset(isNotPrime, false, sizeof(isNotPrime));
    for (int i = 2; i < MM; i++) {
        if (isNotPrime[i] == false) {
            prime.push_back(i);
            ll x = i + i;
            while (x <= MM) {
                isNotPrime[x] = true;
                x+=i;
            }
        }
    } 
}



bool isPrime(int x) {
    for(ll  i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return true;
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

