import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String [] Args)
	{
		Scanner in=new Scanner(System.in);
		long n=in.nextLong();
		if(n%2==1)
			System.out.println(0);
		else
		{
			long ans=0;
			long q=5;
			n=n/2;
			while(n>=q)
			{
				ans=ans+n/q;
				q=q*5;
			}
			System.out.println(ans);
		}		
	}
}
