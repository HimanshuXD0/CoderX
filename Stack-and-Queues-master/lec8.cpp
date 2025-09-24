//  Max rectangle | Maximal Rectangle | Maximum Size Rectangle in Binary Matrix 
//  https://youtu.be/oaN9ibZKMpA
// Revision Status : 0

#include<bits/stdc++.h>
using namespace std;

 int maxHist(vector<int>&arr){
        stack<int>s;
        int maxA =0;
        int n = arr.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || arr[s.top()]>= arr[i])){
                int height = arr[s.top()];
                s.pop();
                int width;
                if(s.empty()) width =i;
                else width = i- s.top() -1;
                maxA = max(maxA, width*height);
            }
            s.push(i);
        }
        return maxA;
    }
    int maxArea(int mat[200][200], int n, int m) {
        // Your code here
                int maxArea = 0;
                vector<int> height(m, 0);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (mat[i][j] == 1) height[j]++;
                        else height[j] = 0;
                    }
                    int area = maxHist(height);
                    maxArea = max(maxArea, area);
                }
                return maxArea;
    }

int main(){
    
    return 0;
}