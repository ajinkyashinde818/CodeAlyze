import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();

		int n = 0;
		for(int i=100;i>=1;i--) {
			if(a%i == 0 && b%i == 0) {
				n++;
				if(n == k) {
					out.println(i);
				}
			}
		}

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}
