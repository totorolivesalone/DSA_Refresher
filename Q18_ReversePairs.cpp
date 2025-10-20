
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int mergedCount(vector<int> & arr, int left, int mid , int right){
    vector <int> temp(right-left+1);
    int ReverseCount=0;
    int  j=mid+1;
    int  i=left;
    while (i<=mid && j<=right ){
        if(arr[i]>2LL* arr[j]){
            
            ReverseCount=ReverseCount+(mid-i+1);
            j++;
        }else{
            i++;
        }
    }
    
    i=left;
    j=mid+1;
    int k=0;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            
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
    return ReverseCount;
}
int mergeSort(vector<int> & arr, int left, int right){
    int ReverseCount=0;
    if(left<right){
        int mid=left+(right-left)/2;
        ReverseCount+=mergeSort(arr,left,mid);
        ReverseCount+=mergeSort(arr,mid+1,right);
        ReverseCount+=mergedCount(arr,left,mid, right);


    }
    return ReverseCount;

}

int ReverseCount(vector<int> & arr){
    return (mergeSort(arr,0,arr.size()-1 ));
}

int main(){
    vector<int> arr= {10, 3,4,1};
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Inversion Count::"<<ReverseCount(arr);
    return 0;
}