#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int N,M;
	char A[50][50],B[50][50];
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++) scanf(" %s",A[i]);
	for(int i=0;i<M;i++) scanf(" %s",B[i]);
	bool yes;
	for(int i=0;i<(N-M+1)*(N-M+1);i++){
		yes=true;
		for(int j=0;j<M*M;j++){
		    if(A[i/(N-M+1)+j/M][i%(N-M+1)+j%M]!=B[j/M][j%M]){
		    	yes=false;
		    	break;
		    }
		}
		if(yes) break;
	}
	
	if(yes) printf("Yes");
	else printf("No");
}
