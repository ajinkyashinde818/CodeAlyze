import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int n = Integer.parseInt(sc.next());

		long[] value = new long[n];

		for (int i = 0; i < n; i++) {
			value[i] = Long.parseLong(sc.next());
		}

		boolean minuscount = false;
		long max = 0;

		for (int i = 0; i < n; i++) {
			if (value[i] < 0) minuscount = !minuscount;
		}

		for (int i = 0; i < n; i++) {
			max += Math.abs(value[i]);
		}

		if (minuscount) {
			long min = Math.abs(value[0]);

			for (int i = 0; i < n; i++) {
				if (min > Math.abs(value[i])) {
					min = Math.abs(value[i]);
				}
			}

			max -= min * 2L;
		}

		System.out.println(max);


		sc.close();
	}

}
