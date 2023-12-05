#include<bits/stdc++.h>
using namespace std;
const int MOD = 32717;
int main(){
    int k, n;
    cin >> k >> n;
    vector<long long> c(k+1), a(k);
    for (int i=1;i<=k;i++) cin >> c[i];
    for (auto &e : a) cin >> e;
    vector<long long> dp(n+5);
    for (int i=0;i<k;i++) dp[i] = a[i];
    for (int i=k;i<=n;i++){
        for (int j=1;j<=k;j++){
            dp[i] += ((c[j]+MOD)%MOD * (dp[i-j]+MOD)%MOD + MOD)%MOD;
        }
    }
    cout << dp[n]%MOD;

    return 0;
}