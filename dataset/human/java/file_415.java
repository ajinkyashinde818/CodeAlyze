import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int d = sc.nextInt();
		int ta = sc.nextInt();
		int tb = sc.nextInt();
		double da = sc.nextInt();
		double db = sc.nextInt();
		double min = Double.MAX_VALUE;
		for (int i = 0; i * da <= d; i++) {
		    for (int j = 0; i * da + j * db <= d; j++) {
		        if (i == 0 && j == 0) {
		            continue;
		        }
		        min = Math.min(min, Math.abs((ta * i * da + tb * j * db) / (i * da + j * db) - t));
		    }
		}
		System.out.println(min);
	}
}
