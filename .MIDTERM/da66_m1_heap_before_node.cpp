#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, idx;
    cin >> n >> idx;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        if (f != idx){
            ans.push_back(f);
            if (f*2 + 1 < n) q.push(f*2+1);
            if (f*2 + 2 < n) q.push(f*2+2);
        }
    }
    cout << ans.size() << "\n";
    for (auto e : ans)
        cout << e << " ";

    return 0;
}