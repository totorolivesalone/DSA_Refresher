#include<iostream>
#include<cmath>
#include<vector>
#include <limits.h>

using namespace std;

int majorityElement2 (vector <int> & nums ){
    int candidate1=INT_MIN , candidate2= INT_MIN ; 
    int count1=0, count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==candidate1){
            count1++;
        }else if(nums[i]==candidate2){
            count2++;

        }
        else if(count1==0){
            candidate1=nums[i];
            count1=1;
        }else if(count2==0){
            candidate2=nums[i];
            count2=1;
        }else{
            count1--;
            count2--;
        }
    }
   count1=0;
   count2=0;
   for(int i=0;i<nums.size();i++){
    if(nums[i]==candidate1){
       count1++; 
    }
    if(nums[i]==candidate2){
        count2++;

    }
   }
   int n=nums.size();
   if(count1>n/3){
    return candidate1;
   }
   if(count2>n/3){
    return candidate2;
   }
}
int main(){
    int size=5;
    cout<<"Enter 5 elements:"<<endl;
    vector <int> nums(5);
    for(int i=0;i<5;i++){
        cin>>nums[i];

    }
    cout<<"Majority Element::"<<majorityElement2(nums);
    return 0;
}