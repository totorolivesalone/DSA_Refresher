#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
/* Given array nums with n objects colored red , white or blue , sort them in-place so that objects of the same color are adjacent , with colors 
in order red, white and blue. Integers 0, 1 and 2 represent red , white and blue respectively.  */

void sortColors(vector <int> & nums){
    int i=0; // create a pointer to keep track of perimeter of red objects ; initializing that perimeter from start of vector
    int j=0; // create a pointer to keep track of perimeter of white objects ; initializing that perimeter from start of vector
    int k=nums.size()-1; //create a pointer to keep track of perimeter of blue objects  ; intializing that perimeter from end of vector
    int t=0; // this is for swapping variables , swap function alternative. constant space;
    while (j<=k){ // we will continue swapping until white boundary from right exceeds red blue boundary from right
        if(nums[j]==0){ //if pointer defining white boundary has red element ; swap elements of pointer 1 and and pointer 2
            t=nums[j]; //native swap
            nums[j]=nums[i]; 
            nums[i]=t;
            i++; 
            j++; 
        }else if(nums[j]==1){ // if pointer defining white boundary has white element, increment white boundary
            j++; 
        }else //if pointer defining white boundary has blue element, swap it with left periphery of blue elements' domain and push blue's domain to the left
        {
            t=nums[j]; //native swap
            nums[j]=nums[k];
            nums[k]=t;
            k--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter length of array: ";
    cin>>n;
    cout<<"Enter n integers and input can only be 0,1,2:"<<endl;
    vector<int> nums;
    int m=0;
    for(int i=0; i<n;i++){
        cin>>m;
            nums.push_back(m);
        
    }
    cout<<"Your input: "<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    sortColors(nums);
    cout<<"Sorted output : "<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;


}