#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
int grid[15][15];

bool check(int r, int c){
    bool ret = true;
    for (int i=0;i<r;i++) ret = ret && grid[i][c] == 0;
    for (int i=0;i<c;i++) ret = ret && grid[r][i] == 0;
    for (int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) ret = ret && grid[i][j] == 0;
    for (int i=r-1,j=c+1;i>=0&&j<n;i--,j++) ret = ret && grid[i][j] == 0;
    return ret;
}

void NQueens(int r){
    if (r==n){
        ans++;
        return;
    }
    for (int c=0;c<n;c++){
        if (check(r,c)){
            grid[r][c] = 1;
            NQueens(r+1);
        }
        grid[r][c] = 0;
    }
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    NQueens(0);
    cout << ans;

    return 0;
}