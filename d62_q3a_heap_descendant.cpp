#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    vector<int> v;
    int n, a;
    cin >> n >> a;
    q.push(a);
    while (!q.empty()){
        int f = q.front(); q.pop();
        v.push_back(f);
        if (f*2 + 1 < n) q.push(f*2+1);
        if (f*2 + 2 < n) q.push(f*2+2);
    }
    cout << v.size() << "\n";
    for (auto e : v)
        cout << e << " ";

    return 0;
}