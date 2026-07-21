#include<stdio.h>
#include<stdlib.h>

int main(){
	long int N, current_town = 1;
	long long int K;
	scanf("%ld %lld", &N, &K);
	int A[N+1];
	for(int i = 1; i <= N; i++){
		scanf("%d", &A[i]);
	}
	if(K <= N){
		for(int step_i = 1; step_i <= K; step_i++)
			current_town = A[current_town];
		printf("%ld", current_town);
	}
	else{
		int *p;
		p = (int *) malloc(sizeof(int) * (N + 1));	
		for(int town_i = 1; town_i <= N; town_i++)
			p[town_i] = -1;
		p[1] = 0;
		int count = 0, period = 0;
		while(count <= N){
			current_town = A[current_town];
			count++;
			if(p[current_town] == -1){
				p[current_town] = count;
			}
			else{
				period = count - p[current_town];
				count = N + 1;
				break;
			}
		}
		K = (K - p[current_town]) % period;
		for(int i = 1; i <= K; i++)
			current_town = A[current_town];
		printf("%ld", current_town);
	}
	return 0;
}
