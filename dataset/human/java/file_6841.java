import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);

		int k = scan.nextInt();
		int n = scan.nextInt();
		Integer[] a = new Integer[n];
		Integer[] b = new Integer[n];
		int result = 0;

		for(int i=0;i<n;i++) {
			a[i] = scan.nextInt();
		}

		b[0] = k-a[n-1]+a[0];

		for(int i=1;i<n;i++) {
			b[i] = a[i]-a[i-1];
		}

		Arrays.parallelSort(b);
		for(int i=0;i<n-1;i++) {
			result+=b[i];
		}

		System.out.println(result);


	}

}
