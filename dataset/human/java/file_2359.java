import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner in = new Scanner(System.in)) {
			String s = in.nextLine().trim();

			System.out.println(s.substring(0, s.lastIndexOf("FESTIVAL")));
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		}
	}
}
