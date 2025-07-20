#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1; //pointer for last element of nums1
    int j=n-1; //pointer for last element of nums2
    int k=m+n-1; //pointer for new merged array. We are going to merge arrays in num1 . 
    //note merged result is going to be stored in nums 1 . Since we are starting at n+m+1 ; nums1 is not gonna be affected
    /* 
    We are going to start from end of two arrays and virtualise array 1 to be length of sum of two
    We are going to place bigger elements amongst two arrays from end of virtual array 1
    we are going to keep placing bigger elements until either first array is traversed or second array is traversed
    If first array is traversed , we will have to fill all elements of arr2 in arr 1 as they are already sorted , we just have to paste them
    If second array is traversed first, we do nothing as merger is taking place in first array itself
    */
    while (i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }
    }
    while (j>=0){
        nums1[k--]=nums2[j--];
    }

    cout<<endl<<"Sorted Merged array :";
    for(int a=0;a<(m+n-1);a++){
        cout<<nums1[a]<<" ";

    } 
    cout<<endl;
}
int main(){
    vector<int> nums1 ={4,7,9,10};
    vector<int> nums2={2,3,6,9,11};
    int m=4;
    int n=5;

    cout<<"First array:";
    for(int i=0;i<m;i++ ){
        cout<<nums1[i]<<" ";
    }
    cout<<endl<<"Second array:";
    for(int i=0;i<n;i++ ){
        cout<<nums2[i]<<" ";
    }
    merge(nums1,m,nums2,n);
    return 0;


}