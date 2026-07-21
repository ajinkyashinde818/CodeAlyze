#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main()
{
	long long int A[3][300000],N=0,K=0,cnt=0,next=0,i=0;

	scanf("%lld %lld",&N,&K);


	for(i=0;i<N;i++){
		scanf("%lld", &A[0][i]);
		A[1][i]=0;
		A[2][i]=0;
	}

	//A[0][i]はiから行ける町の番号
	//A[1][i]は町iにきた回数
	//A[2][i]は最初に町iにきた時の移動回数


	long long int now=1;
	A[1][0]=1;

	while(cnt<K){
		cnt++;
		next=A[0][now-1];
		A[1][next-1]++;
		
		//printf("移動回数=%lld,%lldから%lldへ\n",cnt,now,next);

		if(A[1][next-1]==1){
			A[2][next-1]=cnt;
			//printf("移動回数=%lldで初めて町%lldにきた\n",cnt ,next);
		}
		else{
			//printf("移動回数=%lldで二回目に町%lldにきた\n",cnt ,next);
			now=next;
			break;
		}


		now=next;

	}

	long long int onecycle = cnt - A[2][now-1];

	//printf("onecycle=%lld\n",onecycle);

	if(onecycle==0){
		printf("%lld",now);
	}
	else{

		long long int surplus=(K-cnt)%onecycle;

		cnt=surplus;

		//printf("残り移動回数=%lld,現在町%lldに滞在中\n",cnt,now);



		while(cnt!=0){

			next=A[0][now-1];

			//printf("残り移動回数=%lld,%lldから%lldへ\n",cnt,now,next);

			now=next;

			cnt--;

		}

		printf("%lld", now);

	}

	return 0;
}
