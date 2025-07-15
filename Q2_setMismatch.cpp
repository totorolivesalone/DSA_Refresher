#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
using namespace std;
vector<int> findErrorNums(vector <int>& nums) {

    int xor_total=0; //when we xor same numbers , they cancel each other out and result is zero
    for(int i=0;i<nums.size();i++){
        xor_total^=nums[i]; //idea is that (1,n) xor nums should ideally be 0. But we have missing element and additional element;
        xor_total^=(i+1); //in such case xor_total=missing^duplicate as rest would be cancelled out
    }
    /* (xor_total -1) turns rightmost 1 to 0 and trailing 0 to 1s 
    ~(xor_total-1):rightmost 0 becomes 1 and rest of the bits flip
    xor_total & ~(xor_total-1): ensures rightmost 1's position is captured.
    what is setBit all about?? 
    xor_total = missing ^ duplicate so 1s exist in xor_total where bits of missing and duplicate differ
    we would have to separate missing and duplicate to find them 
    since difference can be determined by set bits in xor_total , we can make use of rightmost 1 value's position in xor_total
    We take rightmost 1s bit instead of leftmost because it's easier to find rightmost 1 bit's position,
    rightmost bit ensures clear separation of two groups as we know the numbers differ by at least one bit position. 
    
    After we determine the bit position , wherein bit value differs for missing and duplicate definitively ,
    then split nums  and (1,n) vector in the two separate groups. 
    xor all elements in both groups , so duplicate value and missing value can be surfaced 

    we can separate numbers in two groups by putting numbers with 0 value in setBit position in one group and 1 in other 

    */
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
    } // a and b contain duplicate and missing values;
    //to find which one is duplicate and missing, assume a is duplicate and check if nums contain any element equal to a
    //if it does, a is duplicate and b missing ; if not vice versa
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