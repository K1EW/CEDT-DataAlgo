#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

bool solve(string s){
    if (s.size() == 2)
        return s == "01";
    string a="",b="";
    for (int i=0;i<s.size();i++){
        if (i<s.size()/2) a += s[i];
        else b += s[i];
    }
    bool x = solve(a);
    reverse(ALL(a));
    bool y = solve(a);
    bool z = solve(b);
    return (x || y) && z;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    while (n--){
        string s = "";
        for (int i=0;i<(1<<k);i++){
            char t;
            cin >> t;
            s += t;
        }
        cout << (solve(s)?"yes\n" : "no\n");
    }

    return 0;
}