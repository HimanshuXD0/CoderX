// Count Subsets with Sum K 
// https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/

// Revision Status : 1

#include<bits/stdc++.h>
using namespace std;

// Recursive

int f(int n ,int target, vector<int > arr){
    
    if(n==0) return arr[n]==target;
    if(target==0) return 1;

    int notpick = f(n-1,target,arr);
    int pick=0;
    if(arr[n]<=target) pick = f(n-1,target-arr[n],arr);

    return pick+notpick;
}

int main(){
     vector<int> arr = {1,2,3,4};
      int k=4;
      int n = arr.size();
      vector<vector<bool>> dp(n,vector<bool>(k+1,false));
      cout<<f(n,k,arr);

    return 0;
}