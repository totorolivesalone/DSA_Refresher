#include<iostream>
#include<iomanip>
#include<vector>
#include<bitset>
using namespace std;
vector<vector<int>> generate(int numRows){
    vector <vector<int>> PascalsTriangle;
    for(int i=0;i<numRows;i++){
        vector <int> row(i+1,1); 
        for(int j=1;j<i;j++){
            row[j]=PascalsTriangle[i-1][j-1]+ PascalsTriangle[i-1][j];

        }
        PascalsTriangle.push_back(row);
    }
    return PascalsTriangle;


        
}
int main (){
    int numRows;
    cout<<"Enter number of rows:";
    cin>>numRows;
    vector <vector<int>> PascalsTriangle= generate(numRows);
    for (int i=0;i<numRows;i++){
        for(int j=0;j<i+1;j++){
            cout<< PascalsTriangle[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}