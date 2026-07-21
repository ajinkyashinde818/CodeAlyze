#include <stdio.h>

int main(void)
{
	int j,i,min=0,N,M,C[12],A[12][12],X,d[12]={0,0,0,0,0,0,0,0,0,0,0,0},z=1,s[12],total=0;
	scanf("%d",&N);
	scanf("%d",&M);
	scanf("%d",&X);
	for(i=0;i<N;i++){
		scanf("%d",&C[i]);
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
			d[j]+=A[i][j];
		}
		min+=C[i];
		z*=2;
	}
	for(j=0;j<M;j++){
		if(d[j]<X){
			printf("-1");
			return 0;
		}
	}
	for(s[0]=0;s[0]<2;s[0]++){
		for(s[1]=0;s[1]<2;s[1]++){
			for(s[2]=0;s[2]<2;s[2]++){
				for(s[3]=0;s[3]<2;s[3]++){
					for(s[4]=0;s[4]<2;s[4]++){
						for(s[5]=0;s[5]<2;s[5]++){
							for(s[6]=0;s[6]<2;s[6]++){
								for(s[7]=0;s[7]<2;s[7]++){
									for(s[8]=0;s[8]<2;s[8]++){
										for(s[9]=0;s[9]<2;s[9]++){
											for(s[10]=0;s[10]<2;s[10]++){
												for(s[11]=0;s[11]<2;s[11]++){
													for(j=0;j<M;j++){
														d[j]=0;
														for(i=0;i<N;i++){
															d[j]+=s[i]*A[i][j];
														}
													}
													for(j=0;j<M;j++){
														if(d[j]<X){
															break;
														}
													}
													if(j==M){
														total=0;
														for(i=0;i<N;i++){
															total+=s[i]*C[i];
														}
														if(total<min)min=total;
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
	}
	printf("%d",min);
	return 0;
}
