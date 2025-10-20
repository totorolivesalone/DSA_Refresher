#include<iostream>
#include<iomanip>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> numMap;
    int complament;
    for (int i=0;i<nums.size();i++){
        complament=target-nums[i];
        if(numMap.find(complament) !=numMap.end()){
            return {numMap[complament],i};
        }
        numMap[nums[i]]=i;
        
    }
    return {};

        
    }

int main(){
    vector<int> arr= {10, 3,4,1};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<" Target:5"<<endl;
    cout<<"Two Sum:"<<endl;
    vector<int> ans=twoSum(arr,5);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    return 0;
}