// 0/1 Knapsack
// https://takeuforward.org/data-structure/0-1-knapsack-dp-19/

// Revision Status : 1

#include<bits/stdc++.h>
using namespace std;

// Recursive

 int f(int W, int wt[], int val[], int n ){
        
        if(n==0)
        {  if(wt[0]<=W) return val[0];
           else  return 0;
        }
        int notpick = 0+f(W,wt,val,n-1);
        int pick=INT_MIN;
        if(wt[n]<=W)
         pick = val[n]+f(W-wt[n],wt,val,n-1);
        
        return max(pick,notpick);
    }

// tabulation 

int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int>(W+1,0));
           
         for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
         
         for(int i=1;i<n;i++){
             for(int cap=0;cap<=W;cap++){
                 
                int notpick = 0+dp[i-1][cap];
                int pick=INT_MIN;
                if(wt[i]<=cap)
                pick = val[i]+dp[i-1][cap-wt[i]];
                dp[i][cap]=max(pick,notpick);
             }
         }
        
        
        return dp[n-1][W];
    }


// Space optimization 

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0),curr(W + 1, 0);

    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTake  = 0 + prev[cap];
            int take = INT_MIN;

            if (wt[ind] <= cap) {
                take = val[ind] + prev[cap - wt[ind]];
            }
            curr[cap] = max(notTake, take);
        }
    }
     prev = curr;

    return prev[W];
}

    
    int main(){
        
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << knapsack(wt, val, n, W);

        return 0;
    }