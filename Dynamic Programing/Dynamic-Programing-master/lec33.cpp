// Edit Distance 
// https://takeuforward.org/data-structure/edit-distance-dp-33/
//We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations

#include <bits/stdc++.h>
using namespace std;

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;  //  if s1 gets empty insert j+1 char to make same as s2
    if(j<0)
        return i+1;  // if s2 gets empty insert i+1 char to make same as s1
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    /* Minimum of three choices
       1--> replacement
       2--> deletion
       3--> insertion 
    */ 
    
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}

int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return editDistanceUtil(S1,S2,n-1,m-1,dp);
    
}

int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << " "<<editDistance(s1,s2);
}