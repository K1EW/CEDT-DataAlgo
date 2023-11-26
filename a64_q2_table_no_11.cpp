#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

const ll MOD = 100000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    ll a[2] = {3, 7};
    ll b[2] = {1, 2};
    if (n < 3){
        cout << a[n-1];
        return 0;
    }
    for (int i=3;i<=n;i++){
        a[0] = a[1];
        b[0] = b[1];
        b[1] = (a[0]%MOD - b[0]%MOD + MOD)%MOD;
        a[1] = (a[0]%MOD + b[1]%MOD + b[1]%MOD)%MOD;
    }
    cout << a[1];
    return 0;
}