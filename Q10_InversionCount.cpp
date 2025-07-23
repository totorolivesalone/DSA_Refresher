#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
/*
Inversion count to see all arr[i]>arr[j] --->for  [i]<[j]
This can be checked in n square time via two for loops
In nlogn , we can make use of merge sort.
Merge sort breaks arrays into small parts , sorts them and merge them.
 This allows us to count inversions in smaller sorted subarrays from left to right
 If element in left subarray at ith position is greater than element in right subarray
 All elements after ith position in left subarray , are going to be greater than jth element
 therefore, inversionCount=(mid-left+1);
 

*/

int mergedCount(vector<int> & arr, int left, int mid , int right){
    vector <int> temp(right-left+1);
    int inversionCount=0;
    int i=left, j=mid+1, k=0;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inversionCount+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left,k=0; i<=right;i++,k++){
        arr[i]=temp[k];
    }
    return inversionCount;
}
int mergeSort(vector<int> & arr, int left, int right){
    int inversionCount=0;
    if(left<right){
        int mid=left+(right-left)/2;
        inversionCount+=mergeSort(arr,left,mid);
        inversionCount+=mergeSort(arr,mid+1,right);
        inversionCount+=mergedCount(arr,left,mid, right);


    }
    return inversionCount;

}

int inversionCount(vector<int> & arr){
    return (mergeSort(arr,0,arr.size()-1 ));
}

int main(){
    vector<int> arr= {10, 3,4,1};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Inversion Count::"<<inversionCount(arr);
    return 0;
}