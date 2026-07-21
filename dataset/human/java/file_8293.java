import java.util.*;
public class Main
{
	public static long gcd(long a,long b)
	{
		if(b==0)
		{
			return a;
		}
		return gcd(b,a%b);
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long a=in.nextLong();
		long b=in.nextLong();
		gcd(a,b);
		System.out.println((a*b)/gcd(a,b));
	}
}
