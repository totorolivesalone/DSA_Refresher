#include<iostream>
#include<vector>
#include<bitset>
#include <iomanip>
using namespace std;
/*
traverse entire array. Keep track of minimum price and only update it if price lower than that price is found. 
However, for maxprofit , only update it if old maxProfit is less than current prices[i]-minPrice
*/
int maxProfit (vector<int> & prices){
    if(prices.empty())
    {
        return 0;
    }
    int maxProfit=0;
    int minPrice=prices[0];
    for(int i=0;i<prices.size();i++){
        minPrice=min(prices[i],minPrice);
        maxProfit=max(maxProfit, prices[i]-minPrice);
    }
    return maxProfit;


}
int main(){
    vector<int> arr= {2,3,4,5,1};
    cout<<"Stonkssss::";
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Maximum profit::"<<maxProfit(arr);
    return 0;
}