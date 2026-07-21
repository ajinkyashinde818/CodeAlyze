import java.util.Scanner;

public class Main { //YES! (Pay attention to indexing variables when debugging)
	//You tend to get them mixed up; Don't doubt your algorithmic thinking cuz you're a beast!

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int M = input.nextInt();
		int X = input.nextInt();
		long[][] data = new long[N][M+1]; //Extra slot for cost
		for (int i = 0; i < N; i++) {
			data[i][0] = input.nextInt();
			for (int j = 1; j <= M; j++) {
				data[i][j] = input.nextInt();
			}
		}
		long cost = Integer.MAX_VALUE;
		String[] possibilities = Recur(N).split(" ");
		for (int i = 0; i < possibilities.length; i++) {
			String x = possibilities[i];
			long[] cmp = new long[M];
			long curcost = 0;
			for (int j = 0; j < N; j++) {
				if (x.charAt(j)=='Y') {
					curcost+=data[j][0];
					for (int k = 1; k<=M; k++) {
						cmp[k-1]+=data[j][k];
					}
				}
			}
			boolean exceeded = true;
			for (int j = 0; j < M; j++) {
				if (cmp[j]<X) {
					exceeded=false;
					break;
				}
			}
			if (exceeded) cost = Math.min(cost, curcost);
		}
		if (cost!=Integer.MAX_VALUE) System.out.println(cost);
		else System.out.println(-1);
	}
	public static String Recur(int N) {
		if (N==1) return "Y N ";
		String[] arr = Recur(N-1).trim().split(" ");
		String ans = "";
		for (int i = 0; i < arr.length; i++) {
			ans+=arr[i]+"Y ";
		}
		for (int i = 0; i < arr.length; i++) {
			ans+=arr[i]+"N ";
		}
		return ans.trim();
	}
}
