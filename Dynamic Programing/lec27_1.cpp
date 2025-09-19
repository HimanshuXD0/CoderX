// print longest common substring(subarray) 
// https://www.techiedelight.com/longest-common-substring-problem/
// Revision status : 1

#include<bits/stdc++.h>
using namespace std;

string lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    int endingIndex = n;
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                 if(dp[i][j]>ans){
                     ans = dp[i][j];
                     endingIndex = i; // storing the last where we found the maxlength LCS
                }
            }
             else dp[i][j] = 0;     
        }
    }
    
    return s1.substr(endingIndex - ans, ans);
    
}
    

int main(){

   string X = "ABC", Y = "BABA";
    cout << lcs(X, Y);
 
    return 0;
}