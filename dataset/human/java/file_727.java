import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner kb = new Scanner(System.in);
		int i = kb.nextInt();
		int j = kb.nextInt();
		if (i < 10) {
			System.out.println(j + 100 * (10 - i));
		} else {
			System.out.println(j);
		}
		kb.close();
	}

}
