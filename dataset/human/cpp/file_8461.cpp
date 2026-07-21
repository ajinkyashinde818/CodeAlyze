#include <cstdio>
using namespace std;

char m1[60][60],m2[60][60];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",m1[i]);
	for(int i=0;i<m;i++)scanf("%s",m2[i]);
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n-m;j++){
			bool ok=1;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(m1[i+k][j+l]!=m2[k][l])ok=0;
				}
			}
			if(ok) return puts("Yes"),0;
		}
	}
	return puts("No"),0;
}
