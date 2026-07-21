import java.util.Scanner;
import java.io.IOException;

class Main 
{
	/* m ... 1000
	 * c ... 100
	 * x ... 10 
	 * i ... 1
	 * figure = m | c | x | i
	 * num = 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
	 */

	public static void main(String[] args) throws IOException
	{
		Scanner sc = new Scanner(System.in);
		String s1, s2;
		int n = sc.nextInt();

		for(int i = 0; i < n; i++)
		{
			s1 = sc.next();
			s2 = sc.next();

			System.out.println(addMCXI(s1, s2));
		}
	}

	public static String addMCXI(String s1, String s2)
	{
		int num = mcxi2int(s1) + mcxi2int(s2);
		return int2mcxi(num);
	}

	private static int mcxi2int(String str)
	{
		int num = 0, tmp;
		int[] a = new int[4];
		int[] base = {1000, 100, 10, 1};
		int[] index = new int[4];
		char[] mcxi = {'m', 'c', 'x', 'i'};

		for(int i = 0; i < 4; i++)
		{
			index[i] = str.indexOf(mcxi[i]);
		}

		for(int i = 0; i < 4; i++)
		{
			if(index[i] == -1)
			{
				a[i] = 0;
			}
			else if(index[i] == 0) 
			{
				a[i] = 1;	
			}
			else
			{
				tmp = str.charAt(index[i] - 1) - '0';
				if(2 <= tmp && tmp <= 9)
				{
					a[i] = tmp;
				}
				else
				{
					a[i] = 1;
				}
			}
		}

		for(int i = 0; i < 4; i++)
		{
			num += a[i] * base[i];
		}
		
		return num;
	}

	private static String int2mcxi(int num)
	{
		String str = "";
		int[] a = new int[4];
		int[] base = {1000, 100, 10, 1};
		String[] mcxi = {"m", "c", "x", "i"};

		for(int i = 0; i < 4; i++)
		{
			a[i] = num / base[i] % 10;
		}

		for(int i = 0; i < 4; i++)
		{
			switch(a[i])
			{
				case 0:
					break;
				case 1:
					str += mcxi[i];
					break;
				default:
					str += Integer.toString(a[i]) + mcxi[i];
					break;
			}
		}

		return str;
	}
}
