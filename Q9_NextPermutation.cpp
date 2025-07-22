#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include <vector>
#include <algorithm>

using namespace std;
/* next permutation is next largest number lexographically 
first we find a pivot. That is the point wherein edits are going to take place
pivot would be deduced by finding any number from end such that it's less than number to it's right.
If pivot is not found, we simply reverse list as array is already in descending order and reversing it would lead to next permutation

else 
we swap the pivot with number to any number greater than pivot in right (start from right)
then since we swapped greater number with pivot position, we want to reverse the array to right of pivot location to make it ascending

*/

void nextPermutation(vector<int>& nums) {
   int n=nums.size();
   int pivot=-1;
   for(int i=n-2;i>=0;i--){
    if(nums[i]<nums[i+1]){
        pivot=i;
        break;
    }
   }
   if(pivot==-1){
    reverse(nums.begin(),nums.end());
    return;
   }
   for(int i=n-1;i>pivot;i--){
    if(nums[i]>nums[pivot]){
        swap(nums[i],nums[pivot]);
        break;
    }
   }
   reverse(nums.begin()+pivot+1, nums.end());
}
int main(){
    int n;
    cout<<"Enter length of array:";
    cin>>n;
    cout<<"Enter "<<n<<" elements:";
    vector<int>nums (n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    nextPermutation(nums);
    cout<<"Next permutation:";
    for(int i=0;i<n;i++){
        cout<<nums[i] <<" ";
    }
    return 0;

}