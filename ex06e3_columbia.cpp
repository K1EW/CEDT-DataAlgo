#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;
typedef tuple<int, int, int> edge;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> weight(r+5,vector<int>(c+5));
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            cin >>weight[i][j];
            if (i==1&&j==1) weight[i][j] = 0;
        }
    }
    vector<vector<int>> dist(r+5,vector<int>(c+5, INT_MAX));
    vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    dist[1][1] = 0;
    pq.emplace(0,1,1);
    while(!pq.empty()){
        auto [w, i, j] = pq.top();
        pq.pop();
        for (auto [ar, ac] : dir){
            int R = i + ar, C = j + ac;
            if (R < 1 || C < 1 || R > r || C > c) continue;
            if (dist[R][C] > dist[i][j] + weight[R][C]){
                dist[R][C] = dist[i][j] + weight[R][C];
                pq.emplace(dist[R][C], R, C);
            }
        }
    }
    for (int i=1;i<=r;i++){
        for (int j=1;j<=c;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}