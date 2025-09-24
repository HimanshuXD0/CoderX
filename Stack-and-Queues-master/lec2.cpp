// Next Greater Element - II  (circular array)
//  https://takeuforward.org/data-structure/next-greater-element-using-stack/
// Revision Status : 1
// Day ----2

#include<bits/stdc++.h>
using namespace std;

vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i =2*n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i%n]) {
          st.pop();
        }

        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
        }
        st.push(nums[i%n]);
      }
      return nge;
    }



int main(){
    
     vector < int > v {5,7,1,2,6,0};
     vector < int > res = nextGreaterElements(v);
     for (int i = 0; i < res.size(); i++) {
      std::cout << res[i] << " ";
  }
    return 0;
}