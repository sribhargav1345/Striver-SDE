void sieve(int n)
{
    vector<bool> v(n+1,true);
    v[0] = false;
    v[1] = false;

    for(int i=2;i*i<=n;i++)
    {
        if(v[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                v[i] = false;
            }
        }
    }
    return v;
}

void sieveOfEratosthenes(int n, std::vector<bool>& primes) {
    primes.assign(n + 1, true);
    primes[0] = primes[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
       }
    }
}