#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int M, N;
    cin >> N >> M;
    char A[N][N], B[M][M], C[M][M];

    //scanf("%c",&A[0][0]);
    for(int i=0; i<N; i++){
        char s[50];
        cin >> s;
        for(int j=0; j<N; j++){
            A[i][j]=s[j];
        }
    }
    for(int i=0; i<M; i++){
        char s[50];
        cin >> s;
        for(int j=0; j<M; j++){
            B[i][j]=s[j];            
        }
    }

    bool flag;
    flag=false;

    for(int is=0; is<=N-M; is++){
        for(int js=0; js<=N-M; js++){
            //cout << is << " " << " " << js << endl;
            flag=false;
            for(int i=0; i<M; i++){
                for(int j=0; j<M; j++){
                    //cout << "before" << " " << is+i << " " << js+j << " " << i << " " << j << endl;
                    if( A[is+i][js+j]==B[i][j] ){
                        //cout  << "if" << is+i << " " << js+j << " " << i << " " << j << endl;
                        flag=true;
                    }else{
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    } 

    cout << "No" << endl;
    return 0;
}
