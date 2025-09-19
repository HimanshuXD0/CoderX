// frog Jump dp-3
//https://takeuforward.org/data-structure/dynamic-programming-frog-jump-dp-3/
// Revision status = 3
// Day ---- 3
/*
    ->ulta chlte hai recursion mai
    -> phele 1 ki jump k liye calculate krnge diff
    -> fir 2 ki jump k liye calculate krnge diff
    -> fr apn ko minimum dena hai to mini kr denge left or right ka

    => recursive call m index ko maintain krte hai  
    => uske baad us index se age piche kya khelna hai wo likhte 

*/

#include<bits/stdc++.h>
using namespace std;

// recursion

// int frogJump(int n,int *arr){
    
//     if(n==0) return 0;

//     int left = frogJump(n-1,arr)+abs(arr[n]-arr[n-1]);  
//     int right=INT_MAX;

//     if(n>1)  right = frogJump(n-2,arr)+abs(arr[n]-arr[n-2]);
   
//     return min(left,right);
// }

// memoization 



int frogJump(int n , int *arr, vector<int> dp){
   
   if(n==0) return 0;
   if(dp[n]!=-1) return dp[n];  // Base case
   int left = frogJump(n-1,arr,dp)+abs(arr[n]-arr[n-1]);
   int right= INT_MAX;
   if(n>1)
    right = frogJump(n-2,arr,dp)+abs(arr[n]-arr[n-2]);
   
   return dp[n]=min(left,right);

}

int frogj(vector<int> arr, int n){
     
     if(n==0) return 0;
     int onestep = frogj(arr,n-1)+abs(arr[n]-arr[n-1]);
     int twostep=INT_MAX;
     if(n>1) 
     twostep = frogj(arr,n-2)+abs(arr[n]-arr[n-2]);

     return min(onestep,twostep);


}

//  tabolutaion 

int Frogjump(int n,int *arr){
    vector<int> dp;
    dp[0]=0;  // covering the base case 
    for(int i=1;i<n;i++){
        int left= dp[i-1]+abs(arr[i]-arr[i-1]);
        int right=INT_MAX;
        if(i>n)
        int right= dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]= min(left,right);
    }
    cout<<dp[n-1];
    
}


// space optimization

 void so(int n, int *arr){
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int right = INT_MAX;
      int left= prev + abs(arr[i]-arr[i-1]);
      if(i>1)
        right = prev2 + abs(arr[i]-arr[i-2]);
    
      int cur_i=min(left, right);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
 }


int prac(int n , int arr[],vector<int> dp){
   int prev=0;
   int prev2=0;
   int curr =0;
   for(int i=1;i<=n;i++){
   int onestep = prev+abs(arr[i]-arr[i-1]);
   int twostep = INT_MAX;
   if(n>1)
    twostep = prev2+ abs(arr[i]-arr[i-2]);
     curr= min(onestep,twostep);
     prev2=prev;
     prev=curr;
   }
  

   return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = prac(n-1,arr,dp);    // n=6,[30 10 60 10 60 50] ---> 40
    cout<<ans; 
    return 0;
}

