import java.util.Scanner;

public class Main {
	public static void main(String[] ar)
	{
		Scanner sc = new Scanner(System.in);

		int cnt = 0;
		int k = sc.nextInt(), def = sc.nextInt();
		int x = 0, y = 0, z = def;

		// y -> x
		while (true)
		{
			z = def - x;
			y = 0;

			// z -> y
			while (true)
			{
				if (x <= k && y <= k && z <= k) { ++cnt; }

				if (z == 0) { break;}

				--z; ++y;
			}

			++x;

			if (x > def) { break; }
		}

		System.out.println(cnt);
	}
}
