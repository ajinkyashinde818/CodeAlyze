import java.util.Scanner;

public class Main 
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		long a = sc.nextLong();
		long b = sc.nextLong();
		
		sc.close();
		
		long snack = lcm(a, b);
		System.out.println(snack);

	}
	
	static long gcd(long a, long b) 
    { 
		if (a == 0)
		{
			return b;
		}
			  
		return gcd(b % a, a);  
    } 
	
	static long lcm(long a, long b) 
    { 
        return (a*b)/gcd(a, b); 
    } 
}
