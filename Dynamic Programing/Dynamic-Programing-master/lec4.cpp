// frog can jump b/w 1 to k 
//https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
// Resvision status = 2
// DAY -----4 
#include<bits/stdc++.h>
using namespace std;

// recursive 

int frogJumpAtk(int n,int k, int *arr){
    
      if(n==0) return 0;
      int mmjump = INT_MAX;
      for(int j=1;j<=k;j++){
        if(n-j>=0){
        int jump = frogJumpAtk(n-j,k,arr)+abs(arr[n]-arr[n-j]);
         mmjump = min(mmjump,jump);}
      }
      return mmjump;
      
}

// memoization

int frogJumpAtkM(int n,int k,int *arr,vector<int>dp){
   if(n==0) return 0;
    int mmjump = INT_MAX;
    if(dp[n]!=-1) return dp[n];
   for(int j=1;j<=k;j++){
        if(n-j>=0){
        int jump = frogJumpAtkM(n-j,k,arr,dp)+abs(arr[n]-arr[n-j]);
         mmjump = min(mmjump,jump);}
      }

      dp[n]=mmjump;

}

// tabulation

int frogJumpAtkT(int n, int k, int *height, vector<int> dp){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}


int main(){
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> dp(n,-1);
    int arr[n];
    
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0;
    ans=frogJumpAtkT(n-1,k,arr,dp);
    cout<<ans;
    return 0;
}