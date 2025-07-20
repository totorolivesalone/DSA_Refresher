#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
using namespace std;
/* Floy'd Tortoise and Hare algorithm
Traversal of arrays need to be from i=nums[i];
as n+1 elements have any value from 1 to n , this would allow us to traverse without any problem randomly
To find that there is a duplicate element or not in constant space, we need to find if there is a cycle. 
In constant space , wherein we can't use another array, we can use two pointers. 
Fast pointer is gonna traverse two times faster than slow pointer
When fast value = slow value, we have found the cycle!As fast guy, is on same spot as slow guy
Once we have found a cycle, let one pointer point to point of cycle detection and other start from the starting line
Move both pointers at same time, the place where they meet is point of cycle entry or duplication point 

 */
int findDuplicate(vector<int>& nums) {
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];

    }while(fast!=slow);
    fast=nums[0];
    while(fast!=slow)
       { slow=nums[slow];
        fast=nums[fast];
    }
    return fast;

}
int main(){
    vector<int> nums={2,5,1,5,3,4};
    cout<<"Array:";
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";

    }
    cout<<endl<<"Duplicate :"<<findDuplicate(nums)<<endl;
    return 0;
}
/*
Mathematical logic:
L1= Distance from start to cycle entrance (duplicate)
L2=Distance from cycle entrance to meeting point (where fast and slow pointers meet initially)
C=Length of cycle
At meeting point Slow pointer has travelled L1+L2 steps and Faster pointer has travelled L1+L2+K*C, K is number of rounds of loop
Since fast moves twice the number of times as slow,
2(L1+L2)=L1+L2+k*C;
L1+L2=k*C;
L1=k*C-L2;
Now, L1 = K*C-L2 . That is L1 (distance from start to cycle entrance)= distance remaining from meeting point to start of cycle
This is why we start one pointer from cycle and other from meeting point , move them together to arrive at same point
*/