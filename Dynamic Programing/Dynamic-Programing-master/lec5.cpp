//  Maximum sum of non-adjacent elements (DP 5)
// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
// Revision Status = 2
// DAY ----- 5
#include<bits/stdc++.h>
using namespace std;

// recursive
// lFQ :- hum mainly zero idx ka base case find krnge (idx<0) k liye condition lga k kam kr lenge
int solve(int n,vector<int>arr){
	    
	    if(n==0) return arr[n];  // agr hum 0 pr aye hai mtlb humne 1 ko choda hai ..to 0 ko consider krnge 
	    //f(n<0) return 0;
	    int notpick = 0+solve(n-1,arr); // pick nhi kiya to n-1 pe ja skte hai 
        int pick=INT_MIN;
        if(n>1)
	    pick = arr[n]+solve(n-2,arr); // kiya hai to n-2 pe jana pdega no adjacent lene hai 
	    return max(pick,notpick);
	}


int sumna(vector<int> arr , int n ){
    if(n==0) return arr[0];
    int ;

}

 // memoization

 int solve(int ind, vector<int>& arr, vector<int>& dp){
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(ind==0) return arr[ind];
    if(ind<0)  return 0;
    
    int nonPick = 0 + solve(ind-1, arr, dp);
    int pick= arr[ind]+ solve(ind-2, arr,dp);
    
    return dp[ind]=max(pick, nonPick);
}

//tabulation

int solveUtil(int n, vector<int>&arr){
     vector<int> dp(n,-1);
     dp[0]= arr[0];
    
      for(int i=1 ;i<n; i++){
        int nonPick = 0+ dp[i-1];
        int pick = arr[i];
        
        if(i>1) pick += dp[i-2];
            
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

//space optimatizaton

int so(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    int cur_i=0;
    
    for(int i=1; i<n; i++){
        int nonPick = 0 + prev;
        int pick = arr[i];
        if(i>1) pick += prev2;
        
        cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}


int sumadj(int n, vector<int> arr , vector<int> dp){

    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int notake = dp[i-1]+0;
        int take = INT32_MIN;
         if(i>1){
        take = dp[i-2]+arr[i];
      }
      dp[i]= max(take,notake);
    }

    return dp[n-1];
}


int main(){
    int n;
    cin>>n;
    vector<int> dp(n,-1);
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0;
    // recursion wale case hum n-1 pass krnge 
    //kyuki wo n ko as an index use krta hai
    ans=sumadj(n,arr,dp);  // n=4 , [2 1 4 9] ---> 11

    cout<<ans;

    return 0;
}
 