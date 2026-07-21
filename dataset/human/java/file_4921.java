import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		if (n % 2 == 1) {
		    System.out.println(0);
		} else {
		    long count = 0;
		    while (n > 0) {
		        count += n / 5 / 2;
		        n /= 5;
		    }
		    System.out.println(count);
		}
	}
}
