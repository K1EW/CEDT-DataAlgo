#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> A(n + 5);
    for (int i=1;i<=n;i++){
        cin >> A[i];
        A[i] += A[i-1];
    }
    while (m--){
        int a, b;
        cin >> a >> b;
        a++;
        int l=1,r=n;
        ll ans=0;
        while (l <= r){
            int m = l + (r - l)/2;
            ll cost = A[m] - A[a-1] + (m - a + 1)*k;
            if (cost <= b){
                ans = A[m] - A[a-1];
                l = m+1;
            }else{
                r = m-1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}