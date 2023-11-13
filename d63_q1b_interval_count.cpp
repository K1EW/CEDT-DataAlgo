#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    while (m--){
        int p;
        cin >> p;
        cout << upper_bound(a.begin(),a.end(),p+k) - lower_bound(a.begin(),a.end(),p-k) << " ";
    }

    return 0;
}