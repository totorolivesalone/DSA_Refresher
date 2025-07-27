#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
/*
Given that matrix rows are sorted and each row's first element is greater than llast element of prev row, we can think of matrix
as one storted one-d array. Applying Binary search on that 1d array is gonna yeild results in log(m*n) time
and constance space
*/
bool searchMatrix(vector <vector<int>> matrix, int target){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    int m=matrix.size();
    int n=matrix[0].size();
    int left=0;
    int right=m*n-1;
    while(left<=right){
        int mid=left+ (right-left)/2;
        int midElement=matrix[mid/n][mid%n]; //mid element determination can be done by dividing mid by n [cols total] to find row and remainder by n to find column
        if(midElement<target){
            left=mid+1;

        }else if(midElement>target){
            right=mid-1;

        }
        else{
            return true;
        }


    }
    return false;
}
int main(){
    vector <vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    int num;
    cout<<"Enter number to find:: ";
    cin>>num;
    int m=matrix.size();
    int n=matrix[0].size();
    cout<<"OG matrix::"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    bool Found=searchMatrix(matrix,num);
    if(Found){
        cout<<"Found the number";

    }else
    {
        cout<<"Nahhhh!!!";
    }
    return 0;


}
