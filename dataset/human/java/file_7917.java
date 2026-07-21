import java.util.Scanner;
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = 0;
		int g = 0;
		for(int i = 0;i<=9;i++){
			n =sc.nextInt();
			g = g + n;
		}
		System.out.println(g);

	}

}
