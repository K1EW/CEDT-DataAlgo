#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n, k;
    cin >> n >> k;
    for (ull i=0;i<(1<<n);i++){
        ull t = (1<<k)-1;
        bool flag = false;
        while (t < (1<<n)){
            flag = flag || (i & t) == t;
            if (flag) break;
            t = t << 1;
        }
        if (flag){
            bitset<32> b(i);
            vector<int> ans;
            for (int j=0;j<n; j++)
                ans.push_back(b[j]);
            for (int j=ans.size()-1;j>=0;j--)
                cout << ans[j];
            cout << "\n";
        }
    }

    return 0;
}