import java.util.*;

public class Main 
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		String n = scan.next();
		
		if (n.contains("9"))
		{
			System.out.println("Yes");
		}
		else
		{
			System.out.println("No");
		}
		
		
		scan.close();
	}
}
