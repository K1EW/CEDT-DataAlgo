#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for (int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    while (m--){
        int a, b;
        cin >> a >> b;
        auto it = upper_bound(v.begin(), v.end(), make_pair(a,b));
        if (it == v.begin()) cout << "-1 -1 ";
        else if (*(it-1) == make_pair(a,b)) cout << "0 0 ";
        else{
            auto [f, s] = *(it-1);
            cout << f << " " << s << " ";
        }
    }

    return 0;
}