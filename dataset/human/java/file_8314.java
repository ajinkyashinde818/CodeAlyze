import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String [] Args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		long ans=a;
		ans=ans*b;
		ans=ans/gcd(a,b);
		System.out.println(ans);
	}
	
	static int gcd(int a,int b)
	{
		if(a%b==0)
			return b;
		return gcd(b,a%b);
	}
}
