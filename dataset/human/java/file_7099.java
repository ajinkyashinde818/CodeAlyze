import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		int[] a = new int[200001];
		int[] d = new int[200001];
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		for (int i = 0; i < n;i++) {
			a[i] = sc.nextInt();
		}
		int max = 0;
		for (int i = 1; i < n;i++) {
			d[i] = a[i]-a[i-1];
			if (max < d[i]) {
				max = d[i];
			}
		}
		int d0= a[0]+k-a[n-1];
		if (max < d0) {
			max = d0;
		}
		sc.close();
		System.out.println(k-max);
	}
}
