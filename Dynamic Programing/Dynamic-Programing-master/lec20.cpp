// minimum coins 
// https://takeuforward.org/data-structure/minimum-coins-dp-20/

// Revision Status : 1

#include<bits/stdc++.h>
using namespace std;

// Recursive

int f(int n , int T, vector<int> &nums){

    if(n==0){
        if(T%nums[0]==0) return T/nums[0];
        return 1e9;
    }

    int notTake = 0 + f(n-1,T,nums);
    int take = INT_MIN;
    if(nums[n]<=T)
       take = 1 + f(n-1,T-nums[n],nums);
    return min(notTake,take);
}

// tabulation 

int takingcoin(vector<int> arr, int T, int n ){
    // if(n==0){
    //    if(T%arr[n]==0) return T/arr[n];
    //    else return 1e9;
    // }

    vector<vector<int>> dp(n,vector<int>(T+1,-1));

    for(int i =0;i<=T;i++){
        if(i%arr[0]==0) dp[0][i]=i/arr[0];
        else dp[0][i]=1e9;
    }
    
    for(int i =1;i<n;i++){
        for(int j =1;j<=T;j++){
           int notpick= dp[i-1][j]+0;
           int pick=arr[0];
            if(j>=arr[i]) 
            pick=dp[i-1][j-arr[i]]+1;
            dp[i][j] = max(pick,notpick);
        }
    }

     return dp[n-1][T]; 
     }
      

int f(int n , int target, vector<int> &nums){

    vector<vector<int>> dp(n, vector<int>(target+1,0));

    for(int T=0;T<=target;T++){
         if(T%nums[0]==0) dp[0][T]=T/nums[0];
         else dp[0][T]=1e9;
    }
 
    for(int i = 1;i<n;i++){
        for(int T=0;T<=target;T++){
            int notTake = 0 + dp[i-1][T];
            int take = INT_MIN;
            if(nums[i]<=T)
            take = 1 + dp[i-1][T-nums[i]];
            dp[i][T] = max(notTake,take);
        }   
    }

    return dp[n-1][target];  
}
