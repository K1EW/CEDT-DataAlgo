#include <bits/stdc++.h>
using namespace std;
int grid[11][11];
int R, C, r=1, c=1;
string path = "";
vector<pair<char, pair<int,int>>> dir = {{'A', {0,1}}, {'B', {1, 0}}, {'C', {-1, 0}}};

void search(){
    if (r == R && c == C){
        cout << path << "\n";
        return;
    }
    for (auto [cmd, add] : dir){
        r += add.first, c += add.second;
        if (r < 1 || c < 1 || r > R || c > C || grid[r][c] != 0){
            r -= add.first, c -= add.second;
            continue;
        }
        grid[r][c] = 1;
        path.push_back(cmd);
        search();
        path.pop_back();
        grid[r][c] = 0;
        r -= add.first, c -= add.second;
    }
}

int main(){
    cin >> R >> C;
    for (int i=1;i<=R;i++){
        for (int j=1;j<=C;j++)
            cin >> grid[i][j];
    }
    grid[1][1] = 1;
    search();
    cout << "DONE";

    return 0;
}