#include<bits/stdc++.h>
using namespace std;

vector<int> previousGreaterElement(vector<int>& vec){
    int n = vec.size();
    stack<int> greater;
    vector<int> ans(n);
    ans[0] = 0;
    greater.push(0);
    int poped = 0;
    for(int i=1;i<n;i++){
        while(!greater.empty() && vec[greater.top()]<vec[i]){
            greater.pop();
            poped+=1;
        }
        if(greater.empty()){
            ans[i] = poped;
            greater.push(i);
            poped=0;
        } 
        else if(vec[greater.top()]>=vec[i]){
            int range = (i - greater.top()) - 1 +greater.size();
            ans[i] = range;
            greater.push(i);
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {1,10,6,7,9,8,2,4,3,5};
    vector<int> ans = previousGreaterElement(vec);
    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;
}