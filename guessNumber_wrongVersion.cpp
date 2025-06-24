// >I m given a number n , i have guess k , return 
// the min no of queries for finding k , k can change 
// anytime during the question.

#include <bits/stdc++.h>
using namespace std;

int n;  // Upper limit
set<int> candidates;  // Current possible values of k

// Sieve to get primes up to n
vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

// Simulated user function with changeable k
int k_real;  // Hidden value
bool ask(int x) {
    return k_real % x == 0;
}

// Ask same query 3 times to detect lie
bool reliableAsk(int x) {
    int count = 0;
    for(int i = 0; i < 3; ++i) {
        if(ask(x)) count++;
        // simulate adversary: k_real might change here
        // e.g., randomly change k_real to another value in candidates
    }
    return count >= 2;  // Majority rule
}

// Main solver
int findK(int n) {
    vector<int> primes = sieve(n);
    candidates.clear();
    for(int i = 1; i <= n; ++i) candidates.insert(i);

    for(int p : primes) {
        bool divisible = reliableAsk(p);

        set<int> next;
        for(int val : candidates) {
            if(divisible && val % p == 0) next.insert(val);
            if(!divisible && val % p != 0) next.insert(val);
        }

        candidates = next;

        if(candidates.size() == 1)
            break;
    }

    if(candidates.size() == 1)
        return *candidates.begin();
    return -1;
}

// Driver
int main() {
    cout << "Enter n: ";
    cin >> n;

    srand(time(0));
    
    // Set some initial value of k_real
    cin >> k_real;

    int found = findK(n);
    cout << "Guessed k = " << found << endl;
}