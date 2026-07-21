import java.util.Scanner;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < n; i++)
		{
			String str[] = sc.nextLine().split(" ");
			int sum = toInt(str[0]) + toInt(str[1]);
			System.out.println(toMCXI(sum));
		}
	}
	private static int toInt(String str)
	{
		int res = 0;
		int n = 1;
		for (int i = 0; i < str.length(); i++)
		{
			char c = str.charAt(i);
			switch(c)
			{
				case 'm':
					res += n * 1000;
					n = 1;
					break;
				case 'c':
					res += n * 100;
					n = 1;
					break;
				case 'x':
					res += n * 10;
					n = 1;
					break;
				case 'i':
					res += n;
					n = 1;
					break;
				default:
					n = c - '0';
					break;
			}
		}
		return res;
	}
	private static String toMCXI(int n)
	{
		StringBuffer res = new StringBuffer();
		char order[] = {'i', 'x', 'c', 'm'};
		for (int i = 0; i < 4; i++)
		{
			int a = n % 10;
			if (a != 0)
			{
				res.insert(0, order[i]);
				if (a != 1)
				{
					res.insert(0, a);
				}
			}
			n /= 10;
		}
		return res.toString();
	}
}
