import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long A = in.nextLong();
		long B = in.nextLong();
		long C = in.nextLong();

		if (A + B >= C) {
			System.out.println(B + C);
		} else {
			System.out.println(Math.min(A + B, C) + 1 + B);
		}
		in.close();
	}

}
