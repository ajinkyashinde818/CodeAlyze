import java.util.*;
	import java.lang.Math;
    public class Main
	{
		
		public static void main(String args[])
		{
			Scanner scan = new Scanner(System.in);
			int n = scan.nextInt();
			int k = scan.nextInt();
			int m = 100*(10-n);
			if(n<10)
				System.out.println(k+m);
			else
				System.out.println(k);
			
		}
    }
