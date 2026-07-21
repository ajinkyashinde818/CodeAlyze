#include<stdio.h>
#include<stdlib.h>

int ROW_INDEX = 1;
//[min_range, max_range]からn_ints個の整数の組をすべてとりだしcomb[組][整数]に格納する
void AllCombs_ints(int min_range, int max_range, int depth, int n_ints, int **comb){
	if(depth > 0){
		for(int x = min_range; x <= max_range; x++){
			//comb[0]を一時的な格納場所として使っている。気持ち悪い。
			comb[0][depth-1] = x;
			if(depth == 1){
				for(int num_i = 1; num_i <= n_ints; num_i++)
					comb[ROW_INDEX][num_i-1] = comb[0][n_ints-num_i];
				ROW_INDEX++;
			}
			AllCombs_ints(x + 1, max_range, depth - 1, n_ints, comb);
		}
	}
	if(depth == n_ints)
		ROW_INDEX = 1;
}
long int Factorial(int upto){
	if(upto == 0)
		return 1;
	return upto * Factorial(upto-1);
}
int main(){
	int N, M, X;
	scanf("%d %d %d", &N, &M, &X);
	long int A[N][M], C[N], cost = 0, count = 0, skill[M], total_cost = 0, total_skill[M];
	for(int i = 0; i < N; i++){
		scanf("%ld", &C[i]);
		for(int j = 0; j < M; j++){
			scanf("%ld", &A[i][j]);
			skill[j] = 0;
			total_skill[j] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		total_cost += C[i];
		for(int col_i = 0; col_i < M; col_i++){
			total_skill[col_i] += A[i][col_i];
		}
	}
	for(int col_i = 0; col_i < M; col_i++)
		if(total_skill[col_i] >= X)
			count++;
	if(count < M)
		printf("%d", -1);
	else{
		count = 0;
		int **pt_ints;
		long int ans = total_cost;
		for(int n = 1; n <= N; n++){
			long int n_comb = Factorial(N) / Factorial(n) / Factorial(N - n);
			pt_ints = (int **) malloc(sizeof(int *) * (n_comb+1));
			for(int comb_i = 0; comb_i <= n_comb; comb_i++){
				pt_ints[comb_i] = (int *) malloc(sizeof(int) * n);
			}
			AllCombs_ints(1, N, n, n, pt_ints);
			for(int comb_i = 1; comb_i <= n_comb; comb_i++){
				long int ans_temp = 0;
				for(int num_i = 0; num_i < n; num_i++){
					cost += C[pt_ints[comb_i][num_i]-1];
					for(int col_i = 0; col_i < M; col_i++){
						skill[col_i] += A[pt_ints[comb_i][num_i]-1][col_i];
					} 
				}
				for(int col_i = 0; col_i < M; col_i++)
					if(skill[col_i] >= X)
						count++;
				if(count == M && cost < ans)
					ans = cost;
				cost = 0;
				count = 0;
              for(int col_i = 0; col_i < M; col_i++)
                skill[col_i] = 0;
			}
		}
      printf("%ld", ans);
	}
	return 0;
}
