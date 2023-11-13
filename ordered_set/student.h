#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> sA;
    for (auto e : A){
        sA.insert(e);
        v.push_back(e);
    } 
    for (auto e : B){
        if (!sA.count(e))
            v.push_back(e);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> sB;
    for (auto e : B) sB.insert(e);
    for (auto e : A){
        if (sB.count(e))
            v.push_back(e);
    } 

    return v;
}
