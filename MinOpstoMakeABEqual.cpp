//min ops to make a and b equal , condition = divide by prime numbers only 

//gpt code 
int countPrimeOperations(int n) {
    int count = 0;
    for (int p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            count++;
            n /= p;
        }
    }
    if (n > 1) count++; 
    return count;
}

int minOperationsToEqual(int a, int b) {
    if (a == b) return 0;
    int g = gcd(a, b);
    return countPrimeOperations(a / g) + countPrimeOperations(b / g);
}


//sir code , finding prime factors 
map<int,int> mp;
for(int i=2;i<=n;i++){
    while(n%i==0){
        mp[i]++;
        n/=i;
    }
}