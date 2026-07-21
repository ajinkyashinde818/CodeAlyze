#include<iostream>

using namespace std;

int main(){

    int N,M,dy=0; cin >> N >> M;
    char A[N][N],B[M][M];
    if(N < M){
      cout <<"No"<<endl;
      return 0;
    }
//画像A,Bの入力
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<M; i++){
        cin >> B[i];
    }

  for(int i=M; i<=N; i++){
    int dx = 0;
    for(int j=M; j<=N; j++){

        int Tcon = 0;
      //Bに合致するか比較
        for(int k=0; k<M; k++){

            for(int l=0; l<M; l++){

                if(A[k+dx][l+dy] == B[k][l]){
                  Tcon += 1;

                  if(Tcon == M*M){
                    cout << "Yes" << endl;
                    return 0;
                  }
                }
            }

        }

        dx +=1;
    }

      dy += 1;
  }

  cout <<"No" << endl;

}
