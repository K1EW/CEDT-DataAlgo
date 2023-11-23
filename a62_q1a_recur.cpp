#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;

int mat[260][260];

void gen(int a, int b, int r, int c){
    if (a == 0){
        mat[r][c] = b;
        return;
    }
    gen(a-1,b,r,c);
    gen(a-1,b-1,r,c+(1<<(a-1)));
    gen(a-1,b+1,r+(1<<(a-1)),c);
    gen(a-1,b,r+(1<<(a-1)),c+(1<<(a-1)));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    gen(a,b,0,0);
    for (int i=0;i<(1<<a);i++){
        for (int j=0;j<(1<<a);j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}