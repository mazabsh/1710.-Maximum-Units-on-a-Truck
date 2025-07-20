#include<iostream> 
#include<vector>
#include<queue> 
#include<algorithm>

using namespace std; 

class Solution{
public: 
      int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0; 
        auto cmp = [](const vector<int>& a, const vector<int>& b){return a[1]<b[1]; };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp); 
        for(auto d: boxTypes){
          maxHeap.push(d); 
        }
        while(!maxHeap.empty() && truckSize>0){
          auto t = maxHeap.top(); 
          int box_num = t[0]; 
          int box_uni = t[1]; 
          maxHeap.pop(); 
          units += box_uni*min(box_uni, truckSize); 
          truckSize -= box_uni; 
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
