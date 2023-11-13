#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> F;

string DFS(string u, int d = 2){
    if (d == 0)
        return u;
    string ret = "-1";
    if (F.count(u))
        ret = DFS(F[u], d - 1);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string f, s, p1, p2;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> f >> s;
        F[s] = f;
    }
    for (int i=0;i<m;i++){
        cin >> p1 >> p2;
        string g1 = DFS(p1, 2), g2 = DFS(p2, 2);
        if (p1 != p2 && g1 != "-1" && g2 != "-1" && g1 == g2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}