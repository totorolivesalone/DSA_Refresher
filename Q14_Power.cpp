#include<iostream>
#include<cmath>
using namespace std;
/*
negative positive both's power
speed up process by log n time by , 
squaring x and dividing n by /2 . 
breaking powers by squares!
*/
double myPow(double x, int n) {
    long long  N=n; // because negative range iss less in int 
    if(n<0){
        N=-N; 
        x=1/x;
    }
    double result=1.0;
    while (N>0){
        if(N%2==1){
            result*=x;
        }
        x*=x;
        N/=2;
    }
    return result;

        
}
int main(){
    double base ;
    int power;
    cout<<"Enter base number::";
    cin>>base;
    cout<<"Enter power::";
    cin>>power;
    cout<<"("<<base<<")^"<<power<<"::"<<myPow(base,power);
    return 0;
}