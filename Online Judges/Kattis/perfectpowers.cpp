/*
 * https://open.kattis.com/problems/perfectpowers
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000010
long long int _sieve_size;
bitset<MAX_N> pFlags;
long long int spf[MAX_N]; // smallest pf of numbers
vector<long long int> PF;

void sieve(long long int upperbound){
    _sieve_size = upperbound + 1;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
        spf[q] = 2;
    }
    PF.push_back(2);
    for(long long int p = 3; p <= _sieve_size; p += 2){ // constraint can be p * p <= _sieve_size if we don't need to calc PF
        if(pFlags[p]){
            spf[p] = p;
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                    spf[q] = p;
                }
            }
            PF.push_back(p);
        }
    }
}


long long int primeFactors(long long int N) { // and also sumPF
    long long int PF_idx = 0, primefactor = PF[PF_idx], res = 0;
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        if(N % primefactor == 0){
            long long int power = 0;
            while (N % primefactor == 0){
                N /= primefactor; // remove PF
                power++;
            }
            if(res == 0)
                res = power;
            else
                res = __gcd(res, power);
        }
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        return 1; // special case if N is a prime
    return res;
}
long long int n;
int main()
{
    sieve(10000000);
    long long int ans;
    while(cin >> n && n){
        if(n < 0){
            ans = primeFactors(-n);
            while(!(ans%2))
                ans /= 2;
            cout << ans << endl;
        }
        else{
            cout << primeFactors(n) << endl;
        }
    }
    return 0;
}

