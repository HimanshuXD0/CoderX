//  print longest palindromic substring  
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
  
 int findpalindromic(vector<int> s1, vector<int> s2,int n,int m,int ans){
    if(n<0||m<0) return 0;
    if(s1[n]==s2[m]) {
         ans = 1+findpalindromic(s1,s2,n-1,m-1,ans);
    }
    else ans = 0;
   
   return ans;

 }
 int main(){ 
  
    string s= "abcdcbe";
    string t=s;
    reverse(s.begin(),s.end()); 
     cout << lcs(s,t); 
  
     return 0; 
 }