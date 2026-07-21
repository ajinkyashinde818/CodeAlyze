import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int N = scan.nextInt();
		int R = scan.nextInt();

		int re = 0;

		if(N >= 10) {
			re = R;
		}else {
			re = R + 100*(10-N);
		}
		System.out.println(re);
		scan.close();

	}

}
