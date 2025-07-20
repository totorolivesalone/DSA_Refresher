#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    } //if empty, return

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }); //sort interval array based on first element || this is like 2d matrix
    vector<vector<int>> merged ; //creating 2d vector
    merged.push_back(intervals[0]); //initializing twoD vector with first element
    for(int i=1;i<intervals.size();i++){ //iterating from 2nd element in array to check overlap
        vector<int>& last=merged.back(); //plucking last interval from merged array as merged array always contain no overlapped intervals
        if(intervals[i][0]<=last[1]){ //if first element of un-merged array's interval is less than merged array's last element's last element
            
            last[1]=max(last[1],intervals[i][1]); //then overlap exists. Merged array's last element needs to be updated to either intervals' max last element


        }else{
            merged.push_back(intervals[i]); //if no overlap exists, we simpl push new interval to merged array as it is
        }
          }
          return merged ;


        

}
int main(){
    vector <vector<int>> intervals={{1,3},{2,5},{7,8}};
    for (int i=0;i<intervals.size();i++){
        cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"] ";
    }
    cout<<endl;
    cout<<"Merged Intervals: ";
    vector <vector<int>> mergedIntervals=merge(intervals);
    for (int i=0;mergedIntervals.size();i++){
        cout<<"["<<mergedIntervals[i][0]<<","<<mergedIntervals[i][1]<<"] ";
    }


    return 0;
}