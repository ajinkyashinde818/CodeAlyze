import java.util.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int count[] = new int[101];

		for (int i = 0;i < N;++i) {
			int A = sc.nextInt();
			count[A]++;
		}

		for (int a = 100;a >= 1;--a) {
			count[a - 1] += count[a];
		}

		int max = 0;
		for (int a = 0;a <= 100;++a) {
			if (count[a] >= a) {
				max = a;
			}
		}

		System.out.println(max);
	}
}
