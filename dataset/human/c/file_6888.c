#include<stdio.h>
int mat[100][100];
int ret[100][100];
int tmp[100][100];
int s[100];
int t[100];
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c),a){
		c--;
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				mat[i][j]=ret[i][j]=0;
		for(int i=0;i<b;i++){
			int d,e;
			scanf("%d%d",&d,&e);
			d--;e--;
			s[2*i]=d;
			t[2*i]=e;
			s[2*i+1]=e;
			t[2*i+1]=d;
		}
		b*=2;
		for(int i=0;i<b;i++){
			for(int j=i+1;j<b;j++){
				if(t[i]==s[j]&&i/2!=j/2)mat[i][j]=1;
				if(s[i]==t[j]&&i/2!=j/2)mat[j][i]=1;
			}
		}
		for(int i=0;i<b;i++)ret[i][i]=1;
		while(c){
			if(c&1){
				for(int i=0;i<b;i++)
					for(int j=0;j<b;j++)
						tmp[i][j]=0;
				for(int i=0;i<b;i++)
					for(int j=0;j<b;j++)
						for(int k=0;k<b;k++)
							tmp[i][j]|=(ret[i][k]&mat[k][j]);
				for(int i=0;i<b;i++)
					for(int j=0;j<b;j++)
						ret[i][j]=tmp[i][j];
			}
			for(int i=0;i<b;i++)
				for(int j=0;j<b;j++)
					tmp[i][j]=0;
			for(int i=0;i<b;i++)
				for(int j=0;j<b;j++)
					for(int k=0;k<b;k++)
						tmp[i][j]|=(mat[i][k]&mat[k][j]);
			for(int i=0;i<b;i++)
				for(int j=0;j<b;j++)
					mat[i][j]=tmp[i][j];
			c/=2;
		}
		bool Ret=false;
		for(int i=0;i<b;i++){
			if(t[i]==a-1){
				for(int j=0;j<b;j++)if(s[j]==0&&ret[j][i])Ret=true;
			}
		}
		if(Ret)printf("yes\n");else printf("no\n");
	}
}
