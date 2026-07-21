import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		int n = 0;
		int r = 0;
		int anser =0;

		Scanner scan = new Scanner(System.in);

		n = scan.nextInt();
		r = scan.nextInt();

		if(n>=10) {
			anser = r;
		}else {
			anser = r + 100 * (10-n);
		}

		System.out.println(anser);
	}

}
