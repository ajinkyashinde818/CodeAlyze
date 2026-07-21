import java.util.Scanner;

public class Main {

private static final int BIT = 32;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int word = stdin.nextInt();
		int wordBit = word * BIT;
		System.out.println(wordBit);

	}

}
