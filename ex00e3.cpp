#include<iostream>

using namespace std;

double n,d,s,c,i;
int main(){
    cin >> n;
    for(;i++<n;){
        cin >> d;
        c+=d<1||d>n;
        s+=d;
    }
    cout << (c||n*n+n!=2*s?"NO":"YES");
}
