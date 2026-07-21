import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String line = in.nextLine();
		in.close();
		if (line.contains("a") && line.contains("b") && line.contains("c")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}

}
