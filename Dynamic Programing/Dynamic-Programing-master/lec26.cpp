
//Print Longest Common Subsequence 
//https://takeuforward.org/data-structure/print-longest-common-subsequence-dp-26/
// Revision Status : 1

#include<bits/stdc++.h>
using namespace std;


int lcs(string s, string t)
{   int n=s.size();
   int m=t.size();

   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int j=0;j<=m;j++) dp[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int l = dp[n][m];
	string ans="";
	for(int i=0;i<l;i++) ans+="$";
	int index=l-1;
	int i=n,j=m;
    while(i>0&&j>0){
	   if(s[i-1]==t[j-1]) {
		   ans[index]=s[i-1];
		   index--;
		   i--;j--;
	   }
	   else {
		  (dp[i-1][j]>dp[i][j-1])? i--:j--;
	   }
   }
   cout<<ans<<endl;
   return dp[n][m];

}
int main(){
    string s ="adebc";
    string t ="dcadb";
    cout<<lcs(s,t);
    return 0;
}