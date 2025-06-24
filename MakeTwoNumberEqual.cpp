/*
You have two numbers and you have to make it equal by dividing and the divisior should 
be a prime number. Return the minimum number of operation to make them equal.
*/
#include <bits/stdc++.h>
using namespace std;
void countPrimeDivisions(int n, int g,unordered_map<int,int>& mpp) {
    for (int p = 2; p * p <= n; ++p) {
        while (n % p == 0 && g % p != 0) {
            if(mpp.find(p)!=mpp.end()){
                mpp[p]--;
                if(mpp[p]==0){mpp.erase(p);}
            }else{
                mpp[p]++;
            }
            n /= p;
        }
    }
}

int minOperationsToEqual(int a, int b) {
    int g = __gcd(a, b);
    unordered_map<int,int> mpp;
    countPrimeDivisions(a, g,mpp);
    countPrimeDivisions(b, g,mpp);
    int ans = 0;
    for(auto it: mpp){
        ans+=it.second;
    }
    return ans;
}
