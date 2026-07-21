import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		String[] substr = str.split(" ", 0);

		int n = Integer.parseInt(substr[0]);
		int r = Integer.parseInt(substr[1]);
		int ans = r;

		if (n <10) {
			ans += 100*(10-n);
		}

		scan.close();
		System.out.println(ans);
	}
}
