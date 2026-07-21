import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		sc.close();

		int ans = 0;
		int kailen = 0;
		int[] kai = new int[100];
		int i;
		for (i=1; i<=100; i++) {
			if (a % i == 0 && b % i == 0) {
				kai[kailen]= i;
				ans++;
				kailen++;
			}
		}
		System.out.println(kai[kailen-k]);
	}
}
