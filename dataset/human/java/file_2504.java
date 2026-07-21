import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (; N-->0; )
		{
			String x = sc.next(), y = sc.next();
			System.out.println(toString(toInt(x) + toInt(y)));
		}
	}
	
	private static int dd(char c)
	{
		switch (c)
		{
		case 'm': return 1000;
		case 'c': return 100;
		case 'x': return 10;
		case 'i': return 1;
		}
		return 0;
	}
	
	private static int toInt(String s)
	{
		int ret = 0;
		for (int i = 0; i < s.length(); )
		{
			char c = s.charAt(i++);
			int n = 1;
			if (Character.isDigit(c))
			{
				n = c - '0';
				c = s.charAt(i++);
			}
			ret += n * dd(c);
		}
		return ret;
	}
	
	private static String toString(int n)
	{
		int x;
		String ret = "";
		
		x = n % 10;
		ret = (x == 0 ? "" : (x == 1 ? "i" : x + "i")) + ret;
		n /= 10;
		
		x = n % 10;
		ret = (x == 0 ? "" : (x == 1 ? "x" : x + "x")) + ret;
		n /= 10;
		
		x = n % 10;
		ret = (x == 0 ? "" : (x == 1 ? "c" : x + "c")) + ret;
		n /= 10;
		
		x = n % 10;
		ret = (x == 0 ? "" : (x == 1 ? "m" : x + "m")) + ret;
		n /= 10;
		
		return ret;
	}
}
/*
10
xi x9i
i 9i
c2x2i 4c8x8i
m2ci 4m7c9x8i
9c9x9i i
i 9m9c9x8i
m i
i m
m9i i
9m8c7xi c2x8i
*/
