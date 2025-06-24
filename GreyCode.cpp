#include<bits/stdc++.h>
using namespace std;

vector<int> greyCode(int n){
    vector<int> ans;
    ans.push_back(0);
    for(int i=0;i<n;i++){
        int size = ans.size();
        for(int j = size-1;j>=0;j--){
            ans.push_back(ans[j] | (1 << i));
        }
    }
    return ans;
}

int main(){
    int n = 2;
    vector<int> ans = greyCode(n);
    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}