// Count of Distinct Subsequences 
// https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

#include <bits/stdc++.h>
using namespace std;

int prime = 1e9+7;

int countUtil(string s1, string s2, int ind1, int ind2,vector<vector<int>>& dp){
    if(ind2<0)
        return 1;
    if(ind1<0)
        return 0;
    
    if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
    
    if(s1[ind1]==s2[ind2]){
        int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
        int stay = countUtil(s1,s2,ind1-1,ind2,dp);
        
        return dp[ind1][ind2] = (leaveOne + stay)%prime;
    }
    
    else{
        return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    // Write your code here.
    
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return countUtil(t,s,lt-1,ls-1,dp);
} 

int distinct(string s1 , string s2 , int n , int m ){
     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       //  if (m<0) return 1;
     for(int i=0;i<=n;i++) dp[i][0]=1;    // s1 can be empty so i starts from 0
      //  if(n<0) return 0; 
     for(int i=1;i<=m;i++) dp[0][i]=0;   // s2 must have elemnt so i starts from 1
   
     for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(s1[i-1]==s2[j-1]){
           int leave = dp[i-1][j-1];
           int stay = dp[i-1][j];
            dp[i][j]=leave+stay;
      }
     else dp[i][j]=dp[i-1][j];
        }
     }
     return dp[n][m];
    
}


int main() {

  string s1 = "babgbag";
  string s2 = "bag";

  cout <<subsequenceCounting(s1,s2,s1.size(),s2.size());
  
}