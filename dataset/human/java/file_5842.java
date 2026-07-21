import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner stdIn = new Scanner(System.in);
		
		String s = stdIn.next();
		
		boolean flagA = false;
		boolean flagB = false;
		boolean flagC = false;
		
		for(int i = 0; i < 3; i++)
		{
		
			if(s.charAt(i) == 'a')
			{
				flagA = true;
			}
			else if(s.charAt(i) == 'b')
			{
				flagB = true;
			}
			else if(s.charAt(i) == 'c')
			{
				flagC = true;
			}
		}
		
		if(flagA && flagB && flagC)
		{
			System.out.println("Yes");
		}
		else
		{
			System.out.println("No");
		}

	}

}
