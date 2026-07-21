import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int amountToRoll = Integer.parseInt(scan.nextLine());
		
		int streak = 0;
		
		for (int i = 0; i < amountToRoll; i++)
		{
			String[] array = scan.nextLine().split("\\s");
			
			if(array[0].equals(array[1])) 
			{
				streak++;
			}
			
			else 
			{
				streak = 0;
			}
			
			if(streak == 3) 
			{
				System.out.println("Yes");
				break;
			}
			
		}
		
		
		
		if(streak != 3) 
		{
			System.out.println("No");
		}
		
		scan.close();

	}

}
