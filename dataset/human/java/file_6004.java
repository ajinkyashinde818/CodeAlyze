import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] c = sc.next().toCharArray();
		
		Arrays.sort(c);
		if (c[0] != 'a') System.out.println("No");
		else if (c[1] != 'b') System.out.println("No");
		else if (c[2] != 'c') System.out.println("No");
		else System.out.println("Yes");
	}
}
