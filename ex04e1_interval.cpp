#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,t=0;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (auto&[e,s]:v) cin >> s;
    for (auto&[e,s]:v) cin >> e;
    sort(v.begin(),v.end());
    for (auto[e,s]:v){
        if(t<=s){
            ans++;
            t=e;
        }
    }
    cout<<ans;
}