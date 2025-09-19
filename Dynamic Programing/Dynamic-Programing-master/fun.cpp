#include<bits/stdc++.h>
using namespace std;

class data {
   public:
   vector<int> v;
//    data(int e){
//       this->v.push_back(e);
//    }

};

int decodeVariations(const string& s)
{   int ans=0;
    //cout<<ans;
	for(int i =0;i<s.length()-1;i++){
        string t = "";
        // cout<<s[i]<<endl;
        // cout<<s[i+1]<<endl;
         // int n = stoi(t);
         // if(n<=26) ans++;
    }
    return ans+2;
 
}

int main(){
     int n = decodeVariations("1234");
     cout<<n;
    
   //  vector<data> u;
   //  vector<int> arr{1,2,3,4,5,6};
   //  int n=5;
    
   //  for(int i=0;i<n;i++){
   //      data a;
   //      for(int j=0;j<n;j++){
   //         //a*.v.push_back(j);
   //         a.v.push_back(j);
   //      }
   //      u.push_back(a);
   //  }
    

   //   for(int i=0;i<u.size();i++){
   //      for(int j=0;j<u[i].v.size();j++){
   //         cout<<u[i].v[j]<<" ";
   //      }
   //      cout<<endl;
   //   }

        return 0;

    }
    // data a(1,2);
    // data b(4,5);
    // data c(6,3);
    // v.push_back(a);
    // v.push_back(b);
    // v.push_back(c);
    // for(auto e:v){
    //     cout<<e.first<<" "<< e.second<<endl;
    // }





     

   