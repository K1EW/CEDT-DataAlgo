#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> mat = {0, 0, 0, 0};
map<int,vector<int>> dp;

vector<int> prod(vector<int> &A, vector<int> &B){
    return {(A[0]*B[0]%k+A[1]*B[2]%k)%k, (A[0]*B[1]%k+A[1]*B[3]%k)%k, (A[2]*B[0]%k+A[3]*B[2]%k)%k, (A[2]*B[1]%k+A[3]*B[3]%k)%k};
}

vector<int> solve(int n){
    if (n == 1) return mat;
    if (dp.find(n) != dp.end())
        return dp[n];
    vector<int> M = solve(n/2);
    dp[(n/2)*2] = prod(M, M);
    if (n%2 != 0)
        dp[n] = prod(dp[(n/2)*2], mat);
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (auto &e : mat) cin >> e;
    vector<int> res = solve(n);
    for (auto e : res) cout << e << " ";

    return 0;
}