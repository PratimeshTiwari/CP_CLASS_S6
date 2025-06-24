/*
You are given an integer n. Your task is to analyze every prime number less than or equal
to n, and for each such prime number p, determine the maximum number of queries you can
ask to guess a number between 1 and n, given that the secret number is divisible by p.
Each query can ask:
“Is the number divisible by 𝑝^𝑘?”
You must determine, for each prime 𝑝 ≤ 𝑛, the maximum integer 𝑘 such that:
𝑝^𝑘 ≤ 𝑛
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
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            ans.push_back(i);
        }
    }
    return ans;
}

unordered_map<int,int> solve(int n){
    vector<int> range = allPrimeSeive(n);
    unordered_map<int,int> mpp;
    for(auto it: range){
        int question = 0;
        int temp = n;
        while(temp!=0 || temp!=1){
            temp/=it;
            question+=1;
        }
        mpp[it] = question;
    }
    return mpp;
}

int main(){
    int n = 10;
    unordered_map<int,int> mpp = solve(n);
    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}