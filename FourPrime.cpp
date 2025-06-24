/*
Now find all four prime number under n
and it is define as n = a+b+c+d and a,b,c,d are prime.
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

vector<int> FourPrime(vector<bool>& isPrime,int n){
    if(n<8){
        return {-1};
    }
    if(!(n%2)){
        for(int i=0,i<=(n-4)/2;i++){
            if(isPrime[i] && isPrime[n-4-i]){
                return {2,2,i,n-4-i};
            } 
        }
    }else{
        for(int i=0,i<=(n-4)/2;i++){
            if(isPrime[i] && isPrime[n-5-i]){
                return {3,2,i,n-5-i};
            } 
        }
    }
    return {-1};
}

int main(){
    int n;
    cin>>n;
    vector<bool> isPrime = allPrimeSeive(n);
}