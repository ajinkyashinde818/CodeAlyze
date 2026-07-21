import java.io.FileInputStream;
import java.io.InputStream;
import java.util.Scanner;

public class Main{
	static Scanner sc;

	public static void main(String[] args) throws Exception {
		//InputStream in = new FileInputStream("src/input.txt");
		InputStream in = System.in;
		//PrintStream out = new PrintStream("src/output.txt");

		//System.setOut(out);

		sc = new Scanner(in);

		String S = sc.next();

		for(int i = 0; i < S.length() - 8; i++){
			System.out.print(S.charAt(i));
		}
		System.out.println();

		//out.close();
	}
}
