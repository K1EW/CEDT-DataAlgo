#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    ll start;
    cin >> n >> m >> start;
    vector<ll> p(100005);
    p[1] = start;
    for (int i=0;i<n;i++){
        int a, s;
        cin >> a >> s;
        p[a+1] = s;
    }
    for (int i=2;i<100005;i++){
        if (p[i] == 0)
            p[i] = p[i-1];
    }
    for (int i=1;i<100005;i++)
        p[i] += p[i-1];
    for (int i=0;i<m;i++){
        ll P;
        int x;
        cin >> P >> x;
        x++;
        int l=1, r=x;
        auto day = lower_bound(p.begin(), p.begin()+x + 1, P);
        if (day <= p.begin() + x){
            cout << day - p.begin() - 1 << " ";
            continue;
        }
        day = lower_bound(p.begin()+ x + 1, p.end(), P + p[x]);
        cout << day - p.begin() - 1 << " ";
    }

    return 0;
}