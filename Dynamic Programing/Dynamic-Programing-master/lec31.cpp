//Shortest Common Supersequence 
//https://takeuforward.org/data-structure/shortest-common-supersequence-dp-31/


#include<bits/stdc++.h>
using namespace std;


 string shortestCommonSupersequence(string s1, string s2, int x, int y)
{
    vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
    for(int i=0;i<=x;i++) dp[i][0]=0;
    for(int j=0;j<=y;j++) dp[0][j]=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            
                if(s1[i-1]==s2[j-1])  dp[i][j]= 1+dp[i-1][j-1];
    
                else  dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
    
        }
    }
    
        // printing

    int i=x,j=y; 
    string ans="";
    while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }
        else {
        
            ans+=s2[j-1];
                j--;
        }
    }
    while(i>0){ ans+=s1[i-1];i--;}
    while(j>0){ ans+=s2[j-1]; j--;}
    // cout<<ans;
    return ans;  // get directly by x+y-lcs(s1,s2);
}
int main(){
    string s="brute";
    string t="groot";
    cout<<shortestCommonSupersequence(s,t,s.size(),t.size());

    return 0;
}