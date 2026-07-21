#include <stdio.h>

int min(int a, int b){
	if(a>b){
		return b;
	}
	return a;
}

int main(){
	int N;//入力
	scanf("%d",&N);
	long long A[100000];//入力
	int i;
	for(i=0;i<N;i++){
		scanf("%lld",&A[i]);
	}
	int j;//A[i]が何回負の数であるかをカウントする
	j=0;
	long long m;//A[i]の絶対値の最小値
	m=-min(A[0],-A[0]);
	long long S;//A[i]の絶対値の和
	S=0;
	for(i=0;i<N;i++){
		if(A[i]<0){
			j++;
			A[i]=-A[i];
		}
		m=min(m,A[i]);
		S=S+A[i];
	}
	if(j%2==0){
		printf("%lld",S);
	}else{
		printf("%lld",S-2*m);
	}
}
