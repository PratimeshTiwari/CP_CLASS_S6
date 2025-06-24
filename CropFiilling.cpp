#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& grid,vector<int> crop,int n,int m){
    bool flag = true;
    int r = 0;
    for(int i=0;i<crop.size();i++){
        int c = crop[i];
        while(c--){
            if(flag){
            for(int i=0;i<n;i++){
                grid[r][i] = crop[i];
            }
        }else{
            for(int i=n-1;i>=0;i--){
                grid[r][i] = crop[i];
            }
        }
        flag!=flag;
        r+=1;
        }
    }
}

int main(){
    int n = 5,m = 4;
    vector<vector<int>> grid(n,vector<int>(m));
    vector<int> crop = {2,3,4,5,6};
    solve(grid,crop,n,m);
    
}