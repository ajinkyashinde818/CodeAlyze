import java.util.*;
import java.util.concurrent.ThreadLocalRandom; 
import java.io.*;

public class Main
{
	public static void main(String [] Args)
	{
		Scanner in = new Scanner(System.in);
		long n=in.nextLong();
		long ans=0;
		int [] prime = new int[1000001];
		for(int i=2;i<1000001;i++)
		{
			if(prime[i]==0)
			{
				for(int j=2;i*j<1000001;j++)
				{
					prime[i*j]=1;
				}
			}
		}
		long t=n;
		for(long i=2;i*i<n;i++)
		{
			if(prime[(int)i]==0&&n%i==0)
			{
				int q=0;				
				while(t%i==0)
				{
					t=t/i;
					q++;
				}
				int j=0;
				while(j*(j+1)/2<=q)
				{
					j++;
				}
				ans=ans+j-1;
			}
		}
		if(t!=1)
		{
			ans++;
		}
		System.out.println(ans);
	}
}
