//ICPC2014 problem B
#include<stdio.h>

int main()
{
	int i,j,k,l;
	int h;
	int mat[10][5];
	int cnt;
	while(1){
		scanf("%d",&h);
		if( h==0 ) break;
		for( i=0 ; i<h ; i++ ){
			scanf("%d %d %d %d %d",&mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3],&mat[i][4]);
		}
		int sum = 0;
		int flag = 1;
		while(flag==1){
		flag = 0;
		for( i=0 ; i<h ; i++ ){
			for( j=0 ; j<3 ; j++){
				cnt = 1;
				for( k=j+1 ; k<5; k++){
					if( mat[i][j] == mat[i][k] && mat[i][j] != 0 ){
						cnt++;
					}else if( cnt >= 3 ){
						sum += cnt*mat[i][j];
						for( l=j;l<(j+cnt);l++ ){
							mat[i][l] = 0;
						}
						flag = 1;
						break;
					}else{
						cnt=0;
						break;
					}
					if( mat[i][j] == mat[i][k] && k==4 && cnt >= 3 && mat[i][j] != 0){
						sum+= cnt * mat[i][j];
						for( l=j;l<(j+cnt);l++ ){
							mat[i][l] = 0;
						}
						flag = 1;
					}
				}
			}
		}
		//石を下に落とす作業
		for(k=0;k<h;k++){
			for( i=h-1 ; i > 0 ; i-- ){
					for( j=0;j<5;j++){
						if( mat[i][j] == 0 ){
							mat[i][j] = mat[i-1][j];
							mat[i-1][j] = 0;
						}
					}
				}
			}
			
		}
		printf("%d\n",sum);
							
	}
	return 0;
}
