#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, T, ans=0;
    cin >> r>>c>>T;
    int grid[r+5][c+5];
    queue<tuple<int,int,int>> q;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin >> grid[i][j];
            if (grid[i][j] == 1){
                q.emplace(i,j,0);
                ans++;
            }
        }
    }
    vector<pair<int,int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while(!q.empty()){
        auto [cr, cc, ct] = q.front();
        q.pop();
        for (auto [pr, pc] : dir){
            int R = cr + pr, C = cc + pc;
            if (R < 0 || C < 0 || R >= r || C >= c || grid[R][C] != 0 || ct + 1 > T) continue;
            ans++;
            grid[R][C] = 1;
            q.emplace(R,C,ct+1);
        }
    }
    cout << ans;

    return 0;
}