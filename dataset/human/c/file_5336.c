#include <stdio.h>

int N,M,X,A[12][12],C[12];

int main()
{
    int sum_p=0,sum_m=2e8,sum_m_new=0,u=0;
    scanf("%d %d %d",&N,&M,&X);
    for(int i=0;i<N;i++){
	scanf("%d",&C[i]);
	for(int j=0;j<M;j++)
	    scanf("%d",&A[i][j]);
    }
    for(int i=0;i<2;i++){
	for(int j=0;j<2;j++){
	    for(int k=0;k<2;k++){
		for(int l=0;l<2;l++){
		    for(int m=0;m<2;m++){
			for(int n=0;n<2;n++){
			    for(int o=0;o<2;o++){
				for(int p=0;p<2;p++){
				    for(int q=0;q<2;q++){
					for(int r=0;r<2;r++){
					    for(int s=0;s<2;s++){
						for(int t=0;t<2;t++){
						    sum_m_new=i*C[0]+j*C[1]+k*C[2]+l*C[3]+m*C[4]+n*C[5]+o*C[6]+p*C[7]+q*C[8]+r*C[9]+s*C[10]+t*C[11];
						    for(u=0;u<M;u++){
							sum_p=i*A[0][u]+j*A[1][u]+k*A[2][u]+l*A[3][u]+m*A[4][u]+n*A[5][u]+o*A[6][u]+p*A[7][u]+q*A[8][u]+r*A[9][u]+s*A[10][u]+t*A[11][u];
							if(sum_p<X)
							    break;
						    }

						    if(u==M && sum_m_new<sum_m)
							sum_m=sum_m_new;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }

    if(sum_m==2e8)
	puts("-1");
    else 
	printf("%d\n",sum_m);

    return 0;
}
