/*
Find all twin prime number under n
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> allPrimeSeive(int n){
    vector<bool> isPrime(n+1,false);
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return isPrime;
}

vector<pair<int,int>> twinPrime(vector<bool>& isPrime,int n){
    vector<pair<int,int>> ans;
    for(int i=2;i<=n;i+=2){
        if(isPrime[i] && isPrime[i+2]){
            ans.push_back({i,i+2});
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> isPrime = allPrimeSeive(n);
}