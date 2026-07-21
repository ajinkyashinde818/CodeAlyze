#include<stdio.h>
#include<string.h>

int main(void){

	int n;
	long long int k;
	int a[200000];
	int b[200000] = {};
	int i;
	int f = 1;
	int num;
	int next;
	int count;
	int l;
	int now;

	scanf("%d %lld",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
		b[i] = -1;
	}

	next = 0;
	b[next] = 0;
	count = 0;

	if(k<200000){
		for(i=0;i<k;i++){
			next = a[next];
		}

		printf("%d\n",next+1);

	}else{
		while(f==1){
			next = a[next];
			count++;
			if(b[next] == -1){
				b[next] = count;
			}else{
				l = count-b[next];
				f = 0;
			}
			k--;
		}


		for(i=0;i<k%l;i++){
			next = a[next];
		}

		printf("%d\n",next+1);
	}

	return 0;
}
