#include<stdio.h>
int m,n,ans=0,ok=0;
char a[55][55],b[55][55];
int main(){
	scanf("%d %d ",&m,&n);

	for(int i=0;i<m;i++){
		scanf("%s",a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%s",b[i]);
	}

	for(int i=0;ok==0&&i<=m-n;i++){
		for(int j=0;ok==0&&j<=m-n;j++){//判定区域的左上角
			ans=1;
			for(int i1=0;i1<n;i1++){
				for(int j1=0;j1<n;j1++){
					if(!(a[i+i1][j+j1]==b[i1][j1]))
						ans=0;
				}
			}

			if(ans==1){
				printf("Yes");
				ok=1;
				break;
			}
		}
	}
	if(ans==0)printf("No");

}
