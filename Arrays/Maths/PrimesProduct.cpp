/*Given two numbers L and R (inclusive) find the product of primes within this range. 
  Print the product modulo 10 9 + 7 . If there are no primes in that range you must print 1 .*/

#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e6;


vector<int> getPrimes() {
	//Mark isPrime for all the multiples of prime numbers as false
    vector<bool> isPrime(N + 1, true);
    for (int i = 2; i * i <= N; i++){
        if (isPrime[i]){
            for (int j = i; j * i <= N; j++){
                isPrime[i * j] = false;
            }
        }
    }
 
	//Pushing into primes all the prime numbers uptil N
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<int> primes = getPrimes();
 
    int t;
    cin >> t;
 
    while (t--) {
        int l, r;
        cin >> l >> r;
 
        vector<bool> isPrime(r - l + 1, true);
        for (int i = 0; i < primes.size(); i++) {
			//Find the first multiple of prime number within [L,R]
            int k = ceil((1.0 * l) / primes[i]);
            for (int j = max(k, 2LL); primes[i] * j <= r; j++) {
                isPrime[primes[i] * j - l] = false;
            }
        }
 
        int product = 1;
        for (int i = 0; i <= r - l; i++) {
            if (isPrime[i]) {
                product = ((product % MOD) * ((i + l) % MOD)) % MOD;
            }
        }
 
        cout << product << endl;
    }
 
    return 0;
}
