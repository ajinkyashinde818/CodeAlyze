import java.util.Scanner;

// https://atcoder.jp/contests/abc160/tasks/abc1160_c
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] array = new int[n];
		for(int i=0;i<n;i++) {
			array[i] = sc.nextInt();
		}
		sc.close();

		int ans = Math.min(k, k - array[0]);
		//時計回り
		for(int i=1;i<array.length;i++) {
			ans = Math.min(ans, k-array[i]+array[i-1]);
		}

		ans = Math.min(ans, array[n-1] - array[0]);
		//反時計回り
		for(int i=0;i<array.length-1;i++) {
			ans = Math.min(ans, array[i]+k-array[i+1]);
		}

		System.out.println(ans);

	}
}
