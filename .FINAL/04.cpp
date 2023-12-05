#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int r, c;
    int ans = INT_MAX;
    int grid[r+5][c+5];
    cin >> r >> c;
    queue<tuple<int,int,int>> q;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1){
                q.emplace(1,i,j);
            }
        }
    }
    while (!q.empty()){
        auto [t, i, j] = q.front();
        q.pop();
        if (grid[i][j] == 2){
            ans = min(ans, t);
            continue;
        }
        for (auto [pr, pc] : dir){
            int ni = i + pr, nj = j + pc;
            if (ni < 0 || nj < 0 || ni >= r || nj >= c || grid[ni][nj] == 1 || grid[ni][nj] == 3) continue;
            if (grid[ni][nj] == 0)
                grid[ni][nj] = 1;
            q.emplace(t+1, ni, nj);
        }
    }
    cout << ans;

    return 0;
}