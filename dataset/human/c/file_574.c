#include <stdio.h>


int pic_des(int N, int M, char* n_pic, char* m_pic, int offset_y, int offset_x) {

    for(int i=0;i<N;i++) {
        for(int t=0;t<N;t++) {
            if(n_pic[i*N + t] != m_pic[(i+offset_y)*M + (t+offset_x)]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {

    int N, M;
    scanf("%d %d", &M, &N);

    char Npic[N*N];
    char Mpic[M*M];

    for(int i=0;i<M;i++) {
        scanf("%s",&Mpic[i*M]);
    }

    for(int i=0;i<N;i++) {
        scanf("%s",&Npic[i*N]);
    }

    int flg = 0;
    for(int i=0;i<=M-N;i++) {
        for(int t=0;t<=M-N;t++) {
            if(pic_des(N,M,Npic,Mpic, i, t)) {
                flg = 1;
            }
        }
    }

    if(flg) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
