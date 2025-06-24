#include<bits/stdc++.h>
 
using namespace std;
 
int m = 5;
int n = 4;

void calculateDistance(vector<vector<char>> &arr,vector<vector<int>> &distance,int catX,int catY){
    queue<pair<int,int>> q;
    q.push({catX,catY});
    distance[catX][catY] = 0;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nr = x + dx[i];
            int nc = y + dy[i];
            if(nr >= 0 and nr < m and nc >= 0 and nc < n and arr[nr][nc] == 'L' and distance[nr][nc] > 1 + distance[x][y]){
                distance[nr][nc] = 1 + distance[x][y];
                q.push({nr, nc});
            }
        }
    }
}

string getPath(vector<vector<char>> &arr,vector<vector<int>> &distance){

}


int main(){
    
    vector<vector<char>> arr = {
        {'L','L','L','W'},
        {'S','W','L','L'},
        {'L','W','C','L'},
        {'L','W','L','L'},
        {'L','L','L','E'},
    };

    int catX = 2;
    int catY = 2;

    
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    calculateDistance(arr,distance,catX,catY);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    string path = getPath(arr, distance);
    cout << "Path: " << path << endl;

    return 0;
}