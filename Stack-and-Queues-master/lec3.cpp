// Number of NGEs to the right
// https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
/*
  basicaly kitne greater elment h koi particular ind k ele k right mai wo niklna hia
  -- phele 1st index ko (indices[0])rkhke check krnge usse jitne bdde mlte jynge count badate jynge
  -- or vector m push kr denge count ko phele index k liye 
  -- fr index[1]  k liye same krnge ....so on jab tak quires khtm nhi hoti 

*/
// Revision Status : 1
// Day ---- 3 
#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(vector<int> &arr, int queries, vector<int> &indices){
        int n = arr.size();
        vector<int> ans;
        for(int i = 0; i < queries; i++){
            int count = 0;
            
            for(int j = indices[i]; j < n; j++){
                if(arr[j]>arr[indices[i]]) count++;
            }
            ans.push_back(count);
        }
        return ans;
       
    }

int main(){

    vector <int>  v {5,7,1,2,6,0};
    vector <int>  idx {1,3};
     vector < int > res = count_NGE(v,2,idx);
     for (int i = 0; i < res.size(); i++) {
      std::cout << res[i] << " ";
  }
    
    return 0;
}