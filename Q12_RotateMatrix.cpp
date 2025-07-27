#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/* 
transpose and reverse
[cos sin 
-sin cos]
*/
void rotate(vector <vector<int>> & matrix){
    int n=matrix.size();
    //transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //reverse rows
    for (int i=0;i<n;i++){
        int left=0;
        int right=n-1;
        while(left<right){
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }
}
int main(){
    vector <vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    int n=matrix.size();
    cout<<"OG matrix::"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Rotated matrix::"<<endl;
    rotate(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}