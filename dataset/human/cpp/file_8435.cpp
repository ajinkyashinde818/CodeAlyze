#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(N);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int j=0; j<M; ++j) cin >> B[j];
    bool ans = false;
    for(int i=0; i<N-M+1; ++i){
        for(int j=0; j<N-M+1; ++j){
            bool exist_ans = true;
            for(int k=0; k<M; ++k){
                if(A[i+k].substr(j, M) != B[k]){
                    exist_ans = false;
                    break;
                }
                //else{
                    //cout << "match " <<  B[k] << "\n";
                //}
            }
            //if(exist_ans){
                //cout << i << " " << j << "\n";
            //}
            ans |= exist_ans;
        }
    }
    
    if(ans)
        cout<< "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
