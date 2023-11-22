#include <bits/stdc++.h>

using namespace std;

int n;

int solve(int cnt, int last, int sum){
    if (sum >= n || cnt >= n)
        return sum == n;
    return solve(cnt+1, last, sum+last) + solve(cnt+1, last+1, sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << solve(0,1,0);

    return 0;
}