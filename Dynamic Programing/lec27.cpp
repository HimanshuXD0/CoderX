// length of Longest Common Substring(subarray)
//https://takeuforward.org/data-structure/longest-common-substring-dp-27/
// Revision Status : 1
#include<bits/stdc++.h>
using namespace std;


int lcsubstring(string s, string t){
 int n=s.size();
 int m=t.size();

   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
    int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
                ans =max(ans,dp[i][j]);
			}
			else dp[i][j]=0;    //if(S1[i-1] != S2[j-1]), the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value (dp[i][j]) as 0.
		}
	}
/*
Note: dp[n][m] will not give us the answer;
      rather the maximum value in the entire dp array will give us the length of the longest common substring.
      This is because there is no restriction that the longest common substring is present at the end of both the strings.
*/
    return ans;

}


string lenOfLCS(string s1 , string s2 , int n , int m, int &idx){
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     // if(n<0||m<0) return 0;
      for(int i =0;i<=m;i++) dp[0][i]=0;
      for(int i =0;i<=n;i++) dp[i][0]=0;
      int ans=0;
    //   int idx=0;
      for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                 dp[i][j]=1+dp[i-1][j-1];
                 if(dp[i][j]>ans){
                    ans=dp[i][j];
                    idx=i;
                 }
             } 
             else {
             dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
             }
        } 
      }
     int size =  dp[n][m];
     string s="";
     int i=n;
     int j=m;
     for(int i{};i<size;i++) s+="$";
     int indx=size-1;
     while(i>0&&j>0){
        if(s1[i-1]==s2[j-1]){ s[indx]=s1[i-1];
        indx--;
        i--;j--;
     }
     else (dp[i-1][j]>dp[i][j-1])?i--:j--;
}
     return s+" "+to_string(dp[n][m]);
}


int main(){
    string s ="adebc";
    string t ="dcadb";
    int idx=0;
   // cout<<lcsubstring(s,t)<<endl;
    cout<<lenOfLCS(s,t,5,5,idx)<<endl;
    //int ans = lenOfLCS(s,t,5,5,idx);
   // cout<<s.substr(idx-ans,ans);
    return 0;
}