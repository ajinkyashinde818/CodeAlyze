import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	//C問題

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner scan = new Scanner(System.in);

		int n, r;

		n = scan.nextInt();
		r = scan.nextInt();

		if (n >= 10) {
			System.out.println(r);
		} else {
			System.out.println(r + 100 * (10 - n));
		}

	}

}
