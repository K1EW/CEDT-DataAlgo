#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int f,w,n;
    cin >> f >> w >> n;
    vector<int> p(f);
    for(auto &e:p) cin >> e;
    sort(ALL(p));
    int i=0,j=0,ans=0;
    while (i<=n && j < f){
        if (i < p[j]){
            ans++;
            i = p[j] + 2*w;
        }
        j++;
    }
    cout << ans;

    return 0;
}