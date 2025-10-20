#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
int uniquePaths(int m, int n) {
    vector <int> dp (n,1);
    for(int i=1;i<m;i++){
        for (int j=1;j<n;j++){
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[n-1];
 /*
 In m*n space time , number of paths to any cell will be path[i-1][j]+path[i][j-1] i.e. number of paths to cell above+ number of paths to cell to the left
 Now, if we extract an array and use it , for a cell at ith row , we already know value of j-1th column , we know jth column value , which is equivalent to [i-1][j]. We reset the value using this information
 secondly first row and column would have 1 unique paths always because user can only go down and right not left or UP 
 */
        
}
int main(){
    cout<<"Enter Rows and Columns of grid:"<<endl;
    int m , n;
    cin>>m;
    cin>>n;
    cout<<"Unique paths: "<<uniquePaths(m,n);
    return 0;
}