#include<stdio.h>
#include<stdlib.h>

int main(){
	int m,n;
	int i,j,k,l;
	int flag = 0;
	char** a;
	char** b;
	char* str;

	scanf("%d %d",&n,&m);
	a = (char**)calloc(n,sizeof(char*));
	for(i=0; i<n; i++){
		a[i] = (char*)calloc(n,sizeof(char));
	}
	b = (char**)calloc(m,sizeof(char*));
	for(i=0; i<m; i++){
		b[i] = (char*)calloc(m,sizeof(char));
	}

	str = (char*)calloc(n+1,sizeof(char));
	for(i=0; i<n; i++){
		scanf("%s",str);
		for(j=0; j<n; j++){
			a[i][j] = str[j];
		}
	}


	str = (char*)calloc(m+1,sizeof(char));
	for(i=0; i<m; i++){
		scanf("%s",str);
		for(j=0; j<m; j++){
			b[i][j] = str[j];
		}
	}

	i = 0;
	while( i <= n - m && flag == 0 ){
		j = 0;
		while( j <= n - m && flag == 0 ){
			flag = 1;
			k = 0;
			while( k < m && flag == 1 ){
				l = 0;
				while( l < m && a[i+k][j+l] == b[k][l] ){
					l++;
				}

				if( l == m ){
					flag = 1;
				}else{
					flag = 0;
				}

				k++;
			}
			j++;
		}
		i++;
	}

	if( flag == 1 ){
		printf("Yes\n");
	}else{
		printf("No\n");
	}

	return 0;
}
