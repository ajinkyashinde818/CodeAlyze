import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//String line = br.readLine();
		Scanner scan = new Scanner(System.in);

		String a = scan.next();
		String b = scan.next();

		if(a.compareTo(b)>0)
			System.out.println(">");
		else if(a.compareTo(b)==0)
			System.out.println("=");
		else
			System.out.println("<");


	}
}
