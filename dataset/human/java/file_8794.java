import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int count = 0;
		int wari = Math.min(a, b);
		while (count < k) {
			if (a % wari == 0 && b % wari == 0) {
				count++;
			}
			wari--;
		}
		System.out.println(wari + 1);
 	}
}
