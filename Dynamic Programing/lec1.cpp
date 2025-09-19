// fibonachi series
// https://takeuforward.org/data-structure/dynamic-programming-introduction/
// Revision status = 2
// DAY --- 1

#include<bits/stdc++.h>
using namespace std;


// recursive approch 

// int fee(int n){
//     if(n<=1) return n;
//     return fee(n-1)+fee(n-2);
// }

//  memoization concept remember the previous sloved subproblems


int f(int n, vector<int> dp){
     
    if(n<=1) return n;

      if(dp[n]!=-1) return dp[n];

      return dp[n] = f(n-1,dp)+f(n-2,dp);

}

// tabulation 

int f(int n){
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];

}


// Space Optimization

void so(int n) {

  int prev2 = 0;
  int prev = 1;
  int cur_i = 0;
  for(int i=0; i<n; i++){
      cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
}


int prac(int n,vector<int> dp){

  int prev=1;
  int prev2 =0;
  int curri = 0;

  for(int i=2;i<=n;i++){
    curri=prev+prev2;
    prev2=prev;
    prev=curri;
  }
  return prev;
  // if(n<=1) return 1;
  // if(dp[n]!=-1) return dp[n];
  // return dp[n]=prac(n-1,dp)+prac(n-2,dp);
}


int main() {

  int n=7;
  vector<int> dp(n+1,-1);
  cout<<prac(n,dp);     // n=5 ---> 5
  //cout<<fs(n,dp);     // n=5 ---> 5
  return 0;
}







