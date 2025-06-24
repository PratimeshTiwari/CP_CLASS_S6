/*
Given an integer array of size N, indexed from 0 to N-1, there will be Q queries given
containing a range [L, R] inclusive such that L and R are valid indices and L <= R. For
each query, you have to choose 1 subset of indices in range [L, R] and subtract 1 from
array values at selected indices in subset. An array is called  such that A[i] = 0
where 0 <= i <= N-1 after Q operations. Implement a function to check whether it is
possible to make array a  or not after performing given Q operations.
*/
#include <bits/stdc++.h>
using namespace std;

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries, int size){
    // Difference Array
    int n = nums.size();
    vector<int> diff(n + 1, 0);
    for (int i = 0; i <= size; i++){
        int l = queries[i][0];
        int r = it[i][1];
        diff[l] += 1;
        if (r + 1 < n)
        {
            diff[r + 1] -= 1;
        }
    }
    int prefix = 0;
    for (int i = 0; i < n; i++){
        prefix += diff[i];
        if (prefix < nums[i]){
            return false;
        }
    }
    return true;
}

int minIndexToZeroArray(vector<int> &nums, vector<vector<int>> &queries){
    int low = 0, high = queries.size() - 1;
    int answer = -1;

    while (low <= high){
        int mid = (low + high) / 2;
        if (canMakeZero(nums, queries, mid)){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return answer;
}