import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int a[] = new int[n];
		int minus = 0;
		int zero = 0;
		int minAbs = Integer.MAX_VALUE;
		long absSum = 0;
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();

			if(a[i] < 0){
				minus++;
			}
			if(a[i] == 0){
				zero++;
			}
			minAbs = Math.min(Math.abs(a[i]), minAbs);

			absSum += Math.abs(a[i]);
		}

		if(minus % 2 == 0 || zero > 0){
			System.out.println(absSum);
		}
		else {
			System.out.println(absSum - minAbs*2);
		}

//		if(n == 2){
//			System.out.println(Math.max(a[0] + a[1], -a[0] - a[1]));
//		}
//		int dp[][] = new int[2][n - 1];
//		dp[0][0] = a[0] + a[1];
//		dp[1][0] = -a[0] - a[1];
//
//		for(int i = 1; i < n - 1; i++){
//			dp[0][i] = Math.max(dp[0][i - 1] + a[i + 1], dp[1][i - 1] + a[i]*2 + a[i + 1]);
//			dp[1][i] = Math.max(dp[0][i - 1] - a[i]*2 - a[i + 1], dp[1][i - 1] - a[i + 1]);
//		}

//		int dp[] = new int[n];
//
//		dp[0] = Math.max(a[0], -a[0]);
//		dp[1] = Math.max(a[0] + a[1], -a[0] - a[1]);
//
//		for(int i = 2; i < n; i++){
//			dp[i] = dp[i - 2] + Math.max(a[i], -a[i]);
//		}
//		for(int j = 0; j < 2; j++){
//			for(int i = 0; i < n - 1; i++){
////				System.out.print(dp[j][i]+ " ");
//			}
//			System.out.println();
//		}
//
//		System.out.println(dp[n - 1]);
	}

}
