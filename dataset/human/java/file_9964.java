import java.util.Arrays;
import java.util.Scanner;

public class Main 
{
	static long[] mask = new long[12];
	static int n, m; //n books
	static long x; //target mastery
	static long[] price;
	static long[][] mast;
	static long best = -1;
	static void go(long c)
	{
		boolean[] book = new boolean[n];
		long[] skill = new long[m];
		long pay = 0;
		for(int i = 0; i < n; i++)
		{
			book[i] = (c & mask[i]) > 0;
			
			if(book[i])
			{
				for(int j = 0; j < m; j++)
				{
					skill[j] += mast[i][j];
				}
				pay += price[i];
			}
		}
		
		int count = 0;
		for(int i = 0; i < m; i++)
		{
			if(skill[i] >= x)
			{
				count++;
			}
		}
		
//		System.out.println(count + " " + x + Arrays.toString(skill) + " " + pay + " " + m);
		if(count == m)
		{
			if(best < 0 || best > pay)best=pay;
		}
	}

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		
		n = sc.nextInt();
		m = sc.nextInt();
		x = sc.nextLong();
		price = new long[n];
		mast = new long[n][m];
		
		for(int i = 0; i < n; i++)
		{
			price[i] = sc.nextLong();
			//each algo
			for(int j = 0; j < m; j++)
				mast[i][j] = sc.nextLong();
		}
		
		long curm = 1;
		for(int i = 0; i < n; i++)
		{
			mask[i] = curm;
			curm*= 2;
		}
		
		for(long c = 0; c <= curm-1; c++)
		{
			go(c);
//			System.out.println(Long.toString(c,2));
		}
		System.out.println(best);
	}

}
