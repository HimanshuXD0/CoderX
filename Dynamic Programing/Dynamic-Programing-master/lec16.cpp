// ***Partition A Set Into Two Subsets With Minimum Absolute Sum Difference
// https://takeuforward.org/data-structure/partition-set-into-2-subsets-with-min-absolute-sum-diff-dp-16/

// Revision status : 1


//LFQ :-  dp table ki Last row humesa ye store karti h ki us pore array(mtlb complete n-1 index tak) koi particular target kabhi possible tha ya nhi 
//       -  hum isme 0 se totalsum(jo isme humne target liya hai) sbko dp k last row pr check krnge agr wo true hai to use ek subset ka sum maan lenge s1 or bche hue se s2 minus krke diff nikal lenge   

#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector < int > & arr, int n) {
  int totSum = 0;

  for (int i = 0; i < n; i++) {
    totSum += arr[i];
  }

  vector < vector < bool >> dp(n, vector < bool > (totSum + 1, false));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }

  if (arr[0] <= totSum)
    dp[0][totSum] = true;

  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= totSum; target++) {

      bool notTaken = dp[ind - 1][target];

      bool taken = false;
      if (arr[ind] <= target)
        taken = dp[ind - 1][target - arr[ind]];

      dp[ind][target] = notTaken || taken;
    }
  }
  
  int mini = 1e9;
  for (int i = 0; i <= totSum; i++) {
    if (dp[n - 1][i] == true) {
      int diff = abs(i - (totSum - i));
      mini = min(mini, diff);
    }
  }

  return mini;
}

int main() {

  vector<int> arr = {1,2,3,4,4,4,2,4};
  int n = arr.size();
 int dp[4][2];
  int l=sizeof(dp)/sizeof(int);
  
}
