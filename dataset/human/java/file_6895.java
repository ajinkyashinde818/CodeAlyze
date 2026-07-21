import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K,N;
		K = sc.nextInt();
		N = sc.nextInt();
		int a[] = new int[N];
		for (int i = 0;i<N;i++) {
			a[i] = sc.nextInt();
		}
		int sa=0;
		for (int i=1;i<N;i++) {
			if (a[i]-a[i-1]>sa) {
				sa= a[i]-a[i-1];
			}
		}
		if (a[N-1]-a[0]<K-sa) {
			System.out.println(a[N-1]-a[0]);
		} else {
			System.out.println(K-sa);
		}
	}
}
