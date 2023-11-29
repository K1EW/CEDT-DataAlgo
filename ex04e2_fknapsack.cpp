#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;

class item {
public:
    ld value;
    ld weight;
};

bool cmp (item x, item y){
    return (x.value/x.weight) >= (y.value/y.weight);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ld w;
    cin >> w >> n;
    vector<item> items(n);
    for (int i=0;i<n;i++) cin >> items[i].value;
    for (int i=0;i<n;i++) cin >> items[i].weight;
    sort(ALL(items), cmp);
    ld ans = 0;
    int i=0;
    while (w > 0 && i < n){
        if (items[i].weight <= w){
            w -= items[i].weight;
            ans += items[i].value;
            i++;
        }else{
            ans += w*items[i].value/items[i].weight;
            w = 0;
            i++;
        }
    }
    printf("%.4Lf", ans);

    return 0;
}