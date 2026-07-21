import java.util.Scanner;

public class Main {

	public static void main (String[] args)  {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		System.out.println(Math.max((10-n)*100, 0)+r);
		
 
	}

	
	

}
