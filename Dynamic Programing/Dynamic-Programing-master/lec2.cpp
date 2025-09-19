// cimbing the stairs
// https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
// Revision status = 2
// DAY ----2 

#include<bits/stdc++.h>
using namespace std;



//recursive
// sra kaam ulta chlega

// int solve(int n){
//    if(n<=1) return 1; // bnda 1 se sirf do 1 kadam piche ja skta hai 
//    int left = solve(n-1);
//    int right = solve(n-2);
//    return left+right;
// }


// memoization
 int solve(int n,vector<int>dp){
   if(n<=1) return 1; // bnda 1 se sirf do 1 kadam piche ja skta hai 
   if(dp[n]!=-1) return -1;
   int left = solve(n-1,dp);
   int right = solve(n-2,dp);
   return dp[n]=left+right;
}


// tabulation
 int solve(int n){
 vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];
   }

void so(int n) {

  int prev2 = 1;
  int prev = 1;
  int cur_i = 0;
  for(int i=2; i<=n; i++){
      cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
}

int prac(int n,vector<int> dp){
 int prev=1;
 int  prev2=0;
 int curr =0;

  for(int i=2;i<=n;i++){
    int onstep = prev;
    int twostep = prev2;
    curr = onstep+twostep;
    prev2=prev;
    prev=curr;
  }
 return prev;
}

   int main(){
    int n=5;
    vector<int> dp(n+1,-1);
     cout<<prac(5,dp);           // n=5 ---> 5
   }

   