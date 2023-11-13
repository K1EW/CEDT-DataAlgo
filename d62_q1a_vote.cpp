#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    map<string, int> mp;
    priority_queue<pair<int, string>> pq;
    for (int i=0;i++<n;){
        string s;
        cin >> s;
        mp[s] += 1;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        pq.emplace((*it).second, (*it).first);
    int cnt = 0, ans = -1;
    while (!pq.empty()){
        ans = pq.top().first;
        cnt++;
        pq.pop();
        if (cnt >= k)
            break;
    }
    cout << ans;

    return 0;
}