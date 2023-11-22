#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<pair<int,int>> s;
    s.insert({-1, -1});
    s.insert({1e9+5, 1e9+5});
    int cnt = 0;
    while (n--){
        int cmd;
        cin >> cmd;
        if (cmd == 1){
            int l, r;
            cin >> l >> r;
            r++;
            auto it = s.upper_bound({l+1,-1});
            auto temp = prev(it);
            if (temp->first <= l && l <= temp->second){
                l = temp->first;
                r = max(r, temp->second);
                s.erase(temp);
            }
            while (it->first <= r){
                r = max(r, it->second);
                it = s.erase(it);
            }
            s.insert({l, r});
            cnt = s.size()-2;
        }else{
            cout << cnt << "\n";
        }
    }    

    return 0;
}