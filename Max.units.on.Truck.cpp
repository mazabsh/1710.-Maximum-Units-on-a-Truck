#include<iostream> 
#include<vector>
#include<queue> 
#include<algorithm>

using namespace std; 

class Solution{
public: 
      int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0; 
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){return a[1]>b[1]; });
        for(auto box:boxTypes){
              int number = min(truckSize, box[0]); 
              units +=number*box[1]; 
              truckSize -=number; 
              if(truckSize<=0) break; 
        }
        return units; 
        
      }
};
int main(){
  vector<vector<int>> boxTypes ={{1,3},{2,2},{3,1}};
  int truckSize = 4; 
  Solution sol; 
  cout << sol.maximumUnits(boxTypes,truckSize) << endl; 
  return 0; 
}
