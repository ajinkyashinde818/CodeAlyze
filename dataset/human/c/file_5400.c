#include<stdio.h>
#include<math.h>

int main(void){
    int N,M,X,i,j,cost=2147483647,count=0;
    scanf("%d%d%d",&N,&M,&X);
    int C[N],A[N][M],use[N],point[M];
    for(i=0;i<N;i++){
        use[i]=0;
        scanf("%d",&C[i]);
        for(j=0;j<M;j++){
            scanf("%d",&A[i][j]);
        }
    }
    use[N-1]=1;
    while(count<pow(2,N)){
        int counter=0,costcount=0;
        for(j=0;j<M;j++){
            int point=0;
            for(i=0;i<N;i++){
                point+=A[i][j]*use[i];
            }
            if(point>=X){
                counter++;
            }
        }
        if(counter==M){
            for(i=0;i<N;i++){
                costcount+=C[i]*use[i];
            }
            if(costcount<cost) cost=costcount;
        }
        int k=N-1;
        do{
            use[k]=1-use[k];
            k--;
        }while(use[k+1]==0);
        count++;
    }
    if(cost==2147483647){
        printf("-1\n");
    }else{
        printf("%d\n",cost);
    }    
    return 0;
}
