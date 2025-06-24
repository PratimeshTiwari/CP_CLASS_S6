/*
You are given an array: arr = [1, 2, 3, 4, 5]
You're allowed to insert any combination of +, -, and * between the numbers in order.
Your goal is to check: Can these operations result in a final value of 23?
*/
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>& vec,int ind,int curr){
    if(i==vec.size()){
        if(curr==23){
            return true;
        }
        return false;
    }
    return solve(vec,ind+1,curr+vec[ind]) || solve(vec,ind+1,curr-vec[ind]) 
    || solve(vec,ind+1,curr*vec[ind]);
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    return solve(vec,1,vec[0]);
}