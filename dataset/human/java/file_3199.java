import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		// Scanner scan = new Scanner(System.in);
		String[] ana = new String[2];
		ana = line.split("");
		
		if(ana[0].equals("9"))
			System.out.println("Yes");
		else if(ana[1].equals("9"))
			System.out.println("Yes");
		else
			System.out.println("No");

}
}
