import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		if (n <= 9) {
			System.out.println(r + 100 * (10 - n));
		} else {
			System.out.println(r);
		}
		
	}
}
