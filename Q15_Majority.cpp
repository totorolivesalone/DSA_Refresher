#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int majorityElement (vector <int> & nums ){
    int candidate= nums[0]; //lets set a candidate ; start with first element
    int count=1; //set count variable value to 1 
    for(int i=1;i<nums.size();i++){ //iterate through entire array 
        if(count==0){ //whenever count ==0 ; we set candidate to current number
            candidate=nums[i];//count is reset to 1 
            count=1;
        }else{
            if(candidate==nums[i]){ // however if count is not 0 , we check if candidate matches current number
                count++; //if yes count is incremented ; otherwise decremented 
            }else{
                count--;
            }
        }
    }
    return candidate; // majority element will always survive the "cancellation" process where different elements cancel each other out.
}
int main(){
    int size=5;
    cout<<"Enter 5 elements:"<<endl;
    vector <int> nums(5);
    for(int i=0;i<5;i++){
        cin>>nums[i];

    }
    cout<<"Majority Element::"<<majorityElement(nums);
    return 0;
}