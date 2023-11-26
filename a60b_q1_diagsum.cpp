#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n][n];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> a[i][j];
    int ans=a[0][0];
    for (int i=0;i<n;i++){
        int gmx = a[i][0], lmx = a[i][0];
        for (int r=i+1,c=1;r<n&&c<n;r++,c++){
            lmx = max(lmx + a[r][c], a[r][c]);
            gmx = max(gmx, lmx);
        }
        ans = max(gmx, ans);
    }
    for (int j=1;j<n;j++){
        int gmx = a[0][j], lmx = a[0][j];
        for (int r=1,c=j+1;r<n&&c<n;r++,c++){
            lmx = max(lmx + a[r][c], a[r][c]);
            gmx = max(gmx, lmx);
        }
        ans = max(gmx, ans);
    }
    cout << ans;

    return 0;
}