#include <bits/stdc++.h>
using namespace std;

int main(){
int i, j, x, y, N, M; cin >> N >> M; string A[N], B[M];
for(i=0; i<N; i++){ cin >> A[i]; }
for(i=0; i<M; i++){ cin >> B[i]; }
int d=N-M;
for(x=0; x<=d; x++){for(y=0; y<=d; y++){
for(i=0; i<M; i++){for(j=0; j<M; j++){ if(A[i+x][j+y]!=B[i][j]){i=M+1; break;} }}
if(i==M){ cout << "Yes\n"; return 0; }
}}
cout << "No\n";
}
