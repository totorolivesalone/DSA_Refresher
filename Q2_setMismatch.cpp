#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
using namespace std;
vector<int> findErrorNums(vector <int>& nums) {

    int xor_total=0;
    for(int i=0;i<nums.size();i++){
        xor_total^=nums[i];
        xor_total^=(i+1);
    }
    int setBit= xor_total & ~( xor_total -1);
    int a=0;
    int b=0;
    for(int i=0;i<nums.size();i++){
        if(setBit & nums[i]){
            a^=nums[i];
        }else{
            b^=nums[i];
        }
    }
    for (int i=1;i<=nums.size();i++){
        if(setBit & i){
            a^=i;
        }else{
            b^=i;
        }
    }
    bool a_is_duplicate=false;
    for (int i=0;i<nums.size();i++){
        if(nums[i]==a){
            a_is_duplicate=true;
            break;
        }
    }
    vector<int> arr;
    if(a_is_duplicate){
        arr={a,b};
       
    }
    else {
        arr={b,a};
        
    }    

       return arr; 
}
int main(){
    vector <int> nums= {3,4,5,1,6,4};
    cout<<"Array::";
    for(int i=0;i<6;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector <int> arr=findErrorNums(nums);
    cout<<"Duplicate::"<<arr[0]<<" , Missing::"<<arr[1];
    return 0;
}