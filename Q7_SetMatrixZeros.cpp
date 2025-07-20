#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
using namespace std;
/*
We have a matrix , 
let's consider two passes! 
First of all we are going to see if there is a 0 in either first row and/or column , if there is we break and store this information
Second pass, we are going to examine all rows and columns except first and we are going to use first row and column as markers to store if ith row or column has zero
Third pass is going to be about evaluating row and column and marking rows and columns as 0s
Last passes would be to examine if first rows and columns had any zero and marking that row and column as 0

We are not including first rows and columns in secondary pass as we need those rows for markers . If we don't ,
we might have matrix[0][3]=0 and mark [0][0] a zero, 
When examining next row, we might look at column [0][0] and mark entire column as 0 , which is wrong

*/
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m==0){
        return;
    }
    int n=matrix[0].size();
    bool firstRowZero=false;
    bool firstColumnZero=false;
    for(int i=0;i<n;i++){
        if(matrix[0][i]==0){
            firstRowZero=true;
            break;
        }
    }
    for(int i=0;i<m;i++){
        if(matrix[i][0]==0){
            firstColumnZero=true;
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;//mark row
                matrix[0][j]=0;//mark column
            }
        }
    }
    for (int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }

        }
    }
    if (firstRowZero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
    
    if (firstColumnZero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
        
}
int main(){
    vector<vector<int>> matrix ={{1,1,1},{2,0,1},{1,4,5}};
    cout<<"Matrix::"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";

        }
        cout<<endl;

    }
    setZeroes(matrix);
    cout<<"Zeroed Matrix:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[i][j]<<" ";

        }
        cout<<endl;

    }


}