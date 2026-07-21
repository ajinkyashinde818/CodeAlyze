#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;

const int nax=52;
int M,N;
char A[52][52],B[52][52];
bool b=false,a=false;

int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
                scanf("%s",&A[i]);
    }
    for(int i=0;i<M;i++){
                scanf("%s",&B[i]);
    }
    //printf("%s %s %d %d\n",A[0],B[0],N,M);
//--------------------------------------
    for(int i=0;i<N-M+1;i++){
        for(int j=0;j<N-M+1;j++){
                                b=false;
            for(int k=0;k<M;k++){
                for(int l=0;l<M;l++){
                    if(A[i+k][j+l]!=B[k][l]){
                        b=true;
                        break;
                    }
                }
                if(b){
                    break;
                }
            }

        if(!b){
            printf("Yes");
            return 0;
        }
        }

    }
    printf("No" );
        return 0;
}
