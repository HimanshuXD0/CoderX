//  Area of largest rectangle in Histogram
// https://youtu.be/vhUxKxiconE
// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/
// Revision Status : 1
// DAY -- 7 


#include<bits/stdc++.h>
using namespace std;

 int largestRectangleArea(vector < int > & arr) {
      int n = arr.size();
      stack < int > st;
      vector<int> leftsmall(n,0),rightsmall(n,n-1);   /// in this we cannot put -1 for not found coz w're playinn with index      // prefix // PSE // 
      for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i])  st.pop();
        if (!st.empty()) leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty()) st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])   st.pop();
        if (!st.empty()) rightsmall[i] = st.top() - 1;
        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, arr[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }

    // optimized solution ---> 

    // int maxHist(vector<int>&arr){
    //     stack<int>s;
    //     int maxA =0;
    //     int n = arr.size();
    //     for(int i=0;i<=n;i++){
    //         while(!s.empty() && (i==n || arr[s.top()]>= arr[i])){
    //             int height = arr[s.top()];
    //             s.pop();
    //             int width;
    //             if(s.empty()) width =i;
    //             else width = i- s.top() -1;
    //             maxA = max(maxA, width*height);
    //         }
    //         s.push(i);
    //     }
    //     return maxA;
    // }

int main(){
    
    return 0;
}