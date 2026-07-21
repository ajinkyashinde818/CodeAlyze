#include <bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int N,M;
    cin >> N >> M;

    vector<string> A(N);
    vector<string> B(M);

    //Aの入力
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }

    //Bの入力
    for(int i=0;i<M;i++){
        cin >> B.at(i);
    }

    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
            bool ans=true;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A.at(i+k).at(j+l)!=B.at(k).at(l)){
                        ans=false;
                        break;
                    }
                }
                if(ans==false){
                    break;
                }
            }
            if(ans==true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
