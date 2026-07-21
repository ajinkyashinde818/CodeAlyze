import java.util.Scanner;
public class Main 
{
	public static void main(String[] args) 
    {
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		if(n%2==1)
        {
		    System.out.println(0);
		}
		else
        {
		    long total = 0;
		    long x = n/2;
		    while(x>0)
            {
		        x = x/5; 
		        total += x;
		    }
		    System.out.println(total);
		}
	}
}// :)
