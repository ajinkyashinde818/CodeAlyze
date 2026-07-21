import java.util.Scanner;


public class Main 
{
	final static String FES = "FESTIVAL";
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		String fes_name="";
		sc.close();
		for(int i=0,fes_len = Main.FES.length() ;i<S.length()-fes_len;i++)
		{
			fes_name += S.charAt(i);
		}

		System.out.println(fes_name);
		
	}

}
