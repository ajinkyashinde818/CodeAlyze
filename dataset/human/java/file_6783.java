import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();

		int[] a = new int[n];

		int i = 0;
		while(i < n) {
			a[i] = sc.nextInt();
			i++;
		}

		int distance = a[n-1]-a[0];
		for(i = 1; i < n;i++) {
			distance = Math.min(distance, k - (a[i] -a[i-1]));
		}

		System.out.println(distance);
	}

}
