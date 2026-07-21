import java.util.*;

class Main {


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] C = new int[N];
		int[][] A = new int[N][M];
		boolean possibility = false;

		int min = 0;
		for(int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			min += C[i];
			for(int j = 0; j < M; j ++) {
				A[i][j] = sc.nextInt();
			}
		}

		for (int i=0; i<(Math.pow(2,N)); i++) {
			int understand[] = new int[M];
			for(int j = 0; j < M; j ++) {
				understand[j] = 0;
			}
			boolean[] overX = new boolean[M];
			int price = 0;
			
			
			for (int j=0; j<N; j++) {
				if ((1&i>>j) == 1) {
					price += C[j];
					for (int k=0; k<M; k++) {
						understand[k] += A[j][k];
						if(understand[k] >= X) overX[k] = true;	
					}
					
				}


			}
			
			int count = 0;
			for(int l = 0; l < M; l ++) {
				if(overX[l] == true) count++;
			}
			if(count == M) {
				min = Math.min(min,price);
				possibility = true;
			}
			
			
		}



		if(possibility){
			System.out.println(min);
		}else {
			System.out.println(-1);
		}

	}



}
