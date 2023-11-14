#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, v;
    cin >> n >> k >> v;

    vector<int> a(n);
    for (auto &e : a) cin >> e;
    a.insert(a.begin() + k, v);
    n++;
    int i = k, j = k, cnt=0, l=n,r=n;
    int round = 0;
    while(1){
        while (i-1>=0&&a[i-1]==v) i--;
        while (j+1<n&&a[j+1]==v) j++;
        if(j-i+1-cnt>=3){
            l=i;
            r=j;
            if (i-1>=0&&j+1<n&&a[i-1]==a[j+1]){
                v = a[i-1];
                cnt = j-i+1;
                i--;
                j++;
            } else 
              break;
        } else 
        break;
    }

    for (int i=0;i<n;i++){
        if (l <= i && i <= r) continue;
        cout << a[i] << " ";
    }

    return 0;
}