import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();

		cost = new int[n];
		effect = new int[n][m];
		used = new boolean[n];
		for(int i = 0; i < n; i++){
			cost[i] = sc.nextInt();

			for(int j = 0; j < m; j++){
				effect[i][j] = sc.nextInt();
			}
		}

		int result = dfs(0, n, m, x);
		System.out.println(result != Integer.MAX_VALUE ? result : -1);
	}

	static int cost[];
	static int effect[][];
	static boolean used[];

	static int dfs(int depth, int n, int m, int x){
		if(depth == n){
			int result[] = new int[m];
			int total = 0;
			for(int i = 0; i < n; i++){
				if(used[i]){
					for(int j = 0; j < m; j++){
						result[j] += effect[i][j];
					}

					total += cost[i];
				}
			}

			for(int i = 0; i < m; i++){
				if(result[i] < x){
					return Integer.MAX_VALUE;
				}

			}

			return total;
		}

		int result = Integer.MAX_VALUE;
		used[depth] = false;
		result = Math.min(result, dfs(depth + 1, n, m, x));
		used[depth] = true;
		result = Math.min(result, dfs(depth + 1, n, m, x));

		return result;
	}

}
