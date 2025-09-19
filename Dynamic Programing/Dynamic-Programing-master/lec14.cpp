// Subset Sum Equals to Target
// https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/
// Revision Status : 1


#include<bits/stdc++.h>
using namespace std;


int subset(vector<int> arr, int n , int target ){
    vector<vector<int>> dp(n,vector<int>(target+1,false));
    if(arr[0]<=target)  // agr hum index 0 pr agye or arr[0] equal hai target k to usko mark krdo 
        dp[0][arr[0]] = true;
    for(int i=0;i<n;i++) dp[i][0]=true;
    
    int notpick= subset(arr,n-1,target);
    int pick=false;
    if(arr[n]<=target) 
     pick=subset(arr,n-1,target-arr[n]);
    return(pick||notpick);
}




// recursive solution

bool f(int n ,int target, vector<int > arr){
    
    if(n==0) return arr[n]==target;
    if(target==0) return true;

    bool notpick = f(n-1,target,arr);
    bool pick=false;
    if(arr[n]<=target) pick = f(n-1,target-arr[n],arr);

    return pick||notpick;
}

// memoization 

// LFQ :- Changing parameters ka dp array bnate hai  isme index or target hai  
//        unke nested loop lagenge jo chnging hai tabulation mai

int f(int n , int target, vector<int> arr , vector<vector<bool>> dp){

   if(n==0) return arr[n]==target;
   if(target==0) return true;
   if(dp[n][target]!=-1) return dp[n][target];
   bool notpick = f(n-1,target,arr,dp);
   bool pick=false;
   if(arr[n]<=target) pick = f(n-1,target-1,arr,dp);
   return dp[n][target] = pick||notpick;
}

// tabulation 

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    // if(arr[0]<=k)  // agr hum index 0 pr agye or arr[0] equal hai target k to usko mark krdo 
    //     dp[0][arr[0]] = true;

        for(int i =0 ;i<=k;i++){
            dp[0][i]=true;
        }
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
            
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
                
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
}


// Space optimization

int so(int n ,int k ,vector<int> &arr){
    vector<bool> prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;    // sare target zero wale ko true mark krnge
    prev[arr[0]]=true;       // 
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = prev[target];
            
            bool taken = false;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
                
            curr[target]= notTaken||taken;
        }
        prev=curr;
    }
    
    return prev[k];
}


int main(){
      vector<int> arr = {1,2,3,4};
      int k=4;
      int n = arr.size();
      vector<vector<bool>> dp(n,vector<bool>(k+1,false));
      cout<<subsetSumToK(n,k,arr);

    return 0;
}