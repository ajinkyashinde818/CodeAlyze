#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque> 
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype> 
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    for (int i=0; i<M; i++) {
        cin >> B.at(i);
    }
    for (int i=0; i<N-M+1; i++) {
        for (int j=0; j<N-M+1; j++) {
           bool v = true;
           for (int k=0; k<M; k++) {
               for (int l=0; l<M; l++) {
                   if (A.at(i+k).at(j+l)!=B.at(k).at(l)) {
                       v = false;
                   }
               }
           }
           if (v) {
               cout << "Yes" << endl;
               return 0;
           }
        }
    }
    cout << "No" << endl;
}
