import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
	
	public static void main(String[] args)
	{
		new Main().run();
	}
	
	public void run()
	{
		Scanner file = new Scanner(System.in);
		int N = file.nextInt();
		long[] ints = new long[N];
		for(int i = 0;i<N;i++)
			ints[i] = file.nextLong();
		long[][] dp = new long[ints.length][2];
		dp[ints.length-1][0] = -ints[ints.length-1];
		dp[ints.length-1][1] = ints[ints.length -1];
		for(int i = ints.length-2;i>=0;i--)
		{
			for(int j = 0;j<2;j++)
			{
				if(j == 0)
				{
					dp[i][j] = Math.max(-ints[i]+dp[i+1][1],ints[i]+dp[i+1][0]);
				}else {
					dp[i][j] = Math.max(ints[i]+dp[i+1][1],-ints[i]+dp[i+1][0]);
				}
			}
		}
		System.out.println(dp[0][1]);
	}
	
	int gcd(int a, int b)
	{
		return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
	}
	
}
