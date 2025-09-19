// length of longest common subsequence
// https://takeuforward.org/data-structure/longest-common-subsequence-dp-25/
// Revision Status =1

#include<bits/stdc++.h>
using namespace std;

//recursive

    int lcs(int n,int m,string s,string t,vector<vector<int>> dp){
        if(n<0||m<0) return 0;
        
        if(s[n]==t[m]) return 1+lcs(n-1,m-1,s,t,dp);
        else return 0 + max(lcs(n-1,m,s,t,dp),lcs(n,m-1,s,t,dp));
    }

//memoization

int lcsM(int n,int m,string s,string t,vector<vector<int>> dp){
    if(n<0||m<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n]==t[m]) return dp[n][m]=1+lcsM(n-1,m-1,s,t,dp);
     return dp[n][m]= 0 + max(lcsM(n-1,m,s,t,dp),lcsM(n,m-1,s,t,dp));
}

// tabulation

int lcsT(int n,int m,string s,string t){
     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]= 0+max(dp[i-1][j],dp[i][j-1]);
      }
   }
    return dp[n][m];
}

// space optimization (index shifting)

int so(int n, int m , string s,string t){
  vector<int> prev(m+1,0) , curr(m+1,0);
  for(int j=0;j<=m; j++) prev[j]=0;
  for(int i=0;i<=m;i++){
  for(int j=0;j<=n;j++){
      if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
      else curr[j]=max(prev[j],curr[j-1]);
  }
   prev=curr;
 }

  return prev[m];
}


int main(){
    string s ="adebc";
    string t ="dcadb";
    int n =s.size();
    int m =t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<lcsT(n, m ,s,t);
    return 0;
}