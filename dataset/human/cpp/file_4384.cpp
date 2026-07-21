#include "bits/stdc++.h"
using namespace std;
const int maxn = 555;
// not tested
template<typename T> class compresser{
public:
    static void compress_and_push(vector<T> & to_compress){
        to_compress = compress(to_compress);
    }
    static vector<T> compress(vector<T> to_compress){
        vector<T> copy = compressed_values(to_compress);
        for(T & v : to_compress)
            v = lower_bound(copy.begin(), copy.end(), v) - copy.begin();
        return to_compress;
    }
    static vector<T> compressed_values(vector<T> to_compress){
        sort(to_compress.begin(), to_compress.end());
        to_compress.erase(unique(to_compress.begin(), to_compress.end()), to_compress.end());
        return to_compress;
    }
};
bool diff(vector<long long> u, vector<long long> v){
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    for(int e = 0; e < v.size(); e++) if(u[e] != v[e]) return true;
    return false;
}
void dfs(vector<vector<int> > & graph, vector<int> & seen, int cur){
    seen[cur] = 1;
    for(int nxt : graph[cur]) if(! seen[nxt]) dfs(graph, seen, nxt);
}
int M(){
    int n;
    if(!(cin >> n)) return 0;
    vector<long long> A(n), B(n);
    for(long long & v : A) cin >> v;
    for(long long & v : B) cin >> v;
    long long xorsumA = 0;
    for(long long v : A) xorsumA ^= v;
    long long xorsumB = 0;
    for(long long v : B) xorsumB ^= v;
    A.push_back(xorsumA);
    B.push_back(xorsumB);
    if(A == B) printf("0\n");
    else{
        if(diff(A, B)) printf("-1\n");
        else{
            compresser<long long> solver;
            solver.compress_and_push(A);
            solver.compress_and_push(B);
            vector<vector<int> > graph(200200);
            vector<int > seen(200200);
            int ed = 0;
            set<int> used;
            for(int e = 0; e < n; e++){
                if(A[e] != B[e]) {
                    graph[A[e]].push_back(B[e]);
                    graph[B[e]].push_back(A[e]);
                    used.insert(A[e]);
                    used.insert(B[e]);
                    ed++;
                }
            }
            used.insert(A[n]);
            used.insert(B[n]);
            int comps = 0;
            for(int v : used){
                if(!seen[v]){
                    //cout << v << endl;
                    dfs(graph, seen, v);
                    comps++;
                }
            }
            //cout << "cc " << comps << endl;
            printf("%d\n", ed + comps - 1);
        }
    }
    return 1;
}
int main(){
    while(M());
    return 0;
}
