#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
using namespace std;
int maxSubArray(vector<int>& nums) {

    if(nums.size()<1){
        return 0;
    }
    int maxLocal=nums[0];
    int maxGlobal=nums[0];
    for(int i=1;i<nums.size();i++){
        maxLocal=max(nums[i],nums[i]+maxLocal);
        if(maxLocal>maxGlobal){
            maxGlobal=maxLocal;
        }
    }
    return maxGlobal;
}
int main(){
    vector <int> nums={-2,0,-1,2,3,-5};
    cout<<"Array:";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    int maxSum=maxSubArray(nums);
    cout<<endl<<"Max SubArray sum:"<<maxSum;
    return 0;
}